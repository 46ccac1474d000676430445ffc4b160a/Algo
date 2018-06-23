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

    connect(ui->tabWidget, &QTabWidget::currentChanged, this, &MainWindow::on_currentTabChanged);
    connect(ui->actionAdd_selected_to_dict, &QAction::triggered, this, &MainWindow::on_curentDocumentChanged);

    ui->actionClose_if_no_tabs->setChecked(true);
    ui->actionAdd_selected_to_dict->setDisabled(true);
    ui->actionCopy->setDisabled(true);
    ui->actionCut->setDisabled(true);
    ui->actionUndo->setDisabled(true);
    ui->actionRedo->setDisabled(true);
    ui->actionPaste->setDisabled(true);
    ui->actionDelete->setDisabled(true);
    ui->actionSelect_all->setDisabled(true);
    ui->actionSave->setDisabled(true);
    ui->actionShow_current_dict->setDisabled(Trie::obj().isEmpty());
    ui->actionClear_current_dict->setDisabled(Trie::obj().isEmpty());

    on_actionNew_file_triggered();
    on_curentDocumentChanged();
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

void MainWindow::on_actionSave(int index, bool newflname)
{
    if (ui->tabWidget->count() > 0)
    {
        TextEdit *textEdit = static_cast<TextEdit *>(ui->tabWidget->widget(index));

        if (textEdit->fileName().isEmpty() || newflname)
        {
            QString file = QFileDialog::getSaveFileName(this, "Open file", QDir::homePath());
            if (file.isEmpty()) return;

            textEdit->setFileName(file);
        }

        if (!textEdit->save(textEdit->fileName()))
        {
            QMessageBox::warning(this, "Open file", QString("Failed to save file: \"%1\"").arg(textEdit->fileName()));
        }
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
        ui->tabWidget->setCurrentWidget(0);
        on_tabWidget_tabCloseRequested(0);
    }
}

void MainWindow::on_actionSave_as_triggered()
{
    on_actionSave(ui->tabWidget->currentIndex(), true);
}

void MainWindow::on_actionNew_file_triggered()
{
    int index = ui->tabWidget->addTab(new TextEdit(), "Untilted");
    ui->tabWidget->setCurrentIndex(index);

    ui->actionSave_all->setEnabled(true);
    ui->actionSave_as->setEnabled(true);
    ui->actionClose->setEnabled(true);
    ui->actionClose_all->setEnabled(true);
}

void MainWindow::on_tabWidget_tabCloseRequested(int index)
{
    if (ui->tabWidget->count() > 0)
    {
        TextEdit *textEdit = static_cast<TextEdit *>(ui->tabWidget->widget(index));

        if (!textEdit->saved())
        {
            int ans = QMessageBox::question(this,
                                            "File save",
                                            QString("Save changes to file \"%1\" before closing?")
                                            .arg(
                                                textEdit->fileName().isEmpty()
                                                ?
                                                    ui->tabWidget->tabText(index)
                                                  :
                                                    textEdit->fileName()),
                                            QMessageBox::No,
                                            QMessageBox::Cancel,
                                            QMessageBox::Yes);

            if (ans == QMessageBox::Cancel) return;
            if (ans == QMessageBox::Yes) on_actionSave(index);
        }

        ui->tabWidget->removeTab(index);
        textEdit->deleteLater();

        if (ui->tabWidget->count() == 0)
        {
            if (ui->actionClose_if_no_tabs->isChecked()) close();
            else
            {
                ui->actionAdd_selected_to_dict->setDisabled(true);
                ui->actionCopy->setDisabled(true);
                ui->actionCut->setDisabled(true);
                ui->actionUndo->setDisabled(true);
                ui->actionRedo->setDisabled(true);
                ui->actionPaste->setDisabled(true);
                ui->actionDelete->setDisabled(true);
                ui->actionSelect_all->setDisabled(true);
                ui->actionSave->setDisabled(true);
                ui->actionSave_all->setDisabled(true);
                ui->actionSave_as->setDisabled(true);
                ui->actionClose->setDisabled(true);
                ui->actionClose_all->setDisabled(true);
            }
        }
    }
}

void MainWindow::on_currentTabChanged(int index)
{
    if (ui->tabWidget->count() > 0)
    {
        TextEdit *te;
        for (int i = 0; i < ui->tabWidget->count(); i++)
        {
            te = static_cast<TextEdit *>(ui->tabWidget->widget(i));
            disconnect(te, &TextEdit::selectionChanged,
                       this, &MainWindow::on_curentDocumentChanged);
            disconnect(te, &TextEdit::undoAvailable,
                       this, &MainWindow::on_undoEnable);
            disconnect(te, &TextEdit::redoAvailable,
                       this, &MainWindow::on_redoEnable);
            disconnect(te, &TextEdit::textChanged,
                       this, &MainWindow::on_curentDocumentTextChanged);
        }

        te = static_cast<TextEdit *>(ui->tabWidget->widget(index));
        connect(te, &TextEdit::selectionChanged,
                this, &MainWindow::on_curentDocumentChanged);
        connect(te, &TextEdit::undoAvailable,
                this, &MainWindow::on_undoEnable);
        connect(te, &TextEdit::redoAvailable,
                this, &MainWindow::on_redoEnable);
        connect(te, &TextEdit::textChanged,
                this, &MainWindow::on_curentDocumentTextChanged);
    }
}

void MainWindow::on_curentDocumentChanged()
{
    TextEdit *te = static_cast<TextEdit *>(ui->tabWidget->currentWidget());
    QTextCursor cursor = te->textCursor();

    bool selected = cursor.selectionStart() != cursor.selectionEnd();
    ui->actionAdd_selected_to_dict->setEnabled(selected);
    ui->actionCopy->setEnabled(selected);
    ui->actionCut->setEnabled(selected);
    ui->actionPaste->setEnabled(te->canPaste());
    ui->actionSave->setDisabled(te->saved());
    ui->actionShow_current_dict->setDisabled(Trie::obj().isEmpty());
}

void MainWindow::on_actionAdd_selected_to_dict_triggered()
{
    QString text = static_cast<TextEdit *>(ui->tabWidget->currentWidget())->textCursor().selectedText();
    if (!text.isEmpty()) Trie::obj().addWord(text);
    if (!Trie::obj().isEmpty())
    {
        ui->actionShow_current_dict->setEnabled(true);
        ui->actionClear_current_dict->setEnabled(true);
    }
}

void MainWindow::on_actionLoad_dict_from_file_triggered()
{
    QString filename = QFileDialog::getOpenFileName(this, "Open dictionary", QDir::currentPath());
    if (!filename.isEmpty())
    {
        QFile f(filename);
        if (f.open(QIODevice::ReadOnly))
        {
            QString dict(f.readAll());
            dict.remove('\r');
            Trie::obj() << dict.split('\n', QString::SkipEmptyParts);

            if (!Trie::obj().isEmpty())
            {
                ui->actionShow_current_dict->setEnabled(true);
                ui->actionClear_current_dict->setEnabled(true);
            }
        }
        else
        {
            QMessageBox::warning(this, "Open dictionary", QString("Dictionary, named \"%1\" not loaded!").arg(filename));
        }
    }
}

void MainWindow::on_actionShow_current_dict_triggered()
{
    if (Trie::obj().isEmpty())
    {
        QMessageBox::warning(this, "Open dictionary", "Dictionary is empty!");
    }
    else
    {
        QStringList dict = Trie::obj().words(QString());
        on_actionNew_file_triggered();
        TextEdit *te = static_cast<TextEdit *>(ui->tabWidget->currentWidget());
        ui->tabWidget->setTabText(ui->tabWidget->currentIndex(), "Dictionary");
        foreach (const QString &word, dict)
        {
            te->append(QString("<span>%1</span>").arg(word));
        }
    }
}

void MainWindow::on_undoEnable(bool enable)
{
    ui->actionUndo->setEnabled(enable);
}

void MainWindow::on_redoEnable(bool enable)
{
    ui->actionRedo->setEnabled(enable);
}

void MainWindow::on_actionClear_current_dict_triggered()
{
    if (!Trie::obj().isEmpty()
            &&
        QMessageBox::question(this, "Clear curent dictionary", "Are you sure want to clear curent dictionary?", QMessageBox::No, QMessageBox::Yes) == QMessageBox::Yes)
    {
        Trie::obj().clear();
        ui->actionShow_current_dict->setDisabled(true);
        ui->actionClear_current_dict->setDisabled(true);
    }
}

void MainWindow::on_curentDocumentTextChanged()
{
    ui->actionSave->setEnabled(true);
    ui->actionSelect_all->setDisabled(static_cast<TextEdit *>(ui->tabWidget->currentWidget())->toPlainText().isEmpty());
}
