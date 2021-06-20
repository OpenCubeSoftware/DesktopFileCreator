#include "previewdialog.h"
#include "ui_previewdialog.h"

PreviewDialog::PreviewDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PreviewDialog) {
    ui->setupUi(this);
}

PreviewDialog::PreviewDialog(QWidget *parent, QString input) {
    fileText = input;
}

void PreviewDialog::displayText() {
    ui->txtPreview->setPlainText(fileText);
}

PreviewDialog::~PreviewDialog() {
    delete ui;
}
