#ifndef Complex_cpp
#define Complex_cpp

#include "Complex.hpp"

//Complex useful functions
Complex Complex::conjg() const
{
    return Complex(x,-y);
}

double Complex::abs() const
{
    return sqrt(x*x + y*y);
}

double Complex::abs2() const
{
    return x*x + y*y;
}

double Complex::arg() const
{
    return atan2(y,x);
}

//Assignment operator
Complex& Complex::operator = (const Complex& c2)
{
    if (this == &c2) return *this;

    copy(c2);
    return *this;
}

//Complex unary operators
Complex Complex::operator - () const
{
    return Complex(-x, -y);
}

//Complex-Complex arithmetic operators
Complex Complex::operator + (const Complex& c2) const
{
    return Complex(x + c2.x, y + c2.y);
}

Complex Complex::operator - (const Complex& c2) const
{
    return Complex(x - c2.x, y - c2.y);
}

Complex Complex::operator * (const Complex& c2) const
{
    // c*c2 = (x+iy)*(x_2+iy_2) = x*x_2 - y*y_2 + i(x*y_2 + y*x_2)
    double real,imag;
    real = x*c2.x - y*c2.y;
    imag = x*c2.y + y*c2.x;
    return Complex(real, imag);
}

Complex Complex::operator / (const Complex& c2) const
{
    // c/c2 = c*c2.conjg()/|c2|^2
    return (*this)*c2.conjg()/c2.abs2();
}

//Complex-double arithmetic operators
Complex operator + (const Complex& z, double d)
{
    return Complex(d + z.x,z.y);
}

Complex operator + (double d, const Complex& z)
{
    return Complex(d + z.x,z.y);
}

Complex operator - (const Complex& z, double d)
{
    return Complex(z.x - d,z.y);
}

Complex operator - (double d, const Complex& z)
{
    return Complex(d - z.x, -z.y);
}

Complex operator * (const Complex& z, double d)
{
    return Complex(d*z.x, d*z.y);
}

Complex operator * (double d, const Complex& z)
{
    return Complex(d*z.x,d*z.y);
}

Complex operator / (const Complex& z, double d)
{
    return Complex(z.x/d, z.y/d);
}

Complex operator / (double d, const Complex& z)
{
    Complex z_conj = z.conjg();
    return d*z_conj/z.abs2();
}

//Overload << operator
std::ostream& operator << (std::ostream& os, const Complex& z)
{
    os << "(" << z.x << ", " << z.y << "i)";
    return os;
}

//Functions of complex argument
Complex exp(const Complex& z)
{
    return Complex(exp(z.x)*cos(z.y),exp(z.x)*sin(z.y));
}

Complex log(const Complex& z)
{
    return Complex(log(z.abs()),z.arg());
}

Complex cos(const Complex& z)
{
    Complex i(0,1);
    return 0.5*(exp(i*z)+exp(-i*z));
}

Complex sin(const Complex& z)
{
    Complex i(0,1);
    return -i*0.5*(exp(i*z)-exp(-i*z));
}

Complex tan(const Complex& z)
{
    return sin(z)/cos(z);
}

Complex cotan(const Complex& z)
{
    return cos(z)/sin(z);
}

Complex cosh(const Complex& z)
{
    return 0.5*(exp(z) + exp(-z));
}

Complex sinh(const Complex& z)
{
    return 0.5*(exp(z) - exp(-z));
}

Complex tanh(const Complex& z)
{
    return sinh(z)/cosh(z);
}

Complex cotanh(const Complex& z)
{
    return cosh(z)/sinh(z);
}

#endif