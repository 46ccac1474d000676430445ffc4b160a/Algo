#include "mainwindow.hpp"

void MainWindow::updateScene()
{
    QPointF p1(m_x1Spin->value(), m_y1Spin->value());
    QPointF p2(m_x2Spin->value(), m_y2Spin->value());

    m_view->scene()->clear();

    m_view->addKoch(p1, p2, m_powerSpin->value());

    m_view->scene()->addEllipse(p1.x()-2.5, p1.y()-2.5, 5., 5., QPen(QColor(255, 0, 0)), QBrush(QColor(255, 0, 0)))->setToolTip("Point 1");
    m_view->scene()->addEllipse(p2.x()-2.5, p2.y()-2.5, 5., 5., QPen(QColor(0, 255, 0)), QBrush(QColor(0, 255, 0)))->setToolTip("Point 1");
}

MainWindow::MainWindow(QWidget *parent)
    : QWidget(parent, Qt::Window)
{
    m_label = new QLabel("<pre style='color: red'>Lines drawn:\n0</pre>");
    m_powerSlider = new QSlider(Qt::Horizontal);
    m_powerSpin = new QSpinBox();
    m_widthSpin = new QDoubleSpinBox();
    m_x1Spin = new QSpinBox();
    m_y1Spin = new QSpinBox();
    m_x2Spin = new QSpinBox();
    m_y2Spin = new QSpinBox();

    m_view = new GraphicsView();

    auto powerUpEnable = new QCheckBox("&Enable\nhigher\npower");

//SETUP

    connect(m_view, &GraphicsView::linesCounted, [=](int val) -> void {
        m_label->setText(QString("<pre style='color: red'>Lines drawn:\n%1</pre>").arg(val));
    });

    m_powerSlider->setRange(-5, 5);
    m_powerSlider->setSingleStep(1);
    m_powerSlider->setPageStep(1);
    m_powerSpin->setRange(-5, 5);

    connect(m_powerSlider, &QSlider::valueChanged, m_powerSpin, &QSpinBox::setValue);
    connect(m_powerSpin, QOverload<int>::of(&QSpinBox::valueChanged), m_powerSlider, &QSlider::setValue);
    connect(m_powerSlider, &QSlider::valueChanged, this, &MainWindow::updateScene);


    m_widthSpin->setRange(0.05, 3.);
    m_widthSpin->setSingleStep(0.05);
    m_widthSpin->setValue(1.);

    connect(m_widthSpin, QOverload<double>::of(&QDoubleSpinBox::valueChanged), [=](qreal val) -> void {
        m_view->setPenWidth(val);
        updateScene();
    });


    m_x1Spin->setRange(1, m_view->width()-2);
    m_y1Spin->setRange(1, m_view->height()-2);
    m_x2Spin->setRange(1, m_view->width()-2);
    m_y2Spin->setRange(1, m_view->height()-2);

    connect(m_x1Spin, QOverload<int>::of(&QSpinBox::valueChanged), this, &MainWindow::updateScene);
    connect(m_y1Spin, QOverload<int>::of(&QSpinBox::valueChanged), this, &MainWindow::updateScene);
    connect(m_x2Spin, QOverload<int>::of(&QSpinBox::valueChanged), this, &MainWindow::updateScene);
    connect(m_y2Spin, QOverload<int>::of(&QSpinBox::valueChanged), this, &MainWindow::updateScene);


    m_view->setDotTracking(true);
    m_view->setToolTip("Choose first point");

    auto saveBut = new QPushButton("&Save to SVG");
    connect(saveBut, &QPushButton::clicked, m_view, &GraphicsView::saveToSVG);

    auto repaintAct = new QAction("&Repaint");
    auto clearAct = new QAction("&Clear");
    auto saveToSVGAct = new QAction("&Save to SVG");

    connect(repaintAct, &QAction::triggered, this, &MainWindow::updateScene);
    connect(clearAct, &QAction::triggered, [=]() -> void {
        m_view->scene()->clear();

        m_label->setText("<pre style='color: red'>Lines drawn:\n0</pre>");

        m_x1Spin->blockSignals(true);
        m_y1Spin->blockSignals(true);
        m_x2Spin->blockSignals(true);
        m_y2Spin->blockSignals(true);

        m_x1Spin->setValue(1);
        m_y1Spin->setValue(1);
        m_x2Spin->setValue(1);
        m_y2Spin->setValue(1);

        m_x1Spin->blockSignals(false);
        m_y1Spin->blockSignals(false);
        m_x2Spin->blockSignals(false);
        m_y2Spin->blockSignals(false);

        m_index = 0;
    });
    connect(saveToSVGAct, &QAction::triggered, m_view, &GraphicsView::saveToSVG);


    m_view->setContextMenuPolicy(Qt::ActionsContextMenu);
    m_view->addAction(repaintAct);
    m_view->addAction(clearAct);
    m_view->addAction(saveToSVGAct);

    connect(m_view, &GraphicsView::dotTracked, [=](const QPointF &p) -> void {
        m_index++;
        if (m_index == 1)
        {
            m_x1Spin->blockSignals(true);
            m_y1Spin->blockSignals(true);

            m_x1Spin->setValue(p.x());
            m_y1Spin->setValue(p.y());

            m_x1Spin->blockSignals(false);
            m_y1Spin->blockSignals(false);

            m_view->setToolTip("Choose second point");

            m_view->scene()->clear();
            m_view->scene()->addEllipse(p.x()-2.5, p.y()-2.5, 5., 5., QPen(QColor(255, 0, 0)), QBrush(Qt::red))->setToolTip("Point 1");
        }
        else if (m_index == 2)
        {
            m_x2Spin->blockSignals(true);
            m_y2Spin->blockSignals(true);

            m_x2Spin->setValue(p.x());
            m_y2Spin->setValue(p.y());

            m_x2Spin->blockSignals(false);
            m_y2Spin->blockSignals(false);

            m_view->setToolTip("Choose first point");

            updateScene();

            m_index = 0;
        }
    });

    connect(m_view, &GraphicsView::widgetSizeChanged, [=](const QSize &sz) -> void {
        m_x1Spin->setRange(1, sz.width()-2);
        m_y1Spin->setRange(1, sz.height()-2);
        m_x2Spin->setRange(1, sz.width()-2);
        m_y2Spin->setRange(1, sz.height()-2);
    });


    powerUpEnable->setToolTip("<pre>Enable to increase power up to 10 (default limit is 5).\n</pre><pre style='color: red'>Not recommended. It can cause the program to stop</pre>");
    connect(powerUpEnable, &QCheckBox::toggled, [=](bool val) -> void {
        if (val)
        {
            m_powerSlider->setRange(-10, 10);
            m_powerSpin->setRange(-10, 10);
        }
        else
        {
            m_powerSlider->setRange(-5, 5);
            m_powerSpin->setRange(-5, 5);
        }
    });

//LAYOUTS

    auto vp1Lay = new QVBoxLayout();
    vp1Lay->addWidget(m_x1Spin);
    vp1Lay->addWidget(m_y1Spin);

    auto vp2Lay = new QVBoxLayout();
    vp2Lay->addWidget(m_x2Spin);
    vp2Lay->addWidget(m_y2Spin);

    auto vWthSpLay = new QVBoxLayout();
    vWthSpLay->addWidget(m_widthSpin);

    auto vPwLay = new QVBoxLayout();
    vPwLay->addWidget(m_powerSpin);
    vPwLay->addWidget(powerUpEnable);

    auto p1Box = new QGroupBox("Point 1");
    auto p2Box = new QGroupBox("Point 2");
    auto widthBox = new QGroupBox("Line width");
    auto powerBox = new QGroupBox("Power");

    p1Box->setLayout(vp1Lay);
    p2Box->setLayout(vp2Lay);

    widthBox->setLayout(vWthSpLay);

    powerBox->setLayout(vPwLay);

    auto vSpBxLay = new QVBoxLayout();
    vSpBxLay->addWidget(saveBut);
    vSpBxLay->addWidget(m_label);
    vSpBxLay->addWidget(p1Box);
    vSpBxLay->addWidget(p2Box);
    vSpBxLay->addWidget(widthBox);
    vSpBxLay->addWidget(powerBox);

    auto vViewLay = new QVBoxLayout();
    vViewLay->addWidget(m_view);
    vViewLay->addWidget(m_powerSlider);

    auto hlay = new QHBoxLayout();
    hlay->addLayout(vSpBxLay);
    hlay->addLayout(vViewLay);

    setLayout(hlay);
}

MainWindow::~MainWindow()
{

}
