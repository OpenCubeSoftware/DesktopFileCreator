#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "filecreator.h"
#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_btnSaveFile_clicked();
    void on_btnIconFile_clicked(bool checked);

    void on_btnClear_clicked();

    void on_actionAbout_desktop_File_Creator_triggered();

private:
    Ui::MainWindow *ui;
    FileCreator fileCreator;
    bool isIconSet;
};
#endif // MAINWINDOW_H
