#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QButtonGroup>
#include <QStyle>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow) {
    ui->setupUi(this);
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


void MainWindow::on_pushButton_clicked() {

}


void MainWindow::on_toolButton_clicked() {

}


void MainWindow::on_btnSaveFile_clicked() {

}

void MainWindow::on_btnIconFile_clicked() {

}
