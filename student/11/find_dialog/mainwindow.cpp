#include "mainwindow.hh"
#include <fstream>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
}
void MainWindow::on_findPushButton_clicked()
{
    const auto match_case = ui.matchCheckBox->isChecked();

    std::ifstream file_obj(file_name_);
    if (!file_obj)
    {
        ui.textBrowser->setText(QString("File not found"));
        return;
    }
    if (needle_.empty())
    {
        ui.textBrowser->setText(QString("File found"));
        return;
    }

    std::string line;
    while (std::getline(file_obj, line))
    {
        if (match_case)
        {
            if (line.find(needle_) != std::string::npos)
            {
                ui.textBrowser->setText(QString("Word found"));
                return;
            }
        }
        else
        {
            auto needle = needle_;
            std::transform(needle.begin(), needle.end(), needle.begin(), tolower);
            std::transform(line.begin(), line.end(), line.begin(), tolower);

            if (line.find(needle) != std::string::npos)
            {
                ui.textBrowser->setText(QString("Word found"));
                return;
            }
        }

    }

    ui.textBrowser->setText(QString("Word not found"));
}

void MainWindow::on_fileLineEdit_editingFinished()
{
    file_name_ = ui.fileLineEdit->text().toStdString();
}

void MainWindow::on_keyLineEdit_editingFinished()
{
    needle_ = ui.keyLineEdit->text().toStdString();
}
