#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtCore>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    // Read text.
    QString text = ui->lineEdit->text();
    QString number = text.remove(QRegExp("[^\\d]"));
    // Compare to previousText
    if (previousText == text)
    {
        ui->label->setText(QString::number(worker.getInput()));
        if (!worker.isRunning())
        {
            worker.start();
        }
    }
    else
    {
        if (worker.isRunning())
        {
            worker.stop();
        }
        worker.setInput(number.toInt());
        ui->label->setText(number);
        worker.start();
    }
    previousText = text;
}

void MainWindow::on_lineEdit_returnPressed()
{
    on_pushButton_clicked();
}

void MainWindow::on_actionQuit_triggered()
{
    ui->label->setText("Quitting");
    QApplication::quit();
}

void MainWindow::closing()
{
    worker.stop();
}

void MainWindow::on_stopButton_clicked()
{
    worker.stop();
}
