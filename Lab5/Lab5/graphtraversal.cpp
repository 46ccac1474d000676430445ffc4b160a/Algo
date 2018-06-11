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

void GraphTraversal::deepthSearch()
{
    QMutexLocker l(&setRoot_Mutex);

    QLinkedList<Vertex *> stack;
    QLinkedList<QString> visited;

    stack.append(m_root);
    visited.append(m_root->name());

    emit curentVertex(m_root);
    QThread::msleep(m_msecsPause);

    while (!stack.isEmpty())
    {
        Vertex *vertex = stack.last();
        stack.removeLast();


        QLinkedList<Edge *> edges = vertex->edges();
        foreach (Edge *edge, edges)
        {
            if (!visited.contains(edge->v1()->name()))
            {
                stack.append(edge->v1());
                visited.append(edge->v1()->name());

                emit curentEdge(edge);
                QThread::msleep(m_msecsPause);
                emit curentVertex(edge->v1());
                QThread::msleep(m_msecsPause);
            }
            if (!visited.contains(edge->v2()->name()))
            {
                stack.append(edge->v2());
                visited.append(edge->v2()->name());

                emit curentEdge(edge);
                QThread::msleep(m_msecsPause);
                emit curentVertex(edge->v2());
                QThread::msleep(m_msecsPause);
            }
        }
    }

    emit finished();
}

void GraphTraversal::widthSearch()
{
    QMutexLocker l(&setRoot_Mutex);

    QLinkedList<Vertex *> queue;
    QLinkedList<QString> visited;

    queue.append(m_root);
    visited.append(m_root->name());

    emit curentVertex(m_root);
    QThread::msleep(m_msecsPause);

    while (!queue.isEmpty())
    {
        Vertex *vertex = queue.first();
        queue.removeFirst();

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
            }
            if (!visited.contains(edge->v2()->name()))
            {
                queue.append(edge->v2());
                visited.append(edge->v2()->name());

                emit curentEdge(edge);
                QThread::msleep(m_msecsPause);
                emit curentVertex(edge->v2());
                QThread::msleep(m_msecsPause);
            }
        }
    }

    emit finished();
}
