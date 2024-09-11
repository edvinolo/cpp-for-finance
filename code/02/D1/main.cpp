#include <iostream>
#include "sum_double.hpp"

int main()
{
    double x = 1.1, y = 5.3, z = 9.8;
    std::cout << "Sum of " << x << " and " << y << ": " << sum(x,y) << std::endl;
    std::cout << "Sum of " << x << ", " << y << " and " << z << ": " << sum(x,y,z) << std::endl;    
    return 0;
}