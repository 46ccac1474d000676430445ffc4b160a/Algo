#ifndef DIALOG_HPP
#define DIALOG_HPP

#include <QDialog>

namespace Ui {
class Dialog;
}

struct Counts
{
    int cities;
    int branches;
    int departments;
    int groups;
    int workers;
};

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = 0);
    ~Dialog();

    int citiesCount() const;
    int branchesCount() const;
    int departmentsCount() const;
    int groupsCount() const;

    static int dialog(QWidget *parent, Counts &counts);

private slots:

    void on_buttonBox_accepted();

    void on_buttonBox_rejected();

private:
    Ui::Dialog *ui;
};

#endif // DIALOG_HPP
