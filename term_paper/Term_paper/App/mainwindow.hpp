#ifndef MAINWINDOW_HPP
#define MAINWINDOW_HPP

#include <QMainWindow>
#include <QDir>
#include <QFileDialog>
#include <QMessageBox>

#include <TextEdit/textedit.hpp>
#include "Trie/trie.hpp"

#include <QDebug>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_actionExit_triggered();

    void on_actionUndo_triggered();

    void on_actionRedo_triggered();

    void on_actionCopy_triggered();

    void on_actionCut_triggered();

    void on_actionPaste_triggered();

    void on_actionDelete_triggered();

    void on_actionSelect_all_triggered();

    void on_actionOpen_file_triggered();

    void on_actionSave_triggered();

    void on_actionSave(int index);

    void on_actionSave_all_triggered();

    void on_actionClose_triggered();

    void on_actionClose_all_triggered();

    void on_actionSave_as_triggered();

    void on_actionNew_file_triggered();

    void on_tabWidget_tabCloseRequested(int index);

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_HPP
