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

void GraphTraversal::p_deepthSearch(Vertex *root, QSet<QString> &visited, QString path)
{
    QLinkedList<Edge *> edges = root->edges();
    foreach (auto edge, edges)
    {
        Vertex *l_vertex = nullptr;

        if (!visited.contains(edge->v1()->name())) l_vertex = edge->v1();
        else if (!visited.contains(edge->v2()->name())) l_vertex = edge->v2();

        if (l_vertex != nullptr)
        {
            visited.insert(l_vertex->name());

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

void GraphTraversal::p_widthSearch(Vertex *root, QSet<QString> &visited, QHash<QString, QString> &parents)
{
    QLinkedList<Vertex *> queue;

    queue.append(root);
    visited.insert(root->name());
    parents.insert(root->name(), root->name());

    while (!queue.isEmpty())
    {
        Vertex *vertex = queue.takeFirst();

        emit curentVertex(vertex);
        QThread::msleep(m_msecsPause);



        QString val = vertex->name();
        QVector<QString> l_stack;

        while(root->name() != val)
        {
            l_stack.prepend(val);
            val = parents.value(val);
        }

        QString path = root->name() + ", ";
        foreach (QString s, l_stack)
        {
            path.append(s + ", ");
        }

        emit log(path);



        QLinkedList<Edge *> edges = vertex->edges();
        foreach (Edge *edge, edges)
        {
            Vertex *l_vertex = nullptr;

            if (!visited.contains(edge->v1()->name())) l_vertex = edge->v1();
            else if (!visited.contains(edge->v2()->name())) l_vertex = edge->v2();

            if (l_vertex != nullptr)
            {
                queue.append(l_vertex);
                visited.insert(l_vertex->name());
                parents.insert(l_vertex->name(), vertex->name());

                emit curentEdge(edge);
                QThread::msleep(m_msecsPause);

                emit curentVertex(l_vertex);
                QThread::msleep(m_msecsPause);

                emit repaintVertex(l_vertex);
                QThread::msleep(m_msecsPause);

                emit repaintEdge(edge);
                QThread::msleep(m_msecsPause);
            }
        }

        emit repaintVertex(vertex);
        QThread::msleep(m_msecsPause);
    }
}

void GraphTraversal::deepthSearch()
{
    QMutexLocker l(&setRoot_Mutex);

    QSet<QString> visited;
    visited.insert(root()->name());

    emit curentVertex(root());
    QThread::msleep(m_msecsPause);
    emit repaintVertex(root());

    p_deepthSearch(root(), visited, root()->name());

    emit finished();
}

void GraphTraversal::widthSearch()
{
    QMutexLocker l(&setRoot_Mutex);

    QSet<QString> visited;
    QHash<QString, QString> parents;

    p_widthSearch(root(), visited, parents);

    emit finished();
}
