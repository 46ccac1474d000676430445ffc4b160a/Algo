#include "graphicsscene.hpp"

QGraphicsScene *GraphicsView::scene() const
{
    return m_scene;
}

void GraphicsView::addKoch(const QPointF &a, const QPointF &e, int n)
{
    QApplication::setOverrideCursor(Qt::WaitCursor);
    static int counter = 0;
    privateAddKoch(a, e, n, counter);
    QApplication::restoreOverrideCursor();
    emit linesCounted(counter);
    counter = 0;
}

void GraphicsView::setPenWidth(qreal width)
{
    QConicalGradient gradient(m_scene->width()/2., m_scene->height()/2., 0.);

    gradient.setColorAt(0., QColor("#fe0000"));
    gradient.setColorAt(0.1666, QColor("#fef900"));
    gradient.setColorAt(0.3333, QColor("#00fe00"));
    gradient.setColorAt(0.5, QColor("#00fef9"));
    gradient.setColorAt(0.6666, QColor("#0000fe"));
    gradient.setColorAt(0.8333, QColor("#fc00fe"));
    gradient.setColorAt(1., QColor("#fe0000"));

    m_pen = QPen( QBrush(gradient), width, Qt::SolidLine, Qt::RoundCap);
}

void GraphicsView::saveToSVG()
{
    QString fileName = QFileDialog::getSaveFileName(this, "Save SVG", QDir::homePath()+"/koch.svg", "*.svg");

    if (!fileName.isEmpty())
    {
        QApplication::setOverrideCursor(Qt::WaitCursor);

        QSvgGenerator gen;
        gen.setFileName(fileName);
        gen.setSize(QSize(m_scene->width(), m_scene->height()));
        gen.setViewBox(m_scene->sceneRect());

        QPainter painter;
        painter.begin(&gen);

        painter.fillRect(gen.viewBox(), QBrush(QColor(42, 42, 42)));
        m_scene->render(&painter);

        painter.end();

        QApplication::restoreOverrideCursor();
    }
}

void GraphicsView::mousePressEvent(QMouseEvent *event)
{
    if (dotTracking() && event->button() == Qt::LeftButton) emit dotTracked(event->pos());

    QGraphicsView::mousePressEvent(event);
}

void GraphicsView::resizeEvent(QResizeEvent *event)
{
    m_scene->setSceneRect(1, 1, width()-2, height()-2);

    emit widgetSizeChanged(QSize(width(), height()));

    QGraphicsView::resizeEvent(event);
}

void GraphicsView::privateAddKoch(const QPointF &a, const QPointF &e, int n, int &counter)
{
    if (n)
    {
        qreal lineX = e.x() - a.x();
        qreal lineY = e.y() - a.y();

        QPointF b(a.x() + lineX / 3.,
                  a.y() + lineY / 3.);

        const qreal cos60 = 0.5;
        const qreal sin60 = n > 0 ? -0.866666 : 0.866666;  // знак меняет направление выпуклой стороны

        QPointF c(b.x() + (lineX/3.)*cos60 - (lineY/3.)*sin60,
                  b.y() + (lineX/3.)*sin60 + (lineY/3.)*cos60);

        QPointF d(e.x() - lineX / 3.,
                  e.y() - lineY / 3.);

        privateAddKoch(a, b, n > 0 ? n - 1 : n + 1, counter);
        privateAddKoch(b, c, n > 0 ? n - 1 : n + 1, counter);
        privateAddKoch(c, d, n > 0 ? n - 1 : n + 1, counter);
        privateAddKoch(d, e, n > 0 ? n - 1 : n + 1, counter);
    }
    else
    {
        m_scene->addLine(QLineF(a, e), m_pen);
        counter++;
    }
}

GraphicsView::GraphicsView(QWidget *parent) :
    QGraphicsView(parent),
    m_scene(new QGraphicsScene(this))
{
    m_scene->setSceneRect(1, 1, width()-2, height()-2);
    setScene(m_scene);

    setRenderHint(QPainter::Antialiasing);

    setPenWidth(1.);

    connect(this, &GraphicsView::widgetSizeChanged, [=]() -> void {
        setPenWidth(m_pen.widthF());
    });
}
