#include "widget.hpp"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    g(new Graph()),
    ui(new Ui::Widget)
{
    qsrand(QTime::currentTime().msecsSinceStartOfDay());

    ui->setupUi(this);

    ui->clearButton->setIcon(style()->standardIcon(QStyle::SP_TrashIcon));
    connect(ui->clearButton, &QToolButton::clicked, ui->outputField, &QTextBrowser::clear);

    g->setSceneRect(QRectF(0., 0., 600, 600));

    ui->graphicsView->setScene(g);
    ui->graphicsView->thread()->setPriority(QThread::TimeCriticalPriority);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_placeRoundedButton_clicked()
{
    g->placeRounded();
}

void Widget::loadFile(const QString &filename)
{
    QFile f(filename);
    if (f.open(QIODevice::ReadOnly))
    {
        //qDebug() << "File opened";

        QVariantMap map = QJsonDocument::fromJson(f.readAll()).toVariant().toMap();
        f.close();

        g->clearVertices();
        g->clear();

        foreach (auto val, map["edges"].toJsonArray())
        {
            if (val.toArray().size() == 2)
            {
                if (!g->vertexExists(val.toArray()[0].toString()))
                    g->addVertex(val.toArray()[0].toString());

                if (!g->vertexExists(val.toArray()[1].toString()))
                    g->addVertex(val.toArray()[1].toString());
            }
        }

        foreach (auto val, map["edges"].toJsonArray())
        {
            if (val.toArray().size() == 2)
                g->addEdge(val.toArray()[0].toString(), val.toArray()[1].toString());
        }

        ui->rootVertexName->clear();
        ui->rootVertexName->addItems(g->vertexNames());

        g->placeRounded();

        ui->placeRoundedButton->setEnabled(true);
        ui->startTraversalButton->setEnabled(true);
        ui->restoreColorsButton->setEnabled(true);
    }
    else
    {
        QMessageBox::warning(this, "Чтение из файла", QString("Невозможно открыть файл: \"%1\"").arg(filename));
    }
}

void Widget::on_openFileButton_clicked()
{
    QString filename = QFileDialog::getOpenFileName(this, "Open", QDir::currentPath());
    if (!filename.isEmpty())
    {
        loadFile(filename);
    }
}

void Widget::on_startTraversalButton_clicked()
{
    if (!g->isEmpty())
    {
        auto t = new QThread();

        auto df = new GraphTraversal(g->vertex(ui->rootVertexName->currentText()));
        df->setMsecsPause(ui->delaySpinBox->value() * 1000.0);
        df->moveToThread(t);

        connect(t, &QThread::finished, t, &QThread::deleteLater);
        connect(this, &Widget::destroyed, df, &GraphTraversal::deleteLater);

        connect(df, &GraphTraversal::finished, t, &QThread::quit);


        connect(df, &GraphTraversal::curentVertex, this, &Widget::on_curentVertex);
        connect(df, &GraphTraversal::curentEdge, this, &Widget::on_curentEdge);

        connect(df, &GraphTraversal::repaintVertex, this, &Widget::on_repaintVertex);
        connect(df, &GraphTraversal::repaintEdge, this, &Widget::on_repaintEdge);

        connect(df, &GraphTraversal::log, this, &Widget::getLog);

        connect(t, &QThread::started, this, &Widget::on_traversalStarted);

        if (ui->deepthTrRadio->isChecked())
            connect(t, &QThread::started, df, &GraphTraversal::deepthSearch);
        else if (ui->widthTrRadio->isChecked())
            connect(t, &QThread::started, df, &GraphTraversal::widthSearch);

        connect(t, &QThread::finished, this, &Widget::on_traversalFinished);

        t->start();
    }
}

void Widget::on_curentVertex(Vertex *v)
{
    v->setBrush(QBrush(QColor("#0f0")));
    v->setPen(QPen(QBrush("black"), 2.));
}

void Widget::on_curentEdge(Edge *e)
{
    e->setPen(QPen(QBrush("#0f0"), 3.5));
}

void Widget::on_traversalStarted()
{
    ui->rootVertexName->setDisabled(true);
    ui->delaySpinBox->setDisabled(true);
    ui->deepthTrRadio->setDisabled(true);
    ui->widthTrRadio->setDisabled(true);
    ui->startTraversalButton->setDisabled(true);
    ui->openFileButton->setDisabled(true);
    ui->restoreColorsButton->setDisabled(true);
    ui->clearButton->setDisabled(true);

    ui->outputField->append(QString("Начало обхода в %1:")
                            .arg(ui->deepthTrRadio->isChecked() ? "глубину" : "ширину"));
}

void Widget::on_traversalFinished()
{
    ui->outputField->append("Обход завершён");
    ui->outputField->append("<br>");
    QMessageBox::information(this, "Обход графа", "Обход графа завершен!");

    ui->rootVertexName->setEnabled(true);
    ui->delaySpinBox->setEnabled(true);
    ui->deepthTrRadio->setEnabled(true);
    ui->widthTrRadio->setEnabled(true);
    ui->startTraversalButton->setEnabled(true);
    ui->openFileButton->setEnabled(true);
    ui->restoreColorsButton->setEnabled(true);
    ui->clearButton->setEnabled(true);
}

void Widget::on_repaintVertex(Vertex *v)
{
    if (ui->deepthTrRadio->isChecked())
    {
        v->setBrush(QBrush(QColor("red")));
    }
    else if (ui->widthTrRadio->isChecked())
    {
        v->setBrush(QBrush(QColor("blue")));
    }
    v->setPen(QPen(QBrush("black"), 1.));
}

void Widget::on_repaintEdge(Edge *e)
{
    if (ui->deepthTrRadio->isChecked()) e->setPen(QPen(QBrush("red"), 2.));
    else if (ui->widthTrRadio->isChecked()) e->setPen(QPen(QBrush("blue"), 2.));
}

void Widget::getLog(const QString &log)
{
    ui->outputField->append(QString("<span style='color: %1'>%2</span>")
                                .arg(ui->deepthTrRadio->isChecked() ? "red" : "blue")
                                .arg(log));
}

void Widget::on_restoreColorsButton_clicked()
{
    g->setVerticesColor();
    g->setEdgesColor();
}
