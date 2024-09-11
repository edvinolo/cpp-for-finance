#ifndef european_option_hpp
#define european_option_hpp

#include <string>
#include <math.h>

class european_option
{
private:
    void init(); //Initialize default values
    void copy(const european_option& o2);
    
    //Kernel functions for option calculations
    double call_price() const;
    double put_price() const;
    double call_delta() const;
    double put_delta() const;
    double N(double) const; 

public:
    //Public member data for convenience only
    double r; //Interest rate
    double sig;  //Volatility
    double K; //Strike price
    double T; //Expiry date
    double U; //Current underlying price
    double b; //Cost of carry
    
    std::string opt_type; //Option name (call,put)
public:
    //Constructors
    european_option(); //Default call option
    european_option(const european_option & option2); //Copy constructor
    european_option(const std::string& option_type); //Create option type

    //Destructor
    virtual ~european_option();

    //Assignment operator
    european_option& operator = (const european_option& option2);

    //Functions that calculate option price and (some) sensitivities
    double price() const;
    double delta() const;

    //Modifier functions
    void toggle(); //Change option type (C/P, P/C)


};




#endif