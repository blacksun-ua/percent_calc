#include "credit_calculator_impl.h"
#include <iostream>
#include <vector>
#include <boost/lexical_cast.hpp>


credit_calculator_impl::credit_calculator_impl()
{
}

credit_calculator_impl::credit_calculator_impl(int argc, char *argv[])
{
    if(argc < 4 || argv[1] == std::string("--help"))
        argc == 2 ? this->message(argv[1]) : this->message();
    else {
        period_ = boost::lexical_cast<int>(argv[1]);
        percent_ = boost::lexical_cast<int>(argv[2]);
        sum_ = boost::lexical_cast<int>(argv[3]);
        type_ = argc == 5 ? boost::lexical_cast<bool>(argv[4]) : 0;
    }
}

void credit_calculator_impl::message(const char* pn)
{
    std::cout << "credit calculator v 0.0.1\n";
    std::cout << "usage: " << pn << " period " << " percent " << " sum\n";
    std::cout << std::endl;
}

void credit_calculator_impl::eval()
{
    typedef std::vector<calc_line> calc_result;
    calc_result result;

    if(type_ == false) { // Classic
        std::cout << "Classic\n";
        std::cout << "Period \tLeaf \tBody \tPercent \tTotal\n";
        double sum_per_month = sum_ / period_;
        double percent_per_month = percent_ / 12;

        for(int i = 1; i <= period_; ++i) {
            calc_line cl;
            cl.month_number = i;
            cl.body_payment = sum_per_month;
            cl.remain = sum_ - cl.body_payment * i;
            cl.percent_payment = cl.remain * percent_per_month / 100;
            result.push_back(cl);
        }
    } else { // Annuitet
        std::cout << "Annuitet\n";
        std::cout << "Period \tLeaf \tBody \tPercent \tTotal\n";
        double ppm = percent_ / 12 / 100;
        double spm = sum_ * ((ppm * pow(1 + ppm, period_)) / (pow(1 + ppm, period_) - 1));
        int sum = sum_;

        for(int i = 1; i <= period_; ++i) {
            calc_line cl;
            cl.month_number = i;
            cl.percent_payment = sum * ppm;
            cl.body_payment = spm - cl.percent_payment;
            cl.remain = sum - cl.body_payment;
            sum -= cl.body_payment;
            result.push_back(cl);
        }
    }

    int total_percent = 0, total_payment = 0;
    for(calc_result::const_iterator iter = result.begin(), end = result.end(); iter != end; ++iter) {
        std::cout << iter->month_number << "\t" << iter->remain << "\t" << iter->body_payment << "\t" << iter->percent_payment << "\t\t" << iter->percent_payment + iter->body_payment << "\n";
        total_percent += iter->percent_payment;
        total_payment += iter->body_payment + iter->percent_payment;
    }

    std::cout << "Total: \t\t\t" << total_percent << "\t\t" << total_payment << "\n";
    std::cout << std::endl;
}
