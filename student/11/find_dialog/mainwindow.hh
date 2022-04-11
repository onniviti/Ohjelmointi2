#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_mainwindow.h"

class MainWindow: public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = Q_NULLPTR);

private slots:
    void on_findPushButton_clicked();

    void on_keyLineEdit_editingFinished();

    void on_fileLineEdit_editingFinished();

private:
    Ui::MainWindow ui;
    std::string file_name_;
    std::string needle_;
};
