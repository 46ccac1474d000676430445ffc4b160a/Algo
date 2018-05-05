#ifndef GRAPHICSSCENE_HPP
#define GRAPHICSSCENE_HPP

#include <QGraphicsScene>
#include <QGraphicsView>
#include <QPainter>
#include <QSvgGenerator>
#include <QVBoxLayout>
#include <QApplication>
#include <QConicalGradient>
#include <QAction>
#include <QFileDialog>

#include <QMouseEvent>

#include <QDebug>

class GraphicsView : public QGraphicsView
{
    Q_OBJECT

    QGraphicsScene *m_scene;

    QPen m_pen;

    Q_PROPERTY(bool dotTracking READ dotTracking WRITE setDotTracking NOTIFY dotTrackingChanged)
    bool m_dotTracking = false;

    void mousePressEvent(QMouseEvent *event);

    void resizeEvent(QResizeEvent *event);

public:
    explicit GraphicsView(QWidget *parent = nullptr);

    bool dotTracking() const { return m_dotTracking; }
    QGraphicsScene *scene() const;

    void addKoch(const QPointF &a, const QPointF &e, int n);

    void setPenWidth(qreal width);

public slots:
    void setDotTracking(bool dotTracking)
    {
        if (m_dotTracking == dotTracking) return;

        if (dotTracking) viewport()->setCursor(Qt::CrossCursor);
        else QApplication::restoreOverrideCursor();

        m_dotTracking = dotTracking;
        emit dotTrackingChanged(m_dotTracking);
    }

    void saveToSVG();

signals:
    void dotTrackingChanged(bool dotTracking);
    void dotTracked(const QPoint &);
    void widgetSizeChanged(const QSize &);

};

#endif // GRAPHICSSCENE_HPP
