#ifndef GRAPHTRAVERSAL_HPP
#define GRAPHTRAVERSAL_HPP

#include <QObject>
#include <QThread>
#include <QMutex>
#include "graph.hpp"

#include <QLinkedList>

class GraphTraversal : public QObject
{
    Q_OBJECT

    Vertex *m_root;

    QMutex setRoot_Mutex;

    unsigned long m_msecsPause = 1500u;

public:
    GraphTraversal(QObject *parent = nullptr);
    GraphTraversal(Vertex *root, QObject *parent = nullptr);

    Vertex *root() const;
    void setRoot(Vertex *root);

    unsigned long msecsPause() const;
    void setMsecsPause(unsigned long msecsPause);

public slots:
    void deepthSearch();
    void widthSearch();

signals:
    void curentVertex(Vertex *);
    void curentEdge(Edge *);
    void finished();
};

#endif // GRAPHTRAVERSAL_HPP
