#ifndef PREVIEWDIALOG_H
#define PREVIEWDIALOG_H

#include <QDialog>

namespace Ui {
class PreviewDialog;
}

class PreviewDialog : public QDialog {
    Q_OBJECT

public:
    explicit PreviewDialog(QWidget *parent = nullptr);
    explicit PreviewDialog(QWidget * parent = nullptr, QString input = "");
    void displayText();
    ~PreviewDialog();

private:
    Ui::PreviewDialog *ui;
    QString fileText;
};

#endif // PREVIEWDIALOG_H
