#include "dialog.hpp"
#include "ui_dialog.h"
#include "structures/structure.hpp"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);

    connect(ui->buttonBox, &QDialogButtonBox::accepted, this, &Dialog::accept);
    connect(ui->buttonBox, &QDialogButtonBox::rejected, this, &Dialog::reject);
}

Dialog::~Dialog()
{
    delete ui;
}

int Dialog::citiesCount() const
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

int Dialog::workersCount() const
{
     return ui->workersSpin->value();
}
