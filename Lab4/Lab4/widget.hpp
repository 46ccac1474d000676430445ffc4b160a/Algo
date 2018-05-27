#ifndef WIDGET_HPP
#define WIDGET_HPP

#include <QWidget>
#include <QMessageBox>
#include <QClipboard>
#include <QListWidgetItem>
#include <QTimer>
#include <QGraphicsOpacityEffect>

#include "structures/structure.hpp"
#include "dialog.hpp"

namespace Ui {
class Widget;
}

class MainWindow : public QWidget
{
    Q_OBJECT

    Ui::Widget *ui;

    HashTable<City> cities; // key is name of branch
    HashTable<WorkerData> workersData;


public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_searchFormData_clicked();

    void on_cityInput_currentTextChanged(const QString &city);

    void on_branchInput_currentTextChanged(const QString &branch);

    void on_departmentInput_currentTextChanged(const QString &department);

    void on_listWidget_itemDoubleClicked(QListWidgetItem *item);

    void on_searchFormData_2_clicked();
};

#endif // WIDGET_HPP
