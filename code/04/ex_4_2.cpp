#include <iostream>
#include "point.hpp"

int& flunky_flunk()
{
    int result = 1;
    std::cout << "funny" << std::endl;
    return result;
}

int main()
{
    //int test  = flunky_flunk();
    //flunky_flunk() = 12;
    //std::cout << flunky_flunk() << std::endl;
    //std::cout << test << std::endl;

    point pt(1.0,2.0);
    point pt_2(pt);

    pt.set_x(4.2);
    pt.set_y(9.0);

    std::cout << pt.get_x() << " " << pt.get_y() << std::endl;
    std::cout << pt_2.get_x() << " " << pt_2.get_y() << std::endl;

    return 0;
}