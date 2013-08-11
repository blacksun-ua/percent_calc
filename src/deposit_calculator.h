#ifndef DEPOSIT_CALCULATOR_H
#define DEPOSIT_CALCULATOR_H

#include <QDialog>

namespace Ui {
class DepositCalculator;
}

class DepositCalculator : public QDialog
{
    Q_OBJECT
    
public:
    explicit DepositCalculator(QWidget *parent = 0);
    ~DepositCalculator();
    
private:
    Ui::DepositCalculator *ui;
};

#endif // DEPOSIT_CALCULATOR_H
