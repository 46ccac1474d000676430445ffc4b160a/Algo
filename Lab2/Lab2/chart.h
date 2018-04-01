#ifndef CHART_H
#define CHART_H

#include <QObject>
#include <QChart>
#include <QSplineSeries>
#include <QValueAxis>

#include <QScriptEngine>

#include "formulaclean.h"

using namespace QtCharts;

class Chart : public QChart
{
    Q_OBJECT

    QString func;
    double LeftBorder;
    double RightBorder;
    double Step;

public:
    Chart(double leftBorder, double rightBorder, double step, const QString &f);

    double leftBorder() const;
    double rightBorder() const;

public slots:
    void setLeftBorder(double value);
    void setRightBorder(double value);
    void setF(const QString &s);
    void repaint();

};

#endif // CHART_H
