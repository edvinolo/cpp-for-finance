#include <iostream>
#include "european_option.hpp"

int main()
{ // All options are European

    // Call option on a stock
    european_option callOption;
    std::cout << "Call option on a stock: " << callOption.price() << std::endl;

    // Put option on a stock index
    european_option indexOption;
    indexOption.opt_type = "P";
    indexOption.U = 100.0;
    indexOption.K = 95.0;
    indexOption.T = 0.5;
    indexOption.r = 0.10;
    indexOption.sig = 0.20;
    double q = 0.05; // Dividend yield
    indexOption.b = indexOption.r - q;
    std::cout << "Put option on index: " << indexOption.price() << std::endl;
    
    // Call and put options on a future
    european_option futureOption;
    futureOption.opt_type = "P";
    futureOption.U = 19.0;
    futureOption.K = 19.0;
    futureOption.T = 0.75;
    futureOption.r = 0.10;
    futureOption.sig = 0.28;
    futureOption.b = 0.0;

    std::cout << "Put option on future: " << futureOption.price() << std::endl;
    
    // Now change over to a call on the option
    futureOption.toggle();
    std::cout << "Call on future: " << futureOption.price() << std::endl;

    // Compare with Matlabe example
    european_option call_option;
    call_option.U = 100;
    call_option.K = 95;
    call_option.sig = 0.5;
    call_option.T = 3.0/12.0;
    call_option.r = 0.01;
    call_option.b = call_option.r;
    std::cout << "Call option on a stock: " << call_option.price() << std::endl;

    
    return 0;
}