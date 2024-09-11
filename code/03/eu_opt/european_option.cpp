#ifndef european_option_cpp
#define european_option_cpp

#include "european_option.hpp"

//Kernel functions
double european_option::N(double d) const
{
    return 0.5*(erf(0.5*sqrt(2)*d)+1.0);
}

double european_option::call_price() const
{
    double tmp, d1, d2;

    tmp = sig*sqrt(T);
    d1 = (log(U/K) + (b + 0.5*(sig*sig))*T)/tmp;
    d2 = d1 - tmp;

    return (U*exp((b-r)*T)*N(d1)) - (K*exp(-r*T)*N(d2));
}

double european_option::put_price() const
{
    double tmp, d1, d2;
    
    tmp  = sig*sqrt(T);
    d1 = (log(U/K) + (b + 0.5*(sig*sig))*T)/tmp;
    d2 = d1 - tmp;

    return (K*exp((-r*T))*N(-d2)) - (U*exp((b-r)*T)*N(-d1));
}

double european_option::call_delta() const
{
    double tmp, d1;

    tmp = sig*sqrt(T);
    d1 = (log(U/K) + (b + 0.5*(sig*sig))*T)/tmp;

    return exp((b-r)*T)*N(d1);
}

double european_option::put_delta() const
{
    double tmp, d1;

    tmp = sig*sqrt(T);
    d1 = (log(U/K) + (b + 0.5*(sig*sig))*T)/tmp;

    return exp((b-r)*T)*(N(d1) - 1.0);
}

void european_option::init()
{//Inititalize  all default values

    //Default values
    r = 0.08;
    sig  = 0.30;
    K = 65.0;
    T = 0.25;
    U = 60.0; //U ==  stock in this case
    b = r; //Black and Scholes stock option model (1973)
    opt_type = "C"; //European call option (the default type)
}

void european_option::copy(const european_option& o2)
{
    //Copy values from o2
    r = o2.r;
    sig = o2.sig;
    K = o2.K;
    T = o2.T;
    U = o2.U;
    b = o2.b;
    opt_type = o2.opt_type;
}

european_option::european_option()
{
    //Default call option
    init();
}

european_option::european_option(const european_option& o2)
{
    //Copy constructor
    copy(o2);
}

european_option::european_option(const std::string& option_type)
{
    //Create option type
    init();
    opt_type = option_type;
    
    if  (opt_type == "c")
    {
        opt_type = "C";
    }

    if (opt_type == "p")
    {
        opt_type == "P";
    }
}

european_option::~european_option()
{
    //Destructor
}

european_option& european_option::operator = (const european_option& opt2)
{
    //Assignment operator (deep copy)
    
    if (this == &opt2) return *this;

    copy(opt2);

    return *this; 
}

//Functions that calculate  option price and sensitivities
double  european_option::price() const
{
    if (opt_type == "C")
    {
        return call_price();
    }

    else
    {
        return put_price();
    }
}

double european_option::delta() const
{
        if (opt_type == "C")
    {
        return call_delta();
    }

    else
    {
        return put_delta();
    }
}

//Modifier functions
void european_option::toggle()
{
    //Change option type
    if (opt_type == "C")
    {
        opt_type == "P";
    }

    else
    {
        opt_type == "C";
    }
}

#endif