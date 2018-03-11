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
    QString func;
    double LeftBorder;
    double RightBorder;
    double Step;

public:
    Chart(double leftBorder, double rightBorder, double step, const QString &f);

    void repaint();

    double leftBorder() const;
    void setLeftBorder(double value);

    double rightBorder() const;
    void setRightBorder(double value);

    void setF(const QString &s);
};

#endif // CHART_H
