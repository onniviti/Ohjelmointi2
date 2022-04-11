#include "mainwindow.hh"
#include <cmath>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);

    connect(ui.countButton, SIGNAL(clicked()), this, SLOT(count_clicked()));
}

void MainWindow::count_clicked()
{
    const auto weight = std::stoi(ui.weightLineEdit->text().toStdString());
    const auto height = std::stoi(ui.heightLineEdit->text().toStdString());

    const auto bmi = weight / pow(height/100.0, 2);

    ui.resultLabel->setNum(bmi);

    if (bmi < 18.5)
        ui.infoTextBrowser->setText(QString("You are underweight."));
    else if (bmi > 25)
        ui.infoTextBrowser->setText(QString("You are overweight."));
    else
        ui.infoTextBrowser->setText(QString("Your weight is normal."));
}

