#ifndef point_hpp
#define point_hpp

#include <iostream>

class point
{
private:
    void init(double xs, double ys);

    //Properties for x- and y-coordinates
    double x;
    double y;

public:
    //Constructors and destructors
    point(); //default constructor
    point(double xs, double ys); // Construct with coordinates
    point(const point& source); //Copy-constructor
    virtual ~point(); //Destructor

    //Selectors
    double get_x() const; //Return x
    double get_y() const; //Return y

    //Modifiers
    void set_x(double new_x); //Set x
    void set_y(double new_y); //Set y 

    //Assignment operator
    point& operator = (const point& pt_2);
};

//Overload ostream
std::ostream& operator<<(std::ostream& os, const point& pt);

//Selectors
inline double point::get_x() const
{
    return x;
}

inline double point::get_y() const
{
    return y;
}

//Modifiers
inline void point::set_x(double new_x)
{
    x = new_x;
}

inline void point::set_y(double new_y)
{
    y = new_y;
}

//Init function
inline void point::init(double xs, double ys)
{
    x = xs;
    y = ys;
}

#endif