#include "graphtraversal.hpp"

Vertex *GraphTraversal::root() const
{ return m_root; }

void GraphTraversal::setRoot(Vertex *root)
{
    QMutexLocker l(&setRoot_Mutex);
    m_root = root;
}

unsigned long GraphTraversal::msecsPause() const
{ return m_msecsPause; }

void GraphTraversal::setMsecsPause(unsigned long msecsPause)
{ m_msecsPause = msecsPause; }

GraphTraversal::GraphTraversal(QObject *parent) :
    QObject(parent)
{
    connect(this, &GraphTraversal::finished, this, &GraphTraversal::deleteLater, Qt::DirectConnection);
}

GraphTraversal::GraphTraversal(Vertex *root, QObject *parent) :
    QObject(parent),
    m_root(root)
{
    connect(this, &GraphTraversal::finished, this, &GraphTraversal::deleteLater, Qt::DirectConnection);
}

void GraphTraversal::p_deepthSearch(Vertex *root, QLinkedList<QString> &visited, QString path)
{
    QLinkedList<Edge *> edges = root->edges();
    foreach (auto edge, edges)
    {
        Vertex *l_vertex = nullptr;

        if (!visited.contains(edge->v1()->name())) l_vertex = edge->v1();
        else if (!visited.contains(edge->v2()->name())) l_vertex = edge->v2();

        if (l_vertex != nullptr)
        {
            visited.append(l_vertex->name());

            emit curentEdge(edge);
            QThread::msleep(m_msecsPause);
            emit repaintEdge(edge);

            emit curentVertex(l_vertex);
            QThread::msleep(m_msecsPause);
            emit repaintVertex(l_vertex);

            emit log(path+", "+l_vertex->name());
            p_deepthSearch(l_vertex, visited, path+", "+l_vertex->name());

            emit curentEdge(edge);
            QThread::msleep(m_msecsPause);
            emit repaintEdge(edge);

            emit curentVertex(root);
            QThread::msleep(m_msecsPause);
            emit repaintVertex(root);
        }
    }
}

void GraphTraversal::p_widthSearch(Vertex *root, QLinkedList<QString> &visited)
{
    QLinkedList<Vertex *> queue;

    queue.append(root);
    visited.append(root->name());

    while (!queue.isEmpty())
    {
        Vertex *vertex = queue.takeFirst();


        emit curentVertex(vertex);
        QThread::msleep(m_msecsPause);

        QLinkedList<Edge *> v_edges;
        QLinkedList<Vertex *> v_vertices;


        QLinkedList<Edge *> edges = vertex->edges();
        foreach (Edge *edge, edges)
        {
            Vertex *l_vertex = nullptr;

            if (!visited.contains(edge->v1()->name())) l_vertex = edge->v1();
            else if (!visited.contains(edge->v2()->name())) l_vertex = edge->v2();

            if (l_vertex != nullptr)
            {
                queue.append(l_vertex);
                visited.append(l_vertex->name());

                emit curentEdge(edge);
                QThread::msleep(m_msecsPause);

                emit curentVertex(l_vertex);
                QThread::msleep(m_msecsPause);

                v_edges.prepend(edge);
                v_vertices.prepend(l_vertex);
            }
        }

        int n = v_vertices.size();
        while(n--)
        {
            emit repaintVertex(v_vertices.takeFirst());
            QThread::msleep(m_msecsPause);

            emit repaintEdge(v_edges.takeFirst());
            QThread::msleep(m_msecsPause);
        }
        emit repaintVertex(vertex);
        QThread::msleep(m_msecsPause);
    }
}

void GraphTraversal::deepthSearch()
{
    QMutexLocker l(&setRoot_Mutex);

    QLinkedList<QString> visited;
    visited.append(root()->name());

    emit curentVertex(root());
    QThread::msleep(m_msecsPause);
    emit repaintVertex(root());

    p_deepthSearch(root(), visited, root()->name());

    emit finished();
}

void GraphTraversal::widthSearch()
{
    QMutexLocker l(&setRoot_Mutex);

    QLinkedList<QString> visited;
    visited.append(root()->name());

    p_widthSearch(root(), visited);

    emit finished();
}
