#ifndef DRAWWIDGET_H
#define DRAWWIDGET_H

#include <QWidget>
#include <QPainter>
#include <QStyleFactory>
#include <QConicalGradient>

class FractalWidget : public QWidget
{
    Q_OBJECT

    int m_power;

    void paintEvent(QPaintEvent *event);

    void fractal(QPainter &p, const QPointF &a, const QPointF &e, int n);

public:
    explicit FractalWidget(QWidget *parent = nullptr);

    int power() const;
    void setPower(int power);
};

#endif // DRAWWIDGET_H
