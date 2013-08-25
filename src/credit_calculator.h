#ifndef CREDIT_CALCULATOR_H
#define CREDIT_CALCULATOR_H

#include <QDialog>

namespace Ui {
    class CreditCalculator;
}


class CreditCalculator : public QDialog
{
    Q_OBJECT
    
public:
    explicit CreditCalculator(QWidget *parent = 0);
    ~CreditCalculator();
    
private:
    Ui::CreditCalculator *ui;
};

#endif // CREDIT_CALCULATOR_H
