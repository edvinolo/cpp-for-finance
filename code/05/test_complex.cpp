#include <iostream>
#include "Complex.hpp"
#include <math.h>

int main()
{
    double pi = 3.14159265359;
    Complex z_1, z_2(1,1),z_3(1,-1),z_pi(0,-pi);
    Complex z_eq = z_pi;

    std::cout << z_1 << " " << z_2 << " " << z_3 << " " << z_pi << " " << z_eq << std::endl;
    std::cout << "z_2 + z_3 =  " << z_2 + z_3 << " z_2 - z_3 =  " << z_2-z_3 << " z_2*z_3 =  " <<  z_2*z_3 << " z_2/z_3 =  " << z_2/z_3 << std::endl;
    std::cout << "z_2:" << z_2 << " Abs: " << z_2.abs() << " Arg: " << z_2.arg() << " Conjugate: " << z_2.conjg() << std::endl;
    std::cout << "exp(1+1i): " << exp(z_2) << " cos(1+1i): " << cos(z_2) << " cosh(1+1i): " << cosh(z_2) << std::endl;
    std::cout << "exp(-pi*i): " << exp(z_pi) << std::endl;

    return 0;
}