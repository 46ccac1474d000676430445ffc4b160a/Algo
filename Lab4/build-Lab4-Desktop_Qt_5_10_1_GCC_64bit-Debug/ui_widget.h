/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QVBoxLayout *verticalLayout_3;
    QTabWidget *tabWidget;
    QWidget *tab;
    QVBoxLayout *verticalLayout_2;
    QGroupBox *requestform;
    QVBoxLayout *verticalLayout;
    QFormLayout *formLayout;
    QComboBox *cityInput;
    QComboBox *branchInput;
    QComboBox *departmentInput;
    QComboBox *groupInput;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QToolButton *searchFormData;
    QListWidget *listWidget;
    QWidget *tab_2;
    QVBoxLayout *verticalLayout_5;
    QGroupBox *requestform_2;
    QVBoxLayout *verticalLayout_4;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_5;
    QComboBox *nameInput;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer_2;
    QToolButton *searchFormData_2;
    QListWidget *listWidget_2;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QStringLiteral("Widget"));
        Widget->setWindowModality(Qt::NonModal);
        Widget->resize(530, 469);
        Widget->setMinimumSize(QSize(530, 400));
        verticalLayout_3 = new QVBoxLayout(Widget);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        tabWidget = new QTabWidget(Widget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        verticalLayout_2 = new QVBoxLayout(tab);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        requestform = new QGroupBox(tab);
        requestform->setObjectName(QStringLiteral("requestform"));
        verticalLayout = new QVBoxLayout(requestform);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        formLayout = new QFormLayout();
        formLayout->setSpacing(6);
        formLayout->setObjectName(QStringLiteral("formLayout"));
        cityInput = new QComboBox(requestform);
        cityInput->setObjectName(QStringLiteral("cityInput"));
        cityInput->setEditable(true);
        cityInput->setDuplicatesEnabled(false);

        formLayout->setWidget(1, QFormLayout::FieldRole, cityInput);

        branchInput = new QComboBox(requestform);
        branchInput->setObjectName(QStringLiteral("branchInput"));
        branchInput->setEditable(true);

        formLayout->setWidget(2, QFormLayout::FieldRole, branchInput);

        departmentInput = new QComboBox(requestform);
        departmentInput->setObjectName(QStringLiteral("departmentInput"));
        departmentInput->setEditable(true);

        formLayout->setWidget(3, QFormLayout::FieldRole, departmentInput);

        groupInput = new QComboBox(requestform);
        groupInput->setObjectName(QStringLiteral("groupInput"));
        groupInput->setEditable(true);

        formLayout->setWidget(4, QFormLayout::FieldRole, groupInput);

        label = new QLabel(requestform);
        label->setObjectName(QStringLiteral("label"));
        label->setMinimumSize(QSize(0, 0));

        formLayout->setWidget(1, QFormLayout::LabelRole, label);

        label_2 = new QLabel(requestform);
        label_2->setObjectName(QStringLiteral("label_2"));

        formLayout->setWidget(2, QFormLayout::LabelRole, label_2);

        label_3 = new QLabel(requestform);
        label_3->setObjectName(QStringLiteral("label_3"));

        formLayout->setWidget(3, QFormLayout::LabelRole, label_3);

        label_4 = new QLabel(requestform);
        label_4->setObjectName(QStringLiteral("label_4"));

        formLayout->setWidget(4, QFormLayout::LabelRole, label_4);


        verticalLayout->addLayout(formLayout);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        searchFormData = new QToolButton(requestform);
        searchFormData->setObjectName(QStringLiteral("searchFormData"));
        searchFormData->setIconSize(QSize(28, 28));
        searchFormData->setAutoRepeat(false);
        searchFormData->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
        searchFormData->setArrowType(Qt::NoArrow);

        horizontalLayout->addWidget(searchFormData);


        verticalLayout->addLayout(horizontalLayout);


        verticalLayout_2->addWidget(requestform);

        listWidget = new QListWidget(tab);
        listWidget->setObjectName(QStringLiteral("listWidget"));
        listWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
        listWidget->setDefaultDropAction(Qt::CopyAction);
        listWidget->setMovement(QListView::Static);
        listWidget->setSpacing(0);
        listWidget->setSortingEnabled(false);

        verticalLayout_2->addWidget(listWidget);

        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        verticalLayout_5 = new QVBoxLayout(tab_2);
        verticalLayout_5->setSpacing(6);
        verticalLayout_5->setContentsMargins(11, 11, 11, 11);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        requestform_2 = new QGroupBox(tab_2);
        requestform_2->setObjectName(QStringLiteral("requestform_2"));
        verticalLayout_4 = new QVBoxLayout(requestform_2);
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setContentsMargins(11, 11, 11, 11);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        label_5 = new QLabel(requestform_2);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setMinimumSize(QSize(0, 0));
        label_5->setMaximumSize(QSize(140, 16777215));

        horizontalLayout_3->addWidget(label_5);

        nameInput = new QComboBox(requestform_2);
        nameInput->setObjectName(QStringLiteral("nameInput"));
        nameInput->setMinimumSize(QSize(0, 0));
        nameInput->setEditable(true);

        horizontalLayout_3->addWidget(nameInput);


        verticalLayout_4->addLayout(horizontalLayout_3);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);

        searchFormData_2 = new QToolButton(requestform_2);
        searchFormData_2->setObjectName(QStringLiteral("searchFormData_2"));
        searchFormData_2->setIconSize(QSize(28, 28));
        searchFormData_2->setAutoRepeat(false);
        searchFormData_2->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
        searchFormData_2->setArrowType(Qt::NoArrow);

        horizontalLayout_2->addWidget(searchFormData_2);


        verticalLayout_4->addLayout(horizontalLayout_2);

        listWidget_2 = new QListWidget(requestform_2);
        listWidget_2->setObjectName(QStringLiteral("listWidget_2"));

        verticalLayout_4->addWidget(listWidget_2);


        verticalLayout_5->addWidget(requestform_2);

        tabWidget->addTab(tab_2, QString());

        verticalLayout_3->addWidget(tabWidget);


        retranslateUi(Widget);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QApplication::translate("Widget", "\320\233\320\260\320\261\320\276\321\200\320\260\321\202\320\276\321\200\320\275\320\260\321\217 \321\200\320\260\320\261\320\276\321\202\320\260 4 - \321\205\320\265\321\210-\321\202\320\260\320\261\320\273\320\270\321\206\321\213", nullptr));
        requestform->setTitle(QApplication::translate("Widget", "\320\244\320\276\321\200\320\274\320\260 \320\267\320\260\320\277\321\200\320\276\321\201\320\260", nullptr));
#ifndef QT_NO_TOOLTIP
        cityInput->setToolTip(QApplication::translate("Widget", "\320\223\320\276\321\200\320\276\320\264", nullptr));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_TOOLTIP
        branchInput->setToolTip(QApplication::translate("Widget", "\320\244\320\270\320\273\320\270\320\260\320\273", nullptr));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_TOOLTIP
        departmentInput->setToolTip(QApplication::translate("Widget", "\320\236\321\202\320\264\320\265\320\273", nullptr));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_TOOLTIP
        groupInput->setToolTip(QApplication::translate("Widget", "\320\223\321\200\321\203\320\277\320\277\320\260", nullptr));
#endif // QT_NO_TOOLTIP
        label->setText(QApplication::translate("Widget", "\320\223\320\276\321\200\320\276\320\264:", nullptr));
        label_2->setText(QApplication::translate("Widget", "\320\244\320\270\320\273\320\270\320\260\320\273:", nullptr));
        label_3->setText(QApplication::translate("Widget", "\320\236\321\202\320\264\320\265\320\273:", nullptr));
        label_4->setText(QApplication::translate("Widget", "\320\223\321\200\321\203\320\277\320\277\320\260:", nullptr));
        searchFormData->setText(QApplication::translate("Widget", "\320\237\320\276\320\270\321\201\320\272", nullptr));
#ifndef QT_NO_TOOLTIP
        listWidget->setToolTip(QApplication::translate("Widget", "\320\224\320\273\321\217 \320\272\320\276\320\277\320\270\321\200\320\276\320\262\320\260\320\275\320\270\321\217 \321\202\320\265\320\272\321\201\321\202\320\260 \320\272\320\273\320\270\320\272\320\275\320\270\321\202\320\265 \320\277\320\276 \321\215\320\273\320\265\320\274\320\265\320\275\321\202\321\203 \320\264\320\262\320\260\320\266\320\264\321\213", nullptr));
#endif // QT_NO_TOOLTIP
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("Widget", "\320\227\320\260\320\277\321\200\320\276\321\201 \320\277\320\276 \320\270\320\265\321\200\320\260\321\200\321\205\320\270\320\270 \320\276\321\200\320\263\320\260\320\275\320\270\320\267\320\260\321\206\320\270\320\270", nullptr));
        requestform_2->setTitle(QApplication::translate("Widget", "\320\244\320\276\321\200\320\274\320\260 \320\267\320\260\320\277\321\200\320\276\321\201\320\260", nullptr));
        label_5->setText(QApplication::translate("Widget", "\320\230\320\274\321\217 \321\201\320\276\321\202\321\200\321\203\320\264\320\275\320\270\320\272\320\260:", nullptr));
        searchFormData_2->setText(QApplication::translate("Widget", "\320\237\320\276\320\270\321\201\320\272", nullptr));
#ifndef QT_NO_TOOLTIP
        listWidget_2->setToolTip(QApplication::translate("Widget", "\320\224\320\273\321\217 \320\272\320\276\320\277\320\270\321\200\320\276\320\262\320\260\320\275\320\270\321\217 \321\202\320\265\320\272\321\201\321\202\320\260 \320\272\320\273\320\270\320\272\320\275\320\270\321\202\320\265 \320\277\320\276 \321\215\320\273\320\265\320\274\320\265\320\275\321\202\321\203 \320\264\320\262\320\260\320\266\320\264\321\213", nullptr));
#endif // QT_NO_TOOLTIP
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("Widget", "\320\227\320\260\320\277\321\200\320\276\321\201 \320\277\320\276 \320\270\320\274\320\265\320\275\320\270 \321\201\320\276\321\202\321\200\321\203\320\264\320\275\320\270\320\272\320\260", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
