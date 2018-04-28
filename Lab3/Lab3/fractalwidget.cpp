#include "fractalwidget.h"

int FractalWidget::power() const
{
    return m_power;
}

void FractalWidget::setPower(int power)
{
    m_power = power;
    repaint();
}

void FractalWidget::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);

    qreal w = width();
    qreal h = height();
    qreal sh = (w <= h ? w : h) * (5./6.);

    QPointF a(w/2.-sh/2., h/2.-(sh/3.*0.866666));
    QPointF b(w/2., a.y() + sh * 0.866666);
    QPointF c(w-a.x(), a.y());


    QConicalGradient gradient(w/2., h/2., 0.);

    gradient.setColorAt(0., QColor("#fe0000"));
    gradient.setColorAt(0.1666, QColor("#fef900"));
    gradient.setColorAt(0.3333, QColor("#00fe00"));
    gradient.setColorAt(0.5, QColor("#00fef9"));
    gradient.setColorAt(0.6666, QColor("#0000fe"));
    gradient.setColorAt(0.8333, QColor("#fc00fe"));
    gradient.setColorAt(1., QColor("#fe0000"));

    painter.setPen(QPen( QBrush( gradient ), 1. ));


    fractal(painter, a, b, m_power);
    fractal(painter, b, c, m_power);
    fractal(painter, c, a, m_power);

    QWidget::paintEvent(event);
}

void FractalWidget::fractal(QPainter &p, const QPointF &a, const QPointF &e, int n)
{
    if (n)
    {
        qreal lineX = e.x() - a.x();
        qreal lineY = e.y() - a.y();

        QPointF b(a.x() + lineX / 3.,
                  a.y() + lineY / 3.);

        const qreal cos60 = 0.5;
        const qreal sin60 = n > 0 ? 0.866666 : -0.866666;  // знак меняет направление выпуклой стороны

        QPointF c(b.x() + (lineX/3.)*cos60 - (lineY/3.)*sin60,
                  b.y() + (lineX/3.)*sin60 + (lineY/3.)*cos60);

        QPointF d(e.x() - lineX / 3.,
                  e.y() - lineY / 3.);

        fractal(p, a, b, n > 0 ? n - 1 : n + 1);
        fractal(p, b, c, n > 0 ? n - 1 : n + 1);
        fractal(p, c, d, n > 0 ? n - 1 : n + 1);
        fractal(p, d, e, n > 0 ? n - 1 : n + 1);
    }
    else
    {
        p.drawLine(a, e);
    }
}

FractalWidget::FractalWidget(QWidget *parent) :
    QWidget(parent),
    m_power(0)
{

}
