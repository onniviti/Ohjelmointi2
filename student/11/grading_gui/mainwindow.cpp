#include "mainwindow.hh"
#include "ui_mainwindow.h"
#include "gradecounter.hh"
#include <fstream>
#include <string>
#include <QString>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_spinBoxN_valueChanged(int arg1)
{
    this->N_points = arg1;
}


void MainWindow::on_spinBoxG_valueChanged(int arg1)
{
    this->G_points = arg1;
}


void MainWindow::on_spinBoxP_valueChanged(int arg1)
{
    this->P_points = arg1;
}


void MainWindow::on_spinBoxE_valueChanged(int arg1)
{
    this->E_points = arg1;
}


void MainWindow::on_countPushButton_clicked()
{
    std::string final_grade = std::to_string(count_final_grade(N_points, G_points, P_points, E_points));
    QString qstr = QString::fromStdString(final_grade);
    ui->textBrowser->setText(qstr);

}

