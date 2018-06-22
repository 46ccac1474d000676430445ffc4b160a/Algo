#ifndef GRAPHTRAVERSAL_HPP
#define GRAPHTRAVERSAL_HPP

#include <QObject>
#include <QThread>
#include <QMutex>
#include "graph.hpp"

#include <QLinkedList>
#include <QSet>

class GraphTraversal : public QObject
{
    Q_OBJECT

    Vertex *m_root;

    QMutex setRoot_Mutex;

    void p_deepthSearch(Vertex *root, QSet<QString> &visited, QString path);
    void p_widthSearch(Vertex *root, QSet<QString> &visited, QHash<QString, QString> &parents);

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
    void repaintVertex(Vertex *);
    void repaintEdge(Edge *);

    void curentVertex(Vertex *);
    void curentEdge(Edge *);

    void log(const QString &);

    void finished();
};

#endif // GRAPHTRAVERSAL_HPP
