#ifndef GRAPH_HPP
#define GRAPH_HPP

#include <QGraphicsLineItem>
#include <QGraphicsEllipseItem>
#include <QGraphicsScene>

#include <QLinkedList>
#include <QHash>

#include <QQueue>
#include <QStack>

#include <QTimer>

#include <qmath.h>

#include <QGraphicsSceneMouseEvent>
#include <QGraphicsSceneHoverEvent>
#include <QCursor>
#include <QPainter>
#include <QFontMetrics>


#include <QDebug>

class Edge;
class Vertex;


class Edge : public QGraphicsLineItem
{
    Vertex *m_v1;
    Vertex *m_v2;

public:
    Edge(Vertex *v1, Vertex *v2);

    void setP1(const QPointF &p);
    void setP2(const QPointF &p);

    Vertex *v1() const;
    Vertex *v2() const;

    bool equals(Edge *edge);

    friend class Vertex;
    friend class Graph;
};



class Vertex : public QGraphicsEllipseItem
{
    QString m_name;
    QLinkedList<Edge *> m_edges;

protected:
    virtual void mouseMoveEvent(QGraphicsSceneMouseEvent *e);
    virtual void mousePressEvent(QGraphicsSceneMouseEvent *e);
    virtual void mouseReleaseEvent(QGraphicsSceneMouseEvent *e);
    virtual void hoverEnterEvent(QGraphicsSceneHoverEvent *e);
    virtual void hoverLeaveEvent(QGraphicsSceneHoverEvent *e);
    virtual void hoverMoveEvent(QGraphicsSceneHoverEvent *e);
    virtual void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

public:
    Vertex(const QString &name);
    virtual ~Vertex();

    QString name() const;

    void addEdgeTo(Vertex *v);

    Edge *edgeTo(Vertex *v) const;
    Edge *edgeTo(const QString &v) const;

    QLinkedList<Edge *> edges() const;

    QVector<Vertex *> adjacently() const;
    QStringList adjacentlyNames() const;

    void setPosDepend(const QPointF &pos);
};





class Graph : public QGraphicsScene
{
    Q_OBJECT

    QHash<QString, Vertex *> m_vertices;

public:
    Graph();
    virtual ~Graph();

    bool edgeExists(Vertex *v1, Vertex *v2) const;
    bool edgeExists(const QString &v1, const QString &v2) const;

    bool vertexExists(const QString &v) const;

    Vertex *vertex(const QString &v) const;

    QVector<Vertex *> vertices() const;
    QStringList vertexNames() const;

    Edge *edge(Vertex *v1, Vertex *v2) const;
    Edge *edge(const QString &v1, const QString &v2) const;

    bool isEmpty() const;

    void setVerticesColor(const QPen &pen = QPen(), const QBrush &brush = QBrush("lightgreen"));
    void setEdgesColor(const QPen &pen = QPen(QColor("black"), 2.));

public slots:
    void addVertex(Vertex *v);
    void addVertex(const QString &v);

    void addEdge(Vertex *v1, Vertex *v2);
    void addEdge(const QString &v1, const QString &v2);

    void placeRounded();

    void clearVertices();
};

#endif // GRAPH_HPP
