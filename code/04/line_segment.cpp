#ifndef line_segment_cpp
#define line_segment_cpp

#include "line_segment.hpp"

void line_segment::init(const point& p1, const point& p2)
{
    //Initialze
    e1 = p1;
    e2 = p2;
}

point line_segment::start() const
{
    //Get e1
    return e1;
}

point line_segment::end() const
{
    //Get e2
    return e2;
}

void line_segment::start(const point& p1)
{
    //Set e1
    e1 = p1;
    return;
}

void line_segment::end(const point& p2)
{
    //Set e2
    e2 = p2;
    return;
}

double line_segment::length() const
{
    //Compute length of line segment
    double delta_x = e2.get_x() - e1.get_x();
    double delta_y = e2.get_y() - e1.get_y();
    double len = sqrt(delta_x*delta_x + delta_y*delta_y);

    return len; 

}

point line_segment::midpoint() const
{
    //Compute midpoint of line segment
    double mid_x = 0.5*(e1.get_x() + e2.get_x());
    double mid_y = 0.5*(e1.get_y() + e2.get_y());
    
    return point(mid_x, mid_y);
}

line_segment::line_segment()
{
    //Default constructor
    init(point(), point());
}

line_segment::line_segment(const point& p1, const point& p2)
{
    //Constuctor with points
    init(p1,p2);
}

line_segment::line_segment(const line_segment& segment)
{
    //Copy constructor
    e1 = segment.start();
    e2 = segment.end();
}

line_segment::~line_segment()
{
    //Destructor
}

#endif