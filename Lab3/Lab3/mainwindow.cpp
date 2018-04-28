#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QWidget(parent, Qt::Window)
{
    auto fractalwgt = new FractalWidget();
    auto spinbox = new QSpinBox();
    auto slider = new QSlider();

    spinbox->setRange(-7, 7);
    spinbox->setMinimumHeight(100);
    QFont font = spinbox->font();
    font.setPixelSize(70);
    spinbox->setFont(font);

    slider->setRange(-7, 7);
    slider->setStyle(QStyleFactory::create("Android"));

    connect(spinbox, static_cast<void(QSpinBox::*)(int)>(&QSpinBox::valueChanged),
            [=](int val){
        spinbox->clearFocus();
        slider->setValue(val);
        fractalwgt->setPower(val);
    });
    connect(slider, static_cast<void(QSlider::*)(int)>(&QSlider::valueChanged),
            [=](int val){
        spinbox->setValue(val);
        fractalwgt->setPower(val);
    });

    auto hlay = new QHBoxLayout();
    hlay->addWidget(fractalwgt);
    hlay->addWidget(slider);

    auto vlay = new QVBoxLayout();
    vlay->addLayout(hlay);
    vlay->addWidget(spinbox);

    setLayout(vlay);

    setMinimumSize(300, 300);
}

MainWindow::~MainWindow()
{

}
