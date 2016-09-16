#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "worker.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

public slots:
    void closing();
private slots:
    void on_pushButton_clicked();

    void on_lineEdit_returnPressed();

    void on_actionQuit_triggered();

    void on_stopButton_clicked();

private:
    Ui::MainWindow *ui;
    Worker worker;
    QString previousText = "";
};

#endif // MAINWINDOW_H
