#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QWidget(parent)
{
    leftBorder = new QDoubleSpinBox();
    rightBorder = new QDoubleSpinBox;
    leftUserBorder = new QDoubleSpinBox();
    rightUserBorder = new QDoubleSpinBox();
    epsilon=  new QDoubleSpinBox();

    leftBorder->setRange(-1000., 1000);
    rightBorder->setRange(-1000., 1000);
    leftBorder->setValue(-50.);
    rightBorder->setValue(50.);
    leftUserBorder->setRange(-1000., 1000);
    rightUserBorder->setRange(-1000., 1000);
    leftUserBorder->setRange(leftBorder->value(), rightBorder->value());
    rightUserBorder->setRange(leftBorder->value(), rightBorder->value());
    epsilon->setDecimals(9);
    epsilon->setRange(0.000000001, 1);
    epsilon->setValue(0.001);
    epsilon->setMaximumWidth(200);

    function = new QLineEdit("cos(x) * sin(x)");
    function->setMaximumWidth(200);
    lastFunc = function->text();

    chart = new Chart(leftBorder->value(), rightBorder->value(), 0.5, function->text());

    chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);
    chartView->setRubberBand(QChartView::RectangleRubberBand);

    outputField = new QTextBrowser();
    outputField->setFixedHeight(120);
    outputField->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);

    startBut = new QToolButton();
    startBut->setIcon(QIcon(QPixmap(":/run.ico")));
    startBut->setIconSize(QSize(110, 110));


    connect(leftBorder, &QDoubleSpinBox::editingFinished, [=](){
        chart->setLeftBorder(leftBorder->value());
    });
    connect(rightBorder, &QDoubleSpinBox::editingFinished, [=](){
        chart->setRightBorder(rightBorder->value());
    });

    connect(startBut, &QToolButton::clicked, this, &MainWindow::runAlgo);

    connect(function, &QLineEdit::editingFinished, this, &MainWindow::onFunctionEditingFinished);

    QVBoxLayout *vBorderLay = new QVBoxLayout();
    vBorderLay->addWidget(new QLabel("Границы графика:"));
    vBorderLay->addWidget(leftBorder);
    vBorderLay->addWidget(rightBorder);

    QVBoxLayout *vUserBorderLay = new QVBoxLayout();
    vUserBorderLay->addWidget(new QLabel("Границы вычисления X"));
    vUserBorderLay->addWidget(leftUserBorder);
    vUserBorderLay->addWidget(rightUserBorder);

    QVBoxLayout *vFuncEpsLay = new QVBoxLayout();
    vFuncEpsLay->addWidget(new QLabel("Точность:"));
    vFuncEpsLay->addWidget(epsilon);
    vFuncEpsLay->addWidget(new QLabel("Функция: "));
    vFuncEpsLay->addWidget(function);

    QHBoxLayout *hBorderLay = new QHBoxLayout();
    hBorderLay->addLayout(vBorderLay);
    hBorderLay->addLayout(vUserBorderLay);
    hBorderLay->addLayout(vFuncEpsLay);
    hBorderLay->addWidget(outputField);
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

    while (a2 - a1 > eps)
    {
        mid = (a1 + a2) / 2;

        outputField->append(QString("<pre><span style='color: green'>left: </span>%1   <span style='color: green'>right: </span>%2   <span style='color: green'>mid: </span>%3</pre>").arg(a1).arg(a2).arg(mid));

        if( eng.evaluate(func.arg(a2)).toNumber() * eng.evaluate(func.arg(mid)).toNumber() < 0)
            a1 = mid;
        else
            a2 = mid;
    }

    mid = (a1 + a2) / 2;

    outputField->append(QString("<span style='color: red'>Вычисленное значение:</span> %1<br>").arg(mid));

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
