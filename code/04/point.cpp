#ifndef point_cpp
#define point_cpp

#include "point.hpp"

//Assigment operator
point& point::operator = (const point& pt_2)
{
    if (this == &pt_2) return *this;

    x = pt_2.get_x();
    y = pt_2.get_y();

    return *this;
}

//Overload ostream
std::ostream& operator<<(std::ostream& os, const point& pt)
{
    os << "(" << pt.get_x() << ", " << pt.get_y() << ")";
    return os;
}

//Constructors
point::point()
{
    init(0.0,0.0);
}

point::point(double xs, double ys)
{
    init(xs,ys);
}

point::point(const point& source)
{
    init(source.get_x(), source.get_y());
}

//Destructor
point::~point()
{
}

#endif