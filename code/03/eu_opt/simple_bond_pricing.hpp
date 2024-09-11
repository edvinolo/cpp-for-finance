#ifndef simple_bond_pricing_hpp
#define simple_bond_pricing_hpp

#include <vector>
#include <math.h>
#include <cassert>

namespace Chapter3CPPBook
{
    typedef std::vector<double> Vector;

    //Function to calculate power of a number
    double power(double d, long n);

    //Future value of a sum of money invested today
    double future_value(double P_0, unsigned long n_periods, double r);

    //Future value of a sum of money invested today, m periods per year. r is annual interest rate
    double future_value(double P_0, unsigned long n_periods, double r, unsigned long m);

    //Continuous compounding, i.e. limit as m->infinity
    double future_value_continuous(double P_0, unsigned long n_periods, double r);

    //Future value of an ordinary annuity
    double ordinary_annuity(double A, unsigned long n_periods, double r);

    //Present value
    double present_value(double P_n, unsigned long n_periods, double r);

    //Present value of a series of future values
    double present_value(const Vector&  prices, unsigned long n_periods, double r);

    //Present value of an ordinary annuity
    double present_value_ordinary_annuity(double A, unsigned long n_periods, double r);

    //Convert continuous to discrete
    double cont_to_disc(double r_c, unsigned long m);

    //Convert discrete to continuous
    double disc_to_cont(double r_m, unsigned long m);
}

#endif