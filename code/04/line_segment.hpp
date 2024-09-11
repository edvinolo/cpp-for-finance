#ifndef line_segment_hpp
#define line_segment_hpp

#include <iostream>
#include <math.h>
#include "point.hpp"

class line_segment
{
private:
    //Endpoints of line segments
    point e1;
    point e2;

    //Initializer
    void init(const point& p1, const point& p2);

public:
    //Constructors
    line_segment(); //Line with both endpoints at the origin
    line_segment(const point& p1, const point& p2); 
    line_segment(const line_segment& segment); //Copy constructor

    //Destructor
    ~line_segment();

    //Accessing functions
    point start() const; //e1
    point end() const;   //e2

    //Modifiers
    void start(const point& p1); //Set e1
    void end(const point& p2);  //Set e2

    //Arithmetic
    double length() const; //length of line

    //Interaction with points
    point midpoint() const; //Midpoint of line

    //Print a line
    void print() {std::cout << e1 << ", " << e2 << std::endl;}
};

#endif