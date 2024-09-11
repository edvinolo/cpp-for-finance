#include <iostream>
#include "sum_generic.cpp"

int main()
{
    int x = 1,y = 2,z = 3;
    double x_d = 1.1, y_d = 2.2, z_d = 3.3;
    
    std::cout << "Sum of ints x: " << x << " y: " << y << " z: " << z << " is: " << sum(x,y,z) << std::endl;
    std::cout << "Sum of doubles x: " << x_d << " y: " << y_d << " z: " << z_d << " is: " << sum(x_d,y_d,z_d) << std::endl;


    return 0;
}