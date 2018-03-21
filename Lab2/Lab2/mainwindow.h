#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>

#include <QChartView>
#include <QTextBrowser>
#include <QLabel>

#include <QDoubleSpinBox>
#include <QToolButton>
#include <QLineEdit>

#include <QScrollBar>

#include <QVBoxLayout>
#include <QHBoxLayout>

#include <QBitmap>

#include <QScriptEngine>

#include <QMessageBox>

#include <QStyle>

#include "chart.h"
#include "formulaclean.h"

using namespace QtCharts;

class MainWindow : public QWidget
{
    Q_OBJECT

    Chart *chart;

    QChartView *chartView;

    QTextBrowser *outputField;

    QToolButton *startBut,
                *updateBut;

    QLineEdit *function;
    QString lastFunc;

    QDoubleSpinBox *leftBorder,
                   *rightBorder,
                   *leftUserBorder,
                   *rightUserBorder,
                   *epsilon;
private slots:
    void onFunctionEditingFinished();

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

public slots:
    void runAlgo();

};

#endif // MAINWINDOW_H
