/********************************************************************************
** Form generated from reading UI file 'dialog.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOG_H
#define UI_DIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_Dialog
{
public:
    QVBoxLayout *verticalLayout;
    QGridLayout *gridLayout;
    QLabel *label_2;
    QLabel *label_4;
    QLabel *label_3;
    QSpinBox *citySpin;
    QLabel *label;
    QSpinBox *branchSpin;
    QSpinBox *departmentSpin;
    QLabel *label_5;
    QSpinBox *groupSpin;
    QSpinBox *workersSpin;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *Dialog)
    {
        if (Dialog->objectName().isEmpty())
            Dialog->setObjectName(QStringLiteral("Dialog"));
        Dialog->setWindowModality(Qt::NonModal);
        Dialog->resize(540, 158);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(Dialog->sizePolicy().hasHeightForWidth());
        Dialog->setSizePolicy(sizePolicy);
        Dialog->setMaximumSize(QSize(540, 158));
        Dialog->setModal(true);
        verticalLayout = new QVBoxLayout(Dialog);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        label_2 = new QLabel(Dialog);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout->addWidget(label_2, 1, 1, 1, 1);

        label_4 = new QLabel(Dialog);
        label_4->setObjectName(QStringLiteral("label_4"));

        gridLayout->addWidget(label_4, 1, 3, 1, 1);

        label_3 = new QLabel(Dialog);
        label_3->setObjectName(QStringLiteral("label_3"));

        gridLayout->addWidget(label_3, 1, 2, 1, 1);

        citySpin = new QSpinBox(Dialog);
        citySpin->setObjectName(QStringLiteral("citySpin"));
        citySpin->setMinimum(1);
        citySpin->setMaximum(100);
        citySpin->setValue(20);

        gridLayout->addWidget(citySpin, 2, 0, 1, 1);

        label = new QLabel(Dialog);
        label->setObjectName(QStringLiteral("label"));

        gridLayout->addWidget(label, 1, 0, 1, 1);

        branchSpin = new QSpinBox(Dialog);
        branchSpin->setObjectName(QStringLiteral("branchSpin"));
        branchSpin->setMinimum(1);
        branchSpin->setMaximum(100);
        branchSpin->setValue(5);

        gridLayout->addWidget(branchSpin, 2, 1, 1, 1);

        departmentSpin = new QSpinBox(Dialog);
        departmentSpin->setObjectName(QStringLiteral("departmentSpin"));
        departmentSpin->setMinimum(1);
        departmentSpin->setMaximum(100);
        departmentSpin->setValue(10);

        gridLayout->addWidget(departmentSpin, 2, 2, 1, 1);

        label_5 = new QLabel(Dialog);
        label_5->setObjectName(QStringLiteral("label_5"));

        gridLayout->addWidget(label_5, 1, 4, 1, 1);

        groupSpin = new QSpinBox(Dialog);
        groupSpin->setObjectName(QStringLiteral("groupSpin"));
        groupSpin->setMinimum(1);
        groupSpin->setMaximum(100);
        groupSpin->setValue(10);

        gridLayout->addWidget(groupSpin, 2, 3, 1, 1);

        workersSpin = new QSpinBox(Dialog);
        workersSpin->setObjectName(QStringLiteral("workersSpin"));
        workersSpin->setMinimum(1);
        workersSpin->setMaximum(1000);
        workersSpin->setValue(100);

        gridLayout->addWidget(workersSpin, 2, 4, 1, 1);


        verticalLayout->addLayout(gridLayout);

        buttonBox = new QDialogButtonBox(Dialog);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout->addWidget(buttonBox);


        retranslateUi(Dialog);

        QMetaObject::connectSlotsByName(Dialog);
    } // setupUi

    void retranslateUi(QDialog *Dialog)
    {
        Dialog->setWindowTitle(QApplication::translate("Dialog", "\320\237\320\260\321\200\320\260\320\274\320\265\321\202\321\200\321\213 \320\263\320\265\320\275\320\265\321\200\320\260\321\206\320\270\320\270 \321\201\321\202\321\200\321\203\320\272\321\202\321\203\321\200\321\213 \320\276\321\200\320\263\320\260\320\275\320\270\320\267\320\260\321\206\320\270\320\270", nullptr));
        label_2->setText(QApplication::translate("Dialog", "\320\247\320\270\321\201\320\273\320\276\n"
"\321\204\320\270\320\273\320\270\320\260\320\273\320\276\320\262\n"
"\320\262 \320\272\320\260\320\266\320\264\320\276\320\274\n"
"\320\263\320\276\321\200\320\276\320\264\320\265", nullptr));
        label_4->setText(QApplication::translate("Dialog", "\320\247\320\270\321\201\320\273\320\276\n"
"\320\263\321\200\321\203\320\277\320\277\n"
"\320\262 \320\272\320\260\320\266\320\264\320\276\320\274\n"
"\320\276\321\202\320\264\320\265\320\273\320\265", nullptr));
        label_3->setText(QApplication::translate("Dialog", "\320\247\320\270\321\201\320\273\320\276\n"
"\320\276\321\202\320\264\320\265\320\273\320\276\320\262\n"
"\320\262 \320\272\320\260\320\266\320\264\320\276\320\274\n"
"\321\204\320\270\320\273\320\270\320\260\320\273\320\265", nullptr));
        label->setText(QApplication::translate("Dialog", "\320\247\320\270\321\201\320\273\320\276\n"
"\320\263\320\276\321\200\320\276\320\264\320\276\320\262", nullptr));
        label_5->setText(QApplication::translate("Dialog", "\320\247\320\270\321\201\320\273\320\276\n"
"\321\201\320\276\321\202\321\200\321\203\320\264\320\275\320\270\320\272\320\276\320\262\n"
"\320\262 \320\272\320\260\320\266\320\264\320\276\320\271\n"
"\320\263\321\200\321\203\320\277\320\277\320\265", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Dialog: public Ui_Dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG_H
