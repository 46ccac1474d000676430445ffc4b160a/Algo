#include "graphpresentation.hpp"

GraphPresentation::GraphPresentation(QObject *parent) :
    QGraphicsScene(parent)
{
    connect(this, &GraphPresentation::graphChanged, this, &GraphPresentation::on_graphChanged);
    connect(this, &GraphPresentation::sceneRectChanged, this, &GraphPresentation::on_graphChanged);
}

GraphPresentation::GraphPresentation(const QRectF &rect, QObject *parent) :
    QGraphicsScene(parent)
{
    setSceneRect(rect);
    connect(this, &GraphPresentation::graphChanged, this, &GraphPresentation::on_graphChanged);
}

void GraphPresentation::on_graphChanged()
{
    clear();

    QList<QString> v_list = m_graph.vertices();

    int n = v_list.size();

    int w = sceneRect().width();
    int h = sceneRect().height();

    qreal vr = 20.;
    qreal r = w < h ? w/2.-vr : h/2.-vr;

    for (int i = 0; i < n; i++)
    {
        auto &vertex = m_graph.vertexRef(v_list[i]);
        if (vertex.value() == nullptr)
        {
            qreal x = r * cos( 2.*M_PI*i/n - M_PI/2. ) + w/2.;
            qreal y = r * sin( 2.*M_PI*i/n - M_PI/2. ) + h/2.;

            QRectF rect(x-vr/2., y-vr/2., vr, vr);

            QGraphicsEllipseItem *ellipse = addEllipse(rect, QPen(), QBrush("lightgreen"));
            ellipse->setToolTip(vertex.name());
            ellipse->setZValue(1.);

            vertex.setValue(ellipse);
        }
    }

    foreach (const QString &v1, v_list)
    {
        QLinkedList<QString> edges = m_graph.vertex(v1).edges();
        foreach (const QString &v2, edges)
        {
            if (v1 == v2)
            {

            }
            else
            {
                addLine(QLineF(m_graph.vertexRef(v1).value()->rect().center(), m_graph.vertexRef(v2).value()->rect().center()), QPen(QColor("red")) );
            }
        }
    }

}

/*
    int n = graph.vertexCount();

    if (radioState == 0)
    {
        qreal r = width() < height() ? width()/2.-30. : height()/2.-30.;

        for (int i = 0; i < n; i++)
        {
            foreach (int val, graph.edges(i))
            {
                qreal x1 = r * cos( 2.*M_PI*i/n - M_PI/2. ) + width()/2.;
                qreal y1 = r * sin( 2.*M_PI*i/n - M_PI/2. ) + height()/2.;
                qreal x2 = r * cos( 2.*M_PI*val/n - M_PI/2. ) + width()/2.;
                qreal y2 = r * sin( 2.*M_PI*val/n - M_PI/2. ) + height()/2.;

                if (i == val)
                {
                    p.drawEllipse( QPointF(x1 > width()/2. ? x1+20. : x1-20.,
                                           y1 > height()/2. ? y1+20. : y1-20.),
                                   20., 20.);
                }
                else
                {
                    p.drawLine(x1, y1, x2, y2);
                }
            }
        }

        p.setBrush(QBrush("lightgreen"));

        for (int i = 0; i < n; i++)
        {
            qreal x = r * cos( 2.*M_PI*i/n - M_PI/2. ) + width()/2.;
            qreal y = r * sin( 2.*M_PI*i/n - M_PI/2. ) + height()/2.;
            p.drawEllipse(QPointF(x, y), 20., 20.);
            p.drawText(QPointF(x-5.5, y+6.), QString::number(i));
        }
    }
*/
