#ifndef GRAPH_HPP
#define GRAPH_HPP

#include <QHash>
#include <QLinkedList>
#include <QList>

#include <QDebug>

template <class VertexName, class Value>
class Vertex
{
    VertexName m_name;
    Value m_value;
    QLinkedList<VertexName> m_edges;

public:
    Vertex(){}
    Vertex(const VertexName &name,
           const Value &value,
           const QLinkedList<VertexName> edges = QLinkedList<VertexName>());

    void setName(const VertexName &name);
    void setValue(const Value &value);
    void setEdges(const QLinkedList<VertexName> &edges);
    void addEdgeTo(const VertexName &name);

    void removeEdge(const VertexName &name);

    VertexName name() const;
    Value value() const;
    QLinkedList<VertexName> edges() const;

    bool operator ==(const Vertex<VertexName, Value> &vertex) const;
};

template<class VertexName, class Value>
Vertex<VertexName, Value>::Vertex(const VertexName &name,
                           const Value &value,
                           const QLinkedList<VertexName> edges) :
    m_name(name),
    m_value(value),
    m_edges(edges)
{}

template<class VertexName, class Value>
void Vertex<VertexName, Value>::setName(const VertexName &name)
{ m_name = name; }

template<class VertexName, class Value>
void Vertex<VertexName, Value>::setValue(const Value &value)
{ m_value = value; }

template<class VertexName, class Value>
void Vertex<VertexName, Value>::setEdges(const QLinkedList<VertexName> &edges)
{ m_edges = edges; }

template<class VertexName, class Value>
void Vertex<VertexName, Value>::addEdgeTo(const VertexName &name)
{ if (!m_edges.contains(name)) m_edges.append(name); }

template<class VertexName, class Value>
void Vertex<VertexName, Value>::removeEdge(const VertexName &name)
{ m_edges.removeOne(name); }

template<class VertexName, class Value>
VertexName Vertex<VertexName, Value>::name() const
{ return m_name; }

template<class VertexName, class Value>
Value Vertex<VertexName, Value>::value() const
{ return m_value; }

template<class VertexName, class Value>
QLinkedList<VertexName> Vertex<VertexName, Value>::edges() const
{ return m_edges; }

template<class VertexName, class Value>
bool Vertex<VertexName, Value>::operator ==(const Vertex<VertexName, Value> &vertex) const
{ return m_name == vertex.m_name && m_value == vertex.m_value && m_edges == vertex.m_edges; }





template<class VertexName, class Value>
class Graph
{
    QHash< VertexName, Vertex<VertexName, Value> > m_data;

public:
    Graph(){}
    void addVertex(const VertexName &name, const Value &value = Value());
    void addVertex(const Vertex<VertexName, Value> &vertex);
    void addEdge(const VertexName &v1, const VertexName &v2);

    void removeVertex(const VertexName &name);
    void removeEdge(const VertexName &v1, const VertexName &v2);

    Vertex<VertexName, Value> &vertexRef(const VertexName &name);

    Value value(const VertexName &name) const;
    Vertex<VertexName, Value> vertex(const VertexName &name) const;
    QList<VertexName> vertices();
    QLinkedList<VertexName> edges(const VertexName &name) const;

    bool operator ==(const Graph<VertexName, Value> &g);

    bool vertexExists(const VertexName &name) const;
    bool edgeExists(const VertexName &v1, const VertexName &v2) const;

    void clear();

};

template<class VertexName, class Value>
void Graph<VertexName, Value>::addVertex(const VertexName &name, const Value &value)
{
    if (m_data.contains(name)) m_data.remove(name);
    m_data.insert(name, Vertex<VertexName, Value>(name, value));
}

template<class VertexName, class Value>
void Graph<VertexName, Value>::addVertex(const Vertex<VertexName, Value> &vertex)
{
    if (m_data.contains(vertex.name())) m_data.remove(vertex.name());
    m_data.insert(vertex.name(), vertex);
}

template<class VertexName, class Value>
void Graph<VertexName, Value>::addEdge(const VertexName &v1, const VertexName &v2)
{
    if (!m_data.contains(v1)) qDebug() << "Graph::addEdge: v1 not exists";
    else
    {
        if (!m_data.contains(v2)) qDebug() << "Graph::addEdge: v2 not exists";
        else
        {
            m_data[v1].addEdgeTo(v2);
            m_data[v2].addEdgeTo(v1);
        }
    }
}

template<class VertexName, class Value>
void Graph<VertexName, Value>::removeVertex(const VertexName &name)
{
    if (m_data.contains(name))
    {
        m_data.remove(name);
        foreach (const VertexName &vname, m_data.keys())
        {
            m_data[vname].removeEdge(name);
        }
    }
}

template<class VertexName, class Value>
void Graph<VertexName, Value>::removeEdge(const VertexName &v1, const VertexName &v2)
{
    m_data[v1].removeEdge(v2);
    m_data[v2].removeEdge(v1);
}

template<class VertexName, class Value>
Vertex<VertexName, Value> &Graph<VertexName, Value>::vertexRef(const VertexName &name)
{ return m_data[name]; }

template<class VertexName, class Value>
Value Graph<VertexName, Value>::value(const VertexName &name) const
{
    if (m_data.contains(name)) return m_data[name].value();
    else return Value();
}

template<class VertexName, class Value>
Vertex<VertexName, Value> Graph<VertexName, Value>::vertex(const VertexName &name) const
{ return m_data[name]; }

template<class VertexName, class Value>
QList<VertexName> Graph<VertexName, Value>::vertices()
{
    auto list = m_data.keys();
    std::sort(list.begin(), list.end());
    return list;
}

template<class VertexName, class Value>
QLinkedList<VertexName> Graph<VertexName, Value>::edges(const VertexName &name) const
{
    if (m_data.contains(name)) return m_data[name].edges();
    else return QLinkedList<VertexName>();
}

template<class VertexName, class Value>
bool Graph<VertexName, Value>::operator ==(const Graph<VertexName, Value> &g)
{ return m_data == g.m_data; }

template<class VertexName, class Value>
bool Graph<VertexName, Value>::vertexExists(const VertexName &name) const
{ return m_data.contains(name); }

template<class VertexName, class Value>
bool Graph<VertexName, Value>::edgeExists(const VertexName &v1, const VertexName &v2) const
{
    if (m_data.contains(v1) && m_data.contains(v2))
        return m_data[v1].edges().contains(v2) || m_data[v2].edges().contains(v1);
    else
        return false;
}

template<class VertexName, class Value>
void Graph<VertexName, Value>::clear()
{ m_data.clear(); }



#endif // GRAPH_HPP
