/********************************************************************************
** Form generated from reading UI file 'dictsettings.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DICTSETTINGS_H
#define UI_DICTSETTINGS_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>

QT_BEGIN_NAMESPACE

class Ui_DictSettings
{
public:

    void setupUi(QDialog *DictSettings)
    {
        if (DictSettings->objectName().isEmpty())
            DictSettings->setObjectName(QStringLiteral("DictSettings"));
        DictSettings->resize(400, 300);

        retranslateUi(DictSettings);

        QMetaObject::connectSlotsByName(DictSettings);
    } // setupUi

    void retranslateUi(QDialog *DictSettings)
    {
        DictSettings->setWindowTitle(QApplication::translate("DictSettings", "Dialog", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DictSettings: public Ui_DictSettings {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DICTSETTINGS_H
