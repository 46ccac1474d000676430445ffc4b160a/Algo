#ifndef DIALOG_HPP
#define DIALOG_HPP

#include <QDialog>
//#include "structures/structure.hpp"

struct Counts;

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = 0);
    virtual ~Dialog();

    int citiesCount() const;
    int branchesCount() const;
    int departmentsCount() const;
    int groupsCount() const;
    int workersCount() const;

private:
    Ui::Dialog *ui;
};

#endif // DIALOG_HPP
