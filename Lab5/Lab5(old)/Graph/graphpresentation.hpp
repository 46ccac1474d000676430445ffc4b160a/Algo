#ifndef GRAPHPRESENTATION_HPP
#define GRAPHPRESENTATION_HPP

#include <QGraphicsScene>
#include <QGraphicsEllipseItem>

#include <qmath.h>

#include "graph.hpp"

class GraphPresentation : public QGraphicsScene
{
    Q_OBJECT

    Q_PROPERTY(Graph<QString, QGraphicsEllipseItem*> graph READ graph WRITE setGraph NOTIFY graphChanged)

    Graph<QString, QGraphicsEllipseItem*> m_graph;

private slots:
    void on_graphChanged();

public:
    GraphPresentation(QObject *parent = nullptr);
    GraphPresentation(const QRectF &rect, QObject *parent = nullptr);

    Graph<QString, QGraphicsEllipseItem*> graph() const
    { return m_graph; }

public slots:
    void setGraph(Graph<QString, QGraphicsEllipseItem*> graph)
    {
        if (m_graph == graph) return;
        m_graph = graph;
        emit graphChanged(m_graph);
    }

signals:
    void graphChanged(Graph<QString, QGraphicsEllipseItem*> graph);
};

#endif // GRAPHPRESENTATION_HPP
