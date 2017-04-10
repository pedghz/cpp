#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QString>
#include <string>
#include <sstream>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    // connecting height spinbox to the calculator
    connect(ui->height_spinbox, SIGNAL(valueChanged(int)), this, SLOT(calculate_bmi()));
    // connecting weight spinbox to the calculator
    connect(ui->weight_spinbox, SIGNAL(valueChanged(int)), this, SLOT(calculate_bmi()));
    // connecting female action controller to the calculator
    connect(ui->actionFemale, SIGNAL(triggered(bool)), this, SLOT(calculate_bmi()));
    // connecting male action controller to the calculator
    connect(ui->actionMale, SIGNAL(triggered(bool)), this, SLOT(calculate_bmi()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

// Reseting the calculator
void MainWindow::on_actionReset_triggered()
{
    ui->interpretation_label->setText(QString::fromStdString("-"));
    ui->mass_label->setText(QString::fromStdString("-"));
    ui->actionFemale->setChecked(true);
    ui->actionMale->setChecked(false);
    ui->height_spinbox->setValue(0);
    ui->weight_spinbox->setValue(0);
}

// Closing window by action conroller
void MainWindow::on_actionQuit_triggered()
{
    this->close();
}

// Selectiong calculator for female BMI
void MainWindow::on_actionFemale_triggered()
{
    if(ui->actionMale->isChecked()) {
        ui->actionMale->setChecked(false);
        ui->actionFemale->setChecked(true);
        ui->gender_label->setText(QString::fromStdString("Female"));
    }
}

// Selectiong calculator for male BMI
void MainWindow::on_actionMale_triggered()
{
    if(ui->actionFemale->isChecked()) {
        ui->actionFemale->setChecked(false);
        ui->actionMale->setChecked(true);
        ui->gender_label->setText(QString::fromStdString("Male"));
    }
}

// Calculate BMI by gender
void MainWindow::calculate_bmi()
{
    float bmi;
    std::ostringstream bmi_tmp;
    std::string bmi_str;
    double weight = ui->weight_spinbox->value();
    double height_to_m = ui->height_spinbox->value();
    if (height_to_m != 0 && weight != 0) {
        bmi = 100*weight/height_to_m;
        bmi = 100*bmi/height_to_m;
        bmi_tmp << bmi;
        bmi_str = bmi_tmp.str();
        ui->mass_label->setText(QString::fromStdString(bmi_str));

        if (ui->actionMale->isChecked())
        {
            if (bmi <= 20.7)
                ui->interpretation_label->setText(QString::fromStdString("Underweight"));
            else if (bmi > 20.7 && bmi <= 26.4)
                ui->interpretation_label->setText(QString::fromStdString("Normal"));
            else if (bmi > 26.4 && bmi <= 27.8)
                ui->interpretation_label->setText(QString::fromStdString("Slight overweight"));
            else if (bmi > 27.8 && bmi <= 31.1)
                ui->interpretation_label->setText(QString::fromStdString("Overweight"));
            else if (bmi > 31.1)
                ui->interpretation_label->setText(QString::fromStdString("Much overweight"));
        }
        else if (ui->actionFemale->isChecked())
        {
            if (bmi <= 19.1)
                ui->interpretation_label->setText(QString::fromStdString("Underweight"));
            else if (bmi > 19.1 && bmi <= 25.8)
                ui->interpretation_label->setText(QString::fromStdString("Normal"));
            else if (bmi > 25.8 && bmi <= 27.3)
                ui->interpretation_label->setText(QString::fromStdString("Slight overweight"));
            else if (bmi > 27.3 && bmi <= 32.2)
                ui->interpretation_label->setText(QString::fromStdString("Overweight"));
            else if (bmi > 32.2)
                ui->interpretation_label->setText(QString::fromStdString("Much overweight"));
        }
    }
    // If height or weight is not set do not show anything.
    else
    {
        ui->interpretation_label->setText(QString::fromStdString("-"));
        ui->mass_label->setText(QString::fromStdString("-"));
    }
}
