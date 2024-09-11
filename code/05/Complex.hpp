#ifndef Complex_hpp
#define Complex_hpp

#include <math.h>
#include <iostream>

class Complex
{
private:
    double x; //Real
    double y; //Imaginary

    //Initializer
    void init(double x_in, double y_in) {x = x_in, y =  y_in;};

    //Copy
    void copy(const Complex& z) {x = z.x, y = z.y;};

public:
    //Constructors
    Complex() {init(0.0,0.0);}; //Default constructor -> 0 + 0i
    Complex(double x_in, double y_in) {init(x_in,y_in);}; //Construct with real and imaginary part
    Complex(const Complex& z) {copy(z);}; //Copy constructor

    //Destructor
    ~Complex() {};

    //Getters
    double real() const {return x;};
    double imag() const {return y;};

    //Setters
    void real(double x_in) {x = x_in;};
    void imag(double y_in) {y = y_in;};

    //Complex useful functions
    Complex conjg() const;
    double abs() const;
    double abs2() const;
    double arg() const;

    //Assignment operator
    Complex& operator = (const Complex& c2);

    //Complex unary operators
    Complex operator - () const;

    //Complex-Complex arithmetic operators
    Complex operator + (const Complex& c2) const;
    Complex operator - (const Complex& c2) const;
    Complex operator * (const Complex& c2) const;
    Complex operator / (const Complex& c2) const;

    //Complex-double arithmetic operators
    friend Complex operator + (const Complex& z, double d);
    friend Complex operator + (double d, const Complex& z);
    friend Complex operator - (const Complex& z, double d);
    friend Complex operator - (double d, const Complex& z);
    friend Complex operator * (const Complex& z, double d);
    friend Complex operator * (double d, const Complex& z);
    friend Complex operator / (const Complex& z, double d);
    friend Complex operator / (double d, const Complex& z);

    //Overload << operator
    friend std::ostream& operator << (std::ostream& os, const Complex& z);

    //Functions of complex argument
    friend Complex exp(const Complex& z);
    friend Complex log(const Complex& z);
    friend Complex cos(const Complex& z);
    friend Complex sin(const Complex& z);
    friend Complex tan(const Complex& z);
    friend Complex cotan(const Complex& z);
    friend Complex cosh(const Complex& z);
    friend Complex sinh(const Complex& z);
    friend Complex tanh(const Complex& z);
    friend Complex cotanh(const Complex& z);
};

#endif