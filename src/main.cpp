#include "main_window.h"
#include "credit_calculator.h"
#include "credit_calculator_impl.h"
#include <QApplication>


int main(int argc, char *argv[])
{
    //QApplication a(argc, argv);
    //MainWindow w;
    //w.show();
    //CreditCalculator c;
    //c.show();
    //return a.exec();

    credit_calculator_impl calc(argc, argv);
    calc.eval();
    return 0;
}
