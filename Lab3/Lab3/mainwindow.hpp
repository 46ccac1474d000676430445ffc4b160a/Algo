#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QSpinBox>
#include <QCheckBox>
#include <QDoubleSpinBox>
#include <QSlider>
#include <QPushButton>
#include <QGroupBox>

#include <QGraphicsEllipseItem>

#include "graphicsscene.hpp"

#include <QDebug>

class MainWindow : public QWidget
{
    Q_OBJECT

    GraphicsView *m_view;

    QSlider *m_powerSlider;
    QSpinBox *m_powerSpin;
    QDoubleSpinBox *m_widthSpin;
    QSpinBox *m_x1Spin;
    QSpinBox *m_y1Spin;
    QSpinBox *m_x2Spin;
    QSpinBox *m_y2Spin;

    int m_index = 0;

private slots:
    void updateScene();

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();
};

#endif // MAINWINDOW_H
