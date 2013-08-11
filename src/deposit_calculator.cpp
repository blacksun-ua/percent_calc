#include "deposit_calculator.h"
#include "ui_deposit_calculator.h"

DepositCalculator::DepositCalculator(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DepositCalculator)
{
    ui->setupUi(this);
}

DepositCalculator::~DepositCalculator()
{
    delete ui;
}
