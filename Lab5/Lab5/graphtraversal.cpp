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

void GraphTraversal::p_deepthSearch(Vertex *root, QLinkedList<QString> &visited)
{
    QLinkedList<Edge *> edges = root->edges();
    foreach (auto edge, edges)
    {
        if (!visited.contains(edge->v1()->name()))
        {
            visited.append(edge->v1()->name());

            emit curentEdge(edge);
            QThread::msleep(m_msecsPause);
            emit repaintEdge(edge);

            emit curentVertex(edge->v1());
            QThread::msleep(m_msecsPause);
            emit repaintVertex(edge->v1());

            p_deepthSearch(edge->v1(), visited);

            emit curentEdge(edge);
            QThread::msleep(m_msecsPause);
            emit repaintEdge(edge);

            emit curentVertex(root);
            QThread::msleep(m_msecsPause);
            emit repaintVertex(root);
        }
        if (!visited.contains(edge->v2()->name()))
        {
            visited.append(edge->v2()->name());

            emit curentEdge(edge);
            QThread::msleep(m_msecsPause);
            emit repaintEdge(edge);

            emit curentVertex(edge->v2());
            QThread::msleep(m_msecsPause);
            emit repaintVertex(edge->v2());

            p_deepthSearch(edge->v2(), visited);

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
            if (!visited.contains(edge->v1()->name()))
            {
                queue.append(edge->v1());
                visited.append(edge->v1()->name());

                emit curentEdge(edge);
                QThread::msleep(m_msecsPause);

                emit curentVertex(edge->v1());
                QThread::msleep(m_msecsPause);

                v_edges.prepend(edge);
                v_vertices.prepend(edge->v1());
            }
            if (!visited.contains(edge->v2()->name()))
            {
                queue.append(edge->v2());
                visited.append(edge->v2()->name());

                emit curentEdge(edge);
                QThread::msleep(m_msecsPause);

                emit curentVertex(edge->v2());
                QThread::msleep(m_msecsPause);

                v_edges.prepend(edge);
                v_vertices.prepend(edge->v2());
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

    p_deepthSearch(root(), visited);

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
