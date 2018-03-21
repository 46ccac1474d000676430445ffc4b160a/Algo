#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QWidget(parent)
{
    leftBorder = new QDoubleSpinBox();
    rightBorder = new QDoubleSpinBox;
    leftUserBorder = new QDoubleSpinBox();
    rightUserBorder = new QDoubleSpinBox();
    epsilon=  new QDoubleSpinBox();

    leftBorder->setRange(-100., 100.);
    rightBorder->setRange(-100., 100.);
    leftBorder->setValue(-10.);
    rightBorder->setValue(10.);
    leftUserBorder->setRange(-100., 100.);
    rightUserBorder->setRange(-100., 100.);
    leftUserBorder->setRange(leftBorder->value(), rightBorder->value());
    rightUserBorder->setRange(leftBorder->value(), rightBorder->value());
    epsilon->setDecimals(9);
    epsilon->setRange(0.000000001, 1);
    epsilon->setValue(0.001);
    epsilon->setMaximumWidth(200);
    leftBorder->setToolTip("Левая граница графика функции");
    rightBorder->setToolTip("Правая граница графика функции");
    leftUserBorder->setToolTip("Левая граница вычислений X");
    rightUserBorder->setToolTip("Правая граница вычислений X");
    epsilon->setToolTip("Точность вычислений");

    function = new QLineEdit("$cos(x) * $sin(x)");
    function->setMaximumWidth(160);
    function->setToolTip("Функция от X, например $cos(x) / 7.35 или $pow(x, 2) * $cos(x*$E)\n"
                         "(Использование \"$\" для тригонометрических и встроенных функций обязательно)\n"
                         "Доступные элементы-функции:\n"
                         "$abs(x)\n"
                         "$acos(x)\n"
                         "$asin(x)\n"
                         "$atan(x)\n"
                         "$atan2(y, x)\n"
                         "$ceil(x)\n"
                         "$cos(x)\n"
                         "$exp(x)\n"
                         "$floor(x)\n"
                         "$log(x)\n"
                         "$pow(x, y)\n"
                         "$random()\n"
                         "$round(x)\n"
                         "$sin(x)\n"
                         "$sqrt(x)\n"
                         "$tan(x)\n"
                         "$E"
                         "$PI\n"
                         );
    lastFunc = function->text();

    chart = new Chart(leftBorder->value(), rightBorder->value(), 0.25, function->text());

    chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);
    chartView->setRubberBand(QChartView::RectangleRubberBand);

    outputField = new QTextBrowser();
    outputField->setFixedHeight(120);
    outputField->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
    outputField->setFont(QFont("Monospace"));

    startBut = new QToolButton();
    startBut->setIcon(QIcon(QPixmap(":/run.ico")));
    startBut->setIconSize(QSize(110, 110));
    startBut->setToolTip("Запустить выполнение алгоритма");

    updateBut = new QToolButton();
    updateBut->setIcon(style()->standardIcon(QStyle::SP_BrowserReload));
    updateBut->setToolTip("Нарисовать график");


    connect(leftBorder, static_cast<void(QDoubleSpinBox::*)(double)>(&QDoubleSpinBox::valueChanged), [=](double var){
        rightBorder->setMinimum(var+1);
        leftUserBorder->setMinimum(var);
        chart->setLeftBorder(var);
    });

     connect(rightBorder,
             static_cast<void(QDoubleSpinBox::*)(double)>(&QDoubleSpinBox::valueChanged), [=](double var){
         leftBorder->setMaximum(var-1);
         rightUserBorder->setMaximum(var);
         chart->setRightBorder(var);
     });

    connect(leftUserBorder,
            static_cast<void(QDoubleSpinBox::*)(double)>(&QDoubleSpinBox::valueChanged),
            rightUserBorder,
            &QDoubleSpinBox::setMinimum);
    connect(rightUserBorder,
            static_cast<void(QDoubleSpinBox::*)(double)>(&QDoubleSpinBox::valueChanged),
            leftUserBorder,
            &QDoubleSpinBox::setMaximum);

    connect(startBut, &QToolButton::clicked, this, &MainWindow::runAlgo);

    connect(updateBut, &QToolButton::clicked, this, &MainWindow::onFunctionEditingFinished);

    QVBoxLayout *vBorderLay = new QVBoxLayout();
    vBorderLay->addWidget(new QLabel("Границы\nграфика:"));
    vBorderLay->addWidget(leftBorder);
    vBorderLay->addWidget(rightBorder);

    QVBoxLayout *vUserBorderLay = new QVBoxLayout();
    vUserBorderLay->addWidget(new QLabel("Границы\nвычисления X"));
    vUserBorderLay->addWidget(leftUserBorder);
    vUserBorderLay->addWidget(rightUserBorder);

    QHBoxLayout *hFuncLay = new QHBoxLayout();
    hFuncLay->addWidget(function);
    hFuncLay->addWidget(updateBut);

    QVBoxLayout *vFuncEpsLay = new QVBoxLayout();
    vFuncEpsLay->addWidget(new QLabel("Точность:"));
    vFuncEpsLay->addWidget(epsilon);
    vFuncEpsLay->addWidget(new QLabel("Функция: "));
    vFuncEpsLay->addLayout(hFuncLay);

    QHBoxLayout *hBorderLay = new QHBoxLayout();
    hBorderLay->addLayout(vBorderLay);
    hBorderLay->addSpacing(10);
    hBorderLay->addLayout(vUserBorderLay);
    hBorderLay->addSpacing(10);
    hBorderLay->addLayout(vFuncEpsLay);
    hBorderLay->addSpacing(10);
    hBorderLay->addWidget(outputField);
    hBorderLay->addSpacing(10);
    hBorderLay->addWidget(startBut);

    QVBoxLayout *vlay = new QVBoxLayout();
    vlay->addWidget(chartView);
    vlay->addLayout(hBorderLay);

    setLayout(vlay);
}

MainWindow::~MainWindow()
{

}

void MainWindow::onFunctionEditingFinished()
{
    if (chart->series().size() > 1) static_cast<QSplineSeries*>(chart->series()[1])->clear();

    function->clearFocus();
    QString func = function->text();
    QScriptEngine eng;
    bool ok;
    eng.evaluate(formulaClean(func).arg(0)).toVariant().toDouble(&ok);
    if (!ok)
    {
        QMessageBox::warning(this, "Ошибка!", QString("Невозможно посчитать формулу:\n%1").arg(function->text()));
        function->setText(lastFunc);
        return;
    }
    chart->setF(func);
    lastFunc = func;
}

void MainWindow::runAlgo()
{
    double a1 = leftUserBorder->value(),
           a2 = rightUserBorder->value(),
           eps = epsilon->value(),
           mid;

    QString func = formulaClean(function->text());

    QScriptEngine eng;

    bool ok;
    eng.evaluate(func.arg(0)).toVariant().toDouble(&ok);
    if (!ok)
    {
        QMessageBox::warning(this, "Ошибка!", QString("Невозможно посчитать формулу:\n%1").arg(function->text()));
        return;
    }

    outputField->append("Фунцкия: <span style='color: red'>" + function->text().append("</span>\n"));

#define f(x) eng.evaluate(func.arg(x)).toNumber()

    int i = 1;
    while (a2 - a1 > eps)
    {
        mid = (a1 + a2) / 2;

        outputField->append(QString(
        "<pre>"
        "<span style='color: red'>%1 </span>"
        "<span style='color: green'>left: </span>%2  "
        "<span style='color: green'>right: </span>%3  "
        "<span style='color: green'>mid: </span>%4"
        "</pre>"
        ).arg(i++).arg(a1, 0, 'g', 7).arg(a2, 0, 'g', 7).arg(mid, 0, 'g', 7));

        if( f(a2) * f(mid) < 0)
            a1 = mid;
        else
            a2 = mid;
    }
#undef f

    mid = (a1 + a2) / 2;

    outputField->append(QString("<span style='color: red'>Вычисленное значение:</span> %1<br>").arg(mid, 0, 'g', 7));

    outputField->verticalScrollBar()->setValue(outputField->verticalScrollBar()->maximum());

    QLineSeries *dot;
    if (chart->series().size() > 1)
    {
        dot = static_cast<QLineSeries*>(chart->series().at(1));
        dot->clear();
    }
    else
    {
        dot = new QLineSeries();
        dot->setPen(QPen(QBrush(Qt::red), 5, Qt::SolidLine, Qt::RoundCap));
        dot->setName(QString("Dot: x = %1, y = 0").arg(mid));
        chart->addSeries(dot);
    }

    dot->append(mid-0.001, 0.);
    dot->append(mid+0.001, 0.);
    chart->repaint();
}
