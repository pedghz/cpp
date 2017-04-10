#include "mainwindow.h"
#include "ui_mainwindow.h"

Mainwindow::Mainwindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Mainwindow)
{
    ui->setupUi(this);
    connect(ui->clearButton, SIGNAL(clicked(bool)), this, SLOT(clear_button_clicked()));
    connect(ui->spinBox, SIGNAL(valueChanged(int)), this, SLOT(calculate_miles()));
}

Mainwindow::~Mainwindow()
{
    delete ui;
}

void Mainwindow::clear_button_clicked()
{
    ui->spinBox->setValue(0);
    ui->lcdNumber->display(0.0);
}

void Mainwindow::calculate_miles()
{
    double miles = ui->spinBox->value() / 1.609;
    ui->lcdNumber->display(miles);
}
