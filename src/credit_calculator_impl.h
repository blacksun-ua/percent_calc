#ifndef CREDIT_CALCULATOR_IMPL_H
#define CREDIT_CALCULATOR_IMPL_H

#include "money.h"

struct calc_line {
    int month_number;
    int remain;
    int body_payment;
    int percent_payment;
};

class credit_calculator_impl
{
public:
    credit_calculator_impl();
    credit_calculator_impl(int argc, char* argv[]);
    void message(const char* pn = "credit_calculator");
    void eval();

private:
    int period_;
    double percent_;
    double sum_;
    bool type_;
};

#endif // CREDIT_CALCULATOR_IMPL_H
