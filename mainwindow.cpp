#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "previewdialog.h"
#include <QButtonGroup>
#include <QStyle>
#include <QDebug>
#include <QFileDialog>
#include <QFile>
#include "aboutdialog.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow) {
    ui->setupUi(this);
    isIconSet = false;
    ui->rbTerminalFalse->setChecked(true);
    QButtonGroup * buttonGroup = new QButtonGroup(this);
    buttonGroup->addButton(ui->rbTerminalTrue);
    buttonGroup->addButton(ui->rbTerminalFalse);
    buttonGroup->setExclusive(true);
//    QVariant style = ui->btnIconFile->style();
//    ui->btnIconFile->setIcon();
}

MainWindow::~MainWindow() {
    delete ui;
}


void MainWindow::on_btnSaveFile_clicked() {
    bool terminal = ui->rbTerminalTrue->isChecked();
    fileCreator = FileCreator(ui->txtType->text(), ui->txtEncoding->text(), ui->txtName->text(), ui->txtComment->text(), ui->txtExec->text(), ui->txtIcon->text(), ui->txtCategories->text(), terminal);
    fileCreator.makeOutput();

    QString fileName = QFileDialog::getSaveFileName(this, "Save .desktop file");
    if (fileName.isEmpty())
        return;

    QFile desktopFile(fileName);

    if (!desktopFile.open(QIODevice::WriteOnly | QIODevice::Text))
        return;

    QTextStream output(&desktopFile);

    output << fileCreator.getOutput();
    desktopFile.close();
}


void MainWindow::on_btnIconFile_clicked(bool checked) {
    if (!isIconSet) {
        QString iconFile = QFileDialog::getOpenFileName(this, tr("Choose Icon"),"/home/$USERNAME", tr("Images (*.jpg *.png *.ico)"));
        if (iconFile != "") {
            isIconSet = true;
            ui->btnIconFile->setIcon(QIcon(":/images/process-stop.png"));
            ui->txtIcon->setText(iconFile);
            ui->txtIcon->setDisabled(true);
        }
    } else {
        isIconSet = false;
        ui->btnIconFile->setIcon(QIcon(":/images/document-open.png"));
        ui->txtIcon->setText("");
        ui->txtIcon->setEnabled(true);
    }
}


void MainWindow::on_btnClear_clicked() {
    ui->txtCategories->setText("");
    ui->txtCategories->setText("");
    ui->txtEncoding->setText("UTF-8");
    ui->txtExec->setText("");
    ui->txtIcon->setText("");
    ui->txtIcon->setEnabled(true);
    ui->btnIconFile->setIcon(QIcon(":/images/document-open.png"));
    ui->txtName->setText("");
    ui->txtType->setText("Application");
}




void MainWindow::on_actionAbout_desktop_File_Creator_triggered() {
    AboutDialog * dialog = new AboutDialog(this);
    dialog->exec();
}

