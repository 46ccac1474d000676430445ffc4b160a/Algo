/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionExit;
    QAction *actionUndo;
    QAction *actionRedo;
    QAction *actionCopy;
    QAction *actionCut;
    QAction *actionPaste;
    QAction *actionDelete;
    QAction *actionSelect_all;
    QAction *actionOpen_file;
    QAction *actionSave;
    QAction *actionSave_all;
    QAction *actionClose;
    QAction *actionClose_all;
    QAction *actionSave_as;
    QAction *actionNew_file;
    QAction *actionClose_if_no_tabs;
    QAction *actionLoad_dict_from_file;
    QAction *actionShow_current_dict;
    QAction *actionAdd_selected_to_dict;
    QAction *actionClear_current_dict;
    QAction *actionSave_current_dict;
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout;
    QTabWidget *tabWidget;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QMenu *menuEdit;
    QMenu *menuOptions;
    QMenu *menuText_compliting;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(640, 480);
        actionExit = new QAction(MainWindow);
        actionExit->setObjectName(QStringLiteral("actionExit"));
        actionUndo = new QAction(MainWindow);
        actionUndo->setObjectName(QStringLiteral("actionUndo"));
        actionRedo = new QAction(MainWindow);
        actionRedo->setObjectName(QStringLiteral("actionRedo"));
        actionCopy = new QAction(MainWindow);
        actionCopy->setObjectName(QStringLiteral("actionCopy"));
        actionCut = new QAction(MainWindow);
        actionCut->setObjectName(QStringLiteral("actionCut"));
        actionPaste = new QAction(MainWindow);
        actionPaste->setObjectName(QStringLiteral("actionPaste"));
        actionDelete = new QAction(MainWindow);
        actionDelete->setObjectName(QStringLiteral("actionDelete"));
        actionSelect_all = new QAction(MainWindow);
        actionSelect_all->setObjectName(QStringLiteral("actionSelect_all"));
        actionOpen_file = new QAction(MainWindow);
        actionOpen_file->setObjectName(QStringLiteral("actionOpen_file"));
        actionSave = new QAction(MainWindow);
        actionSave->setObjectName(QStringLiteral("actionSave"));
        actionSave_all = new QAction(MainWindow);
        actionSave_all->setObjectName(QStringLiteral("actionSave_all"));
        actionClose = new QAction(MainWindow);
        actionClose->setObjectName(QStringLiteral("actionClose"));
        actionClose_all = new QAction(MainWindow);
        actionClose_all->setObjectName(QStringLiteral("actionClose_all"));
        actionSave_as = new QAction(MainWindow);
        actionSave_as->setObjectName(QStringLiteral("actionSave_as"));
        actionNew_file = new QAction(MainWindow);
        actionNew_file->setObjectName(QStringLiteral("actionNew_file"));
        actionClose_if_no_tabs = new QAction(MainWindow);
        actionClose_if_no_tabs->setObjectName(QStringLiteral("actionClose_if_no_tabs"));
        actionClose_if_no_tabs->setCheckable(true);
        actionLoad_dict_from_file = new QAction(MainWindow);
        actionLoad_dict_from_file->setObjectName(QStringLiteral("actionLoad_dict_from_file"));
        actionShow_current_dict = new QAction(MainWindow);
        actionShow_current_dict->setObjectName(QStringLiteral("actionShow_current_dict"));
        actionAdd_selected_to_dict = new QAction(MainWindow);
        actionAdd_selected_to_dict->setObjectName(QStringLiteral("actionAdd_selected_to_dict"));
        actionClear_current_dict = new QAction(MainWindow);
        actionClear_current_dict->setObjectName(QStringLiteral("actionClear_current_dict"));
        actionSave_current_dict = new QAction(MainWindow);
        actionSave_current_dict->setObjectName(QStringLiteral("actionSave_current_dict"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        verticalLayout = new QVBoxLayout(centralWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setDocumentMode(false);
        tabWidget->setTabsClosable(true);
        tabWidget->setMovable(true);

        verticalLayout->addWidget(tabWidget);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 640, 26));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QStringLiteral("menuFile"));
        menuEdit = new QMenu(menuBar);
        menuEdit->setObjectName(QStringLiteral("menuEdit"));
        menuOptions = new QMenu(menuBar);
        menuOptions->setObjectName(QStringLiteral("menuOptions"));
        menuText_compliting = new QMenu(menuBar);
        menuText_compliting->setObjectName(QStringLiteral("menuText_compliting"));
        MainWindow->setMenuBar(menuBar);

        menuBar->addAction(menuFile->menuAction());
        menuBar->addAction(menuEdit->menuAction());
        menuBar->addAction(menuOptions->menuAction());
        menuBar->addAction(menuText_compliting->menuAction());
        menuFile->addAction(actionNew_file);
        menuFile->addAction(actionOpen_file);
        menuFile->addSeparator();
        menuFile->addAction(actionSave);
        menuFile->addAction(actionSave_as);
        menuFile->addAction(actionSave_all);
        menuFile->addSeparator();
        menuFile->addAction(actionClose);
        menuFile->addAction(actionClose_all);
        menuFile->addSeparator();
        menuFile->addAction(actionExit);
        menuEdit->addAction(actionUndo);
        menuEdit->addAction(actionRedo);
        menuEdit->addSeparator();
        menuEdit->addAction(actionCopy);
        menuEdit->addAction(actionCut);
        menuEdit->addAction(actionPaste);
        menuEdit->addAction(actionDelete);
        menuEdit->addSeparator();
        menuEdit->addAction(actionSelect_all);
        menuOptions->addAction(actionClose_if_no_tabs);
        menuText_compliting->addAction(actionLoad_dict_from_file);
        menuText_compliting->addAction(actionSave_current_dict);
        menuText_compliting->addAction(actionShow_current_dict);
        menuText_compliting->addAction(actionClear_current_dict);
        menuText_compliting->addSeparator();
        menuText_compliting->addAction(actionAdd_selected_to_dict);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(-1);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        actionExit->setText(QApplication::translate("MainWindow", "Exit", nullptr));
#ifndef QT_NO_SHORTCUT
        actionExit->setShortcut(QApplication::translate("MainWindow", "Ctrl+Q", nullptr));
#endif // QT_NO_SHORTCUT
        actionUndo->setText(QApplication::translate("MainWindow", "Undo", nullptr));
#ifndef QT_NO_SHORTCUT
        actionUndo->setShortcut(QApplication::translate("MainWindow", "Ctrl+Z", nullptr));
#endif // QT_NO_SHORTCUT
        actionRedo->setText(QApplication::translate("MainWindow", "Redo", nullptr));
#ifndef QT_NO_SHORTCUT
        actionRedo->setShortcut(QApplication::translate("MainWindow", "Ctrl+Y", nullptr));
#endif // QT_NO_SHORTCUT
        actionCopy->setText(QApplication::translate("MainWindow", "Copy", nullptr));
#ifndef QT_NO_SHORTCUT
        actionCopy->setShortcut(QApplication::translate("MainWindow", "Ctrl+C", nullptr));
#endif // QT_NO_SHORTCUT
        actionCut->setText(QApplication::translate("MainWindow", "Cut", nullptr));
#ifndef QT_NO_SHORTCUT
        actionCut->setShortcut(QApplication::translate("MainWindow", "Ctrl+X", nullptr));
#endif // QT_NO_SHORTCUT
        actionPaste->setText(QApplication::translate("MainWindow", "Paste", nullptr));
#ifndef QT_NO_SHORTCUT
        actionPaste->setShortcut(QApplication::translate("MainWindow", "Ctrl+V", nullptr));
#endif // QT_NO_SHORTCUT
        actionDelete->setText(QApplication::translate("MainWindow", "Delete", nullptr));
#ifndef QT_NO_SHORTCUT
        actionDelete->setShortcut(QApplication::translate("MainWindow", "Del", nullptr));
#endif // QT_NO_SHORTCUT
        actionSelect_all->setText(QApplication::translate("MainWindow", "Select all", nullptr));
#ifndef QT_NO_SHORTCUT
        actionSelect_all->setShortcut(QApplication::translate("MainWindow", "Ctrl+A", nullptr));
#endif // QT_NO_SHORTCUT
        actionOpen_file->setText(QApplication::translate("MainWindow", "Open file...", nullptr));
#ifndef QT_NO_SHORTCUT
        actionOpen_file->setShortcut(QApplication::translate("MainWindow", "Ctrl+O", nullptr));
#endif // QT_NO_SHORTCUT
        actionSave->setText(QApplication::translate("MainWindow", "Save", nullptr));
#ifndef QT_NO_SHORTCUT
        actionSave->setShortcut(QApplication::translate("MainWindow", "Ctrl+S", nullptr));
#endif // QT_NO_SHORTCUT
        actionSave_all->setText(QApplication::translate("MainWindow", "Save all", nullptr));
#ifndef QT_NO_SHORTCUT
        actionSave_all->setShortcut(QApplication::translate("MainWindow", "Ctrl+Shift+S", nullptr));
#endif // QT_NO_SHORTCUT
        actionClose->setText(QApplication::translate("MainWindow", "Close", nullptr));
#ifndef QT_NO_SHORTCUT
        actionClose->setShortcut(QApplication::translate("MainWindow", "Ctrl+W", nullptr));
#endif // QT_NO_SHORTCUT
        actionClose_all->setText(QApplication::translate("MainWindow", "Close all", nullptr));
        actionSave_as->setText(QApplication::translate("MainWindow", "Save as...", nullptr));
        actionNew_file->setText(QApplication::translate("MainWindow", "New file", nullptr));
#ifndef QT_NO_SHORTCUT
        actionNew_file->setShortcut(QApplication::translate("MainWindow", "Ctrl+N", nullptr));
#endif // QT_NO_SHORTCUT
        actionClose_if_no_tabs->setText(QApplication::translate("MainWindow", "Close if no tabs", nullptr));
        actionLoad_dict_from_file->setText(QApplication::translate("MainWindow", "Load dictionary from file", nullptr));
        actionShow_current_dict->setText(QApplication::translate("MainWindow", "Show current dictionary", nullptr));
        actionAdd_selected_to_dict->setText(QApplication::translate("MainWindow", "Add selected to dictionary", nullptr));
#ifndef QT_NO_SHORTCUT
        actionAdd_selected_to_dict->setShortcut(QApplication::translate("MainWindow", "Ctrl+Shift+D", nullptr));
#endif // QT_NO_SHORTCUT
        actionClear_current_dict->setText(QApplication::translate("MainWindow", "Clear current dictionary", nullptr));
        actionSave_current_dict->setText(QApplication::translate("MainWindow", "Save current dictionary", nullptr));
        menuFile->setTitle(QApplication::translate("MainWindow", "File", nullptr));
        menuEdit->setTitle(QApplication::translate("MainWindow", "Edit", nullptr));
        menuOptions->setTitle(QApplication::translate("MainWindow", "Options", nullptr));
        menuText_compliting->setTitle(QApplication::translate("MainWindow", "Text compliting", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
