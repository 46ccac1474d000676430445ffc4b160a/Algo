#include "dialog.hpp"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
}

Dialog::~Dialog()
{
    delete ui;
}

inline int Dialog::citiesCount() const
{
    return ui->citySpin->value();
}

int Dialog::branchesCount() const
{
    return ui->branchSpin->value();
}

int Dialog::departmentsCount() const
{
    return ui->departmentSpin->value();
}

int Dialog::groupsCount() const
{
    return ui->groupSpin->value();
}

int Dialog::dialog(QWidget *parent, Counts &counts)
{
    Dialog *d = new Dialog(parent);
    d->show();

    int ret = d->exec();

    counts.cities = d->ui->citySpin->value();
    counts.branches = d->ui->branchSpin->value();
    counts.departments = d->ui->departmentSpin->value();
    counts.groups = d->ui->groupSpin->value();
    counts.workers = d->ui->workersSpin->value();

    d->deleteLater();

    return ret;
}

void Dialog::on_buttonBox_accepted()
{
    setResult(QDialog::Accepted);
    close();
}

void Dialog::on_buttonBox_rejected()
{
    setResult(QDialog::Rejected);
    close();
}
