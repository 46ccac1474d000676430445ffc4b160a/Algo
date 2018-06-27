#ifndef MAINWINDOW_HPP
#define MAINWINDOW_HPP

#include <QMainWindow>
#include <QDir>
#include <QFileDialog>
#include <QMessageBox>
#include <QCloseEvent>

#include <TextEdit/textedit.hpp>
#include "Trie/trie.hpp"

#include <QDebug>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

    bool isDictSaved;
    QString lastDictPath;

protected:
    void closeEvent(QCloseEvent *event) override;

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

    void on_actionSave(int index, bool newflname = false);

    void on_actionSave_all_triggered();

    void on_actionClose_triggered();

    void on_actionClose_all_triggered();

    void on_actionSave_as_triggered();

    void on_actionNew_file_triggered();

    void on_tabWidget_tabCloseRequested(int index);

    void on_currentTabChanged(int index);

    void on_curentDocumentChanged();

    void on_actionAdd_selected_to_dict_triggered();

    void on_actionLoad_dict_from_file_triggered();

    void on_actionShow_current_dict_triggered();

    void on_undoEnable(bool enable);
    void on_redoEnable(bool enable);

    void on_actionClear_current_dict_triggered();

    void on_curentDocumentTextChanged();

    void on_actionSave_current_dict_triggered();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_HPP
