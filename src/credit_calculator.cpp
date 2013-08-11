#include "credit_calculator.h"
#include "ui_credit_calculator.h"

CreditCalculator::CreditCalculator(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CreditCalculator)
{
    ui->setupUi(this);
}

CreditCalculator::~CreditCalculator()
{
    delete ui;
}
