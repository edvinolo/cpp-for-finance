#include <iostream>
#include "point.hpp"
#include "line_segment.hpp"

int main()
{
    point pt_1,pt_2(2.0,4.0),pt_3(6.2,-5.5);

    line_segment seg_1,seg_2(pt_1,pt_2), seg_3(seg_2);
    seg_3.end(pt_3);

    seg_1.print();
    seg_2.print();
    seg_3.print();

    double len_1 = seg_1.length(), len_2 = seg_2.length(), len_3 = seg_3.length();
    std::cout << "Lengths: " << len_1 << ", " << len_2 << ", " << len_3 << std::endl;

    point mid_1 = seg_1.midpoint(), mid_2 = seg_2.midpoint(), mid_3 = seg_3.midpoint();
    std::cout << "Midpoints: " << mid_1 << " " << mid_2 << " " << mid_3 << std::endl;

    return 0;
}