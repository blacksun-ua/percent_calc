#include "main_window.h"
#include "credit_calculator.h"
#include <QApplication>



int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //MainWindow w;
    //w.show();
    CreditCalculator c;
    c.show();
    
    return a.exec();
}
