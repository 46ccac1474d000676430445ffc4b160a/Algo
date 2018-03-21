#include "chart.h"

Chart::Chart(double leftBorder, double rightBorder, double step, const QString &f) :
    func(f),
    LeftBorder(leftBorder),
    RightBorder(rightBorder),
    Step(step)
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

    double min = eng.evaluate(fun.arg(LeftBorder)).toNumber();
    double max = min;
    for (double x = LeftBorder; x <= RightBorder; x+=Step)
    {
        double y = eng.evaluate(fun.arg(x)).toNumber();
        ser->append(x, y);

        if (y < min) min = y;
        if (y > max) max = y;
    }
    max = (qAbs(max) > qAbs(min)) ? qAbs(max) : qAbs(min);

    if (series().isEmpty()) addSeries(ser);

    createDefaultAxes();
    static_cast<QValueAxis*>(axisX(ser))->setRange(LeftBorder, RightBorder);
    static_cast<QValueAxis*>(axisY(ser))->setRange(-max-0.5, max+0.5);
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

