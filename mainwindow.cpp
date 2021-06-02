#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QButtonGroup>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow) {
    ui->setupUi(this);
    QButtonGroup * buttonGroup = new QButtonGroup(this);
    buttonGroup->addButton(ui->rbTerminalTrue);
    buttonGroup->addButton(ui->rbTerminalFalse);
    buttonGroup->setExclusive(true);
}

MainWindow::~MainWindow() {
    delete ui;
}

