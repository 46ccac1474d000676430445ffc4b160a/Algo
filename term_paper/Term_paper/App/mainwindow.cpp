#include "mainwindow.hpp"
#include "ui_mainwindow.h"

void MainWindow::closeEvent(QCloseEvent *event)
{
    if ( (ui->tabWidget->count() == 0 && ui->actionClose_if_no_tabs->isChecked()) ||
         QMessageBox::question(this, "Close", "Want to close?") == QMessageBox::Yes)
    {
        on_actionClose_all_triggered();

        QMainWindow::closeEvent(event);
    }
    else event->ignore();
}

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QFile f(QDir::currentPath()+"/dict.txt");
    if (f.open(QIODevice::ReadOnly))
    {
        QString buf(f.readAll());
        buf.remove('\r');
        QStringList list = buf.split('\n', QString::SkipEmptyParts);
        f.close();

        foreach (auto val, list)
        {
            Trie::obj() << val;
        }
    }
    else qDebug() << "dict.txt not open";

    ui->actionClose_if_no_tabs->setChecked(true);
    ui->tabWidget->addTab(new TextEdit(), "Untilted");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionExit_triggered()
{
    close();
}

void MainWindow::on_actionUndo_triggered()
{
    static_cast<TextEdit *>(ui->tabWidget->currentWidget())->undo();
}

void MainWindow::on_actionRedo_triggered()
{
    static_cast<TextEdit *>(ui->tabWidget->currentWidget())->redo();
}

void MainWindow::on_actionCopy_triggered()
{
    static_cast<TextEdit *>(ui->tabWidget->currentWidget())->copy();
}

void MainWindow::on_actionCut_triggered()
{
    static_cast<TextEdit *>(ui->tabWidget->currentWidget())->cut();
}

void MainWindow::on_actionPaste_triggered()
{
    static_cast<TextEdit *>(ui->tabWidget->currentWidget())->paste();
}

void MainWindow::on_actionDelete_triggered()
{
    static_cast<TextEdit *>(ui->tabWidget->currentWidget())->textCursor().removeSelectedText();
}

void MainWindow::on_actionSelect_all_triggered()
{
    static_cast<TextEdit *>(ui->tabWidget->currentWidget())->selectAll();
}

void MainWindow::on_actionOpen_file_triggered()
{
    QString file = QFileDialog::getOpenFileName(this, "Open file", QDir::homePath());

    if (file.isEmpty()) return;

    TextEdit *textEdit;

    if (ui->tabWidget->count() == 0)
    {
        textEdit = new TextEdit();
        ui->tabWidget->addTab(textEdit, "Untilted");
    }
    else
    {
        textEdit = static_cast<TextEdit *>(ui->tabWidget->currentWidget());
    }

    if (!textEdit->toPlainText().isEmpty() || !textEdit->fileName().isEmpty())
    {
        textEdit = new TextEdit();
        ui->tabWidget->addTab(textEdit, QFileInfo(file).fileName());
    }

    if (textEdit->open(file))
    {
        ui->tabWidget->setTabText( ui->tabWidget->indexOf(textEdit), QFileInfo(file).fileName());
    }
    else
    {
        QMessageBox::warning(this, "Open file", QString("Failed to open file: \"%1\"").arg(file));
    }
}

void MainWindow::on_actionSave_triggered()
{
    on_actionSave(ui->tabWidget->currentIndex());
}

void MainWindow::on_actionSave(int index)
{
    QString file = QFileDialog::getOpenFileName(this, "Open file", QDir::homePath());
    if (file.isEmpty()) return;

    TextEdit *textEdit = static_cast<TextEdit *>(ui->tabWidget->widget(index));

    if (textEdit->fileName().isEmpty())
    {
        textEdit->setFileName(file);
        if (textEdit->fileName().isEmpty()) return;
    }

    if (!textEdit->save())
    {
        QMessageBox::warning(this, "Open file", QString("Failed to save file: \"%1\"").arg(textEdit->fileName()));
    }
}

void MainWindow::on_actionSave_all_triggered()
{
    for (int i = 0; i < ui->tabWidget->count(); i++)
    {
        TextEdit *textEdit = static_cast<TextEdit *>(ui->tabWidget->widget(i));
        if (!textEdit->saved())
        {
            on_actionSave(i);
        }
    }
}

void MainWindow::on_actionClose_triggered()
{
    on_tabWidget_tabCloseRequested(ui->tabWidget->currentIndex());
}

void MainWindow::on_actionClose_all_triggered()
{
    int n = ui->tabWidget->count();
    while(n--)
    {
        on_tabWidget_tabCloseRequested(0);
    }
}

void MainWindow::on_actionSave_as_triggered()
{
    on_actionSave(ui->tabWidget->currentIndex());
}

void MainWindow::on_actionNew_file_triggered()
{
    ui->tabWidget->addTab(new TextEdit(), "Untilted");
}

void MainWindow::on_tabWidget_tabCloseRequested(int index)
{
    TextEdit *textEdit = static_cast<TextEdit *>(ui->tabWidget->widget(index));

    if (!textEdit->saved())
    {
        int ans = QMessageBox::question(this, "File save", QString("Save changes to file before closing?"),
                                        QMessageBox::No,
                                        QMessageBox::Cancel,
                                        QMessageBox::Yes);

        if (ans == QMessageBox::Cancel) return;
        if (ans == QMessageBox::Yes) on_actionSave(index);
        if (ans == QMessageBox::No || textEdit->saved())
        {
            ui->tabWidget->removeTab(index);
            textEdit->deleteLater();
        }
    }

    if (ui->tabWidget->count() == 0 && ui->actionClose_if_no_tabs->isChecked()) close();
}

void MainWindow::on_actionDictionary_triggered()
{

}
