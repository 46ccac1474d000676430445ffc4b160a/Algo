#ifndef WIDGET_HPP
#define WIDGET_HPP

#include <QWidget>
#include <QTime>
#include <QFileDialog>
#include <QMessageBox>

#include <QFile>

#include <QThread>

#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonObject>

#include "graph.hpp"
#include "graphtraversal.hpp"

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

    Graph *g;

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

private slots:
    void loadFile(const QString &filename);

    void on_placeRoundedButton_clicked();

    void on_openFileButton_clicked();

    void on_startTraversalButton_clicked();

    void on_curentVertex(Vertex *v);
    void on_curentEdge(Edge *e);

    void on_repaintVertex(Vertex *v);
    void on_repaintEdge(Edge *e);

    void on_restoreColorsButton_clicked();

    void on_traversalStarted();
    void on_traversalFinished();

private:
    Ui::Widget *ui;
};

#endif // WIDGET_HPP
