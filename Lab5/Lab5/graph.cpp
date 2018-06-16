#include "graph.hpp"

Edge::Edge(Vertex *v1, Vertex *v2) :
    m_v1(v1),
    m_v2(v2)
{
    setPen(QPen(QBrush("black"), 2.));
    setLine(QLineF(v1->pos(), v2->pos()));
}

void Edge::setP1(const QPointF &p)
{ setLine( QLineF( p, line().p2() ) ); }

void Edge::setP2(const QPointF &p)
{ setLine( QLineF( line().p1(), p ) ); }

Vertex *Edge::v1() const
{ return m_v1; }

Vertex *Edge::v2() const
{ return m_v2; }

bool Edge::equals(Edge *edge)
{
    return v1()->name() == edge->v1()->name()
            &&
           v2()->name() == edge->v2()->name();
}






QString Vertex::name() const
{ return m_name; }

void Vertex::addEdgeTo(Vertex *v)
{
    Edge *edge = nullptr;
    if (edgeTo(v) == nullptr)
    {
        edge = new Edge(this, v);
        m_edges.append(edge);
    }
    if (v->edgeTo(this) == nullptr)
    {
        if (edge == nullptr) edge = new Edge(v, this);
        v->m_edges.append(edge);
    }
}

Edge *Vertex::edgeTo(Vertex *v) const
{
    foreach (auto edge, m_edges)
    {
        if (edge->v1()->name() == v->name() || edge->v2()->name() == v->name()) return edge;
    }
    return nullptr;
}

Edge *Vertex::edgeTo(const QString &v) const
{
    foreach (auto edge, m_edges)
    {
        if (edge->v1()->name() == v || edge->v2()->name() == v) return edge;
    }
    return nullptr;
}

Vertex::Vertex(const QString &name) :
    m_name(name)
{
    setAcceptHoverEvents(true);
    setBrush(QBrush("lightgreen"));
    setToolTip(name);
}

Vertex::~Vertex()
{
    foreach (auto edge, m_edges)
    {
        if (edge->v1() == this) edge->v2()->m_edges.removeOne(edge);
        if (edge->v2() == this) edge->v1()->m_edges.removeOne(edge);
        delete edge;
    }
}

QLinkedList<Edge *> Vertex::edges() const
{ return m_edges; }

QVector<Vertex *> Vertex::adjacently() const
{
    QVector<Vertex *> vec;
    foreach (auto edge, m_edges)
    {
        if (edge->v1()->name() == name()) vec.append(edge->v2());
        if (edge->v2()->name() == name()) vec.append(edge->v1());
    }
    return vec;
}

QStringList Vertex::adjacentlyNames() const
{
    QStringList names;
    foreach (auto edge, m_edges)
    {
        if (edge->v1()->name() == name()) names.append(edge->v2()->name());
        if (edge->v2()->name() == name()) names.append(edge->v1()->name());
    }
    return names;
}

void Vertex::setPosDepend(const QPointF &pos)
{
    setPos(pos);
    foreach (auto edge, m_edges)
    {
        if (edge->v1()->name() == name()) edge->setP1(pos);
        if (edge->v2()->name() == name()) edge->setP2(pos);
    }
}

void Vertex::mouseMoveEvent(QGraphicsSceneMouseEvent *e)
{
    if (e->buttons() & Qt::LeftButton)
    {
        setPosDepend(mapToScene(e->pos()));
    }
}

void Vertex::mousePressEvent(QGraphicsSceneMouseEvent *e)
{
    if (e->buttons() & Qt::LeftButton) setCursor(QCursor(Qt::ClosedHandCursor));
}

void Vertex::mouseReleaseEvent(QGraphicsSceneMouseEvent *e)
{
    setCursor(QCursor(Qt::ArrowCursor));
    e->ignore();
}

void Vertex::hoverEnterEvent(QGraphicsSceneHoverEvent *e)
{
    setCursor(QCursor(Qt::OpenHandCursor));
    e->ignore();
}

void Vertex::hoverLeaveEvent(QGraphicsSceneHoverEvent *e)
{
    setCursor(QCursor(Qt::ArrowCursor));
    e->ignore();
}

void Vertex::hoverMoveEvent(QGraphicsSceneHoverEvent *e)
{
    setCursor(QCursor(Qt::OpenHandCursor));
    e->ignore();
}

void Vertex::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QGraphicsEllipseItem::paint(painter, option, widget);

    int w = QFontMetrics(painter->font()).width(name());
    QPointF p = boundingRect().adjusted(rect().width()/2-w/2, rect().height()/2, 0, 0).topLeft();

    painter->drawText( p, name());
}





Graph::Graph()
{
}

Graph::~Graph()
{ clearVertices(); }

bool Graph::edgeExists(Vertex *v1, Vertex *v2) const
{
    return m_vertices.value(v1->name())->edgeTo(v2) != nullptr
            &&
           m_vertices.value(v2->name())->edgeTo(v1) != nullptr;
}

bool Graph::edgeExists(const QString &v1, const QString &v2) const
{ return m_vertices.value(v1)->edgeTo(v2) != nullptr; }

bool Graph::vertexExists(const QString &v) const
{ return m_vertices.contains(v); }

Vertex *Graph::vertex(const QString &v) const
{ return m_vertices.value(v); }

QVector<Vertex *> Graph::vertices() const
{
    QVector<Vertex *> vec = QVector<Vertex *>::fromList(m_vertices.values());
    std::sort(vec.begin(), vec.end(), [](Vertex *v1, Vertex *v2) -> bool {
                  return v1->name() < v2->name();
              });
    return vec;
}

QStringList Graph::vertexNames() const
{
    QStringList list = m_vertices.keys();
    std::sort(list.begin(), list.end());
    return list;
}

Edge *Graph::edge(Vertex *v1, Vertex *v2) const
{ return v1->edgeTo(v2); }

Edge *Graph::edge(const QString &v1, const QString &v2) const
{ return m_vertices.value(v1)->edgeTo(v2); }

bool Graph::isEmpty() const
{ return m_vertices.isEmpty(); }

void Graph::setVerticesColor(const QPen &pen, const QBrush &brush)
{
    foreach (auto vertex, m_vertices)
    {
        vertex->setPen(pen);
        vertex->setBrush(brush);
    }
}

void Graph::setEdgesColor(const QPen &pen)
{
    foreach (auto vertex, m_vertices)
    {
        QLinkedList<Edge *> edges = vertex->edges();
        foreach (auto edge, edges)
        {
            edge->setPen(pen);
        }
    }
}

void Graph::addVertex(Vertex *v)
{
    if (!m_vertices.contains(v->name()))
    {
        addItem(v);
        m_vertices.insert(v->name(), v);
    }
}

void Graph::addVertex(const QString &v)
{
    if (!m_vertices.contains(v))
    {
        auto vertex = new Vertex(v);
        addItem(vertex);
        m_vertices.insert(v, vertex);
    }
}

void Graph::addEdge(Vertex *v1, Vertex *v2)
{
    if (m_vertices.contains(v1->name()) && m_vertices.contains(v2->name()))
    {
        if (!edgeExists(v1, v2))
        {
            m_vertices.value(v1->name())->addEdgeTo(v2);
            m_vertices.value(v2->name())->addEdgeTo(v1);

            addItem(m_vertices.value(v1->name())->edgeTo(m_vertices.value(v2->name())));
        }
    }
}

void Graph::addEdge(const QString &v1, const QString &v2)
{
    if (m_vertices.contains(v1) && m_vertices.contains(v2))
    {
        if (!edgeExists(v1, v2))
        {
            m_vertices.value(v1)->addEdgeTo(m_vertices.value(v2));
            m_vertices.value(v2)->addEdgeTo(m_vertices.value(v1));

            addItem(m_vertices.value(v1)->edgeTo(m_vertices.value(v2)));
        }
    }
}

void Graph::placeRounded()
{
    qreal w = sceneRect().width();
    qreal h = sceneRect().height();

    qreal vr = 30.;
    qreal r = w < h ? w/2.-vr : h/2.-vr;

    auto vec = vertices();
    int n = vec.size();
    for (int i = 0; i < n; i++)
    {
        auto vertex = vec[i];
        qreal x = r * cos( 2.*M_PI*i/n - M_PI/2. ) + w/2.;
        qreal y = r * sin( 2.*M_PI*i/n - M_PI/2. ) + h/2.;

        QRectF rect(-(vr/2.), -(vr/2.), vr, vr);

        vertex->setRect(rect);
        vertex->setPosDepend(QPointF(x, y));

        vertex->setZValue(1.);
    }
}

void Graph::clearVertices()
{
    foreach (auto vertex, m_vertices)
    {
        delete vertex;
    }
    m_vertices.clear();
}
