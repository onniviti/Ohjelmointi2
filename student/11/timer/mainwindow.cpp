
#include "mainwindow.hh"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    timer(new QTimer(this)),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(on_timer_timeout()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_startButton_clicked()
{
    timer->start(100);
}

void MainWindow::on_stopButton_clicked()
{
    timer->stop();
}

void MainWindow::on_resetButton_clicked()
{
    ui->lcdNumberMin->display(0);
    ui->lcdNumberSec->display(0);
}

void MainWindow::on_timer_timeout()
{
    const auto mins = ui->lcdNumberMin->intValue();
    const auto secs = ui->lcdNumberSec->intValue();

    if (secs == 59)
    {
        ui->lcdNumberMin->display(mins + 1);
        ui->lcdNumberSec->display(0);
    }
    else
        ui->lcdNumberSec->display(secs + 1);
}
