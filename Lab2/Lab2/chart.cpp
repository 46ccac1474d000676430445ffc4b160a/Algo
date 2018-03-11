#include "chart.h"

Chart::Chart(double leftBorder, double rightBorder, double step, const QString &f) :
    LeftBorder(leftBorder), RightBorder(rightBorder), Step(step), func(f)
{
    repaint();
}


void Chart::repaint()
{
    QSplineSeries *ser;

    if (series().isEmpty())
    {
        ser = new QSplineSeries();
    }
    else
    {
        ser = static_cast<QSplineSeries*>(series().at(0));
        ser->clear();
    }
    ser->setName(func);

    QScriptEngine eng;

    QString fun = formulaClean(func);

    for (double x = LeftBorder; x <= RightBorder; x+=Step)
    {
        ser->append(x, eng.evaluate(fun.arg(x)).toNumber());
    }

    if (series().isEmpty()) addSeries(ser);

    createDefaultAxes();
    static_cast<QValueAxis*>(axisX(ser))->setRange(LeftBorder, RightBorder);
    static_cast<QValueAxis*>(axisX(ser))->setTitleText("X-coord");
    static_cast<QValueAxis*>(axisY(ser))->setTitleText("Y-coord");
    static_cast<QValueAxis*>(axisX(ser))->setTickCount(19);
    static_cast<QValueAxis*>(axisY(ser))->setTickCount(9);
}



double Chart::leftBorder() const
{
    return LeftBorder;
}

void Chart::setLeftBorder(double value)
{
    LeftBorder = value;
    repaint();
}

double Chart::rightBorder() const
{
    return RightBorder;
}

void Chart::setRightBorder(double value)
{
    RightBorder = value;
    repaint();
}

void Chart::setF(const QString &s)
{
    func = s;
    repaint();
}

