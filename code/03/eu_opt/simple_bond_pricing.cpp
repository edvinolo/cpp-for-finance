#ifndef simple_bond_pricing_cpp
#define simple_bond_pricing_cpp

#include "simple_bond_pricing.hpp"


namespace Chapter3CPPBook
{
    //Function to calculate power of a number
    double power(double d, long n)
    {
        double product = 1.0;

        if (n >= 0)
        {
            for (long i = 0; i < n; i++)
            {
                product *= d;                
            }
        }

        else
        {
            for (long i = 0; i < -n; i++)
            {
                product /= d;                
            }
        }
 
        return product;
    }

    //Future value of a sum of money invested today
    double future_value(double P_0, unsigned long n_periods, double r)
    {
        double factor = 1.0 + r;
        return P_0*power(factor, n_periods);
    }

    //Future value of a sum of money invested today, m periods per year. r is annual interest rate
    double future_value(double P_0, unsigned long n_periods, double r, unsigned long m)
    {
        double factor = 1.0 + r/m;
        return P_0*power(factor, m*n_periods);
    }

    //Continuous compounding, i.e. limit as m->infinity
    double future_value_continuous(double P_0, unsigned long n_periods, double r)
    {
        return P_0*exp(r*n_periods);
    }

    //Future value of an ordinary annuity
    double ordinary_annuity(double A, unsigned long n_periods, double r)
    {
        double factor = 1.0 + r;

        return A*((power(factor,n_periods)-1.0)/r);
    }

    //Present value
    double present_value(double P_n, unsigned long n_periods, double r)
    {
        double factor = 1.0 + r;
        return P_n/power(factor,n_periods);
    }

    //Present value of a series of future values
    double present_value(const Vector&  prices, unsigned long n_periods, double r)
    {
        assert(n_periods == prices.size());

        double P_V = 0.0;
        double factor  = 1.0 + r;

        for (unsigned long t = 0; t < n_periods; t++)
        {
            P_V += prices[t]/power(factor,t+1);
        }

        return P_V;
    }

    //Present value of an ordinary annuity
    double present_value_ordinary_annuity(double A, unsigned long n_periods, double r)
    {
        double factor = 1.0 + r;
        return A*((1.0 - power(factor,-n_periods))/r);
    }

    //Convert continuous to discrete
    double cont_to_disc(double r_c, unsigned long m)
    {
        return m*(exp(r_c/m)-1.0);
    }

    //Convert discrete to continuous
    double disc_to_cont(double r_m, unsigned long m)
    {
        return m*log(1.0 + r_m/m);
    }
}


#endif