// complex.cpp
//
// Code file for the class of complex numbers in two dimensional
// geometry.
//
// Last modification dates:
//
// 1993-6-27: DD new functions added, mainly member functions changed to
//	      global functions and many new special functions (e.g. arc*. sqrt
// 2011-8-20 DD 101 case (DJD)
//

#include "Complex.hpp"

// This could be a STATIC object but that's an optimisation at this stage.
Complex mpi(const Complex& z)
{ // Multiply z by i == sqrt(-1)

	return Complex(-z.y, z.x);
}

Complex::Complex()
{ // Default constructor

	x = 1.0;
	y = 0.0;
}

Complex::Complex(const Complex &p)
{ // Copy initialisor

	x = p.x;
	y = p.y;
}

Complex::Complex(double real)
{
	x = real;
	y = 0.0;
}

Complex::Complex(double dx, double dy)
{
	x = dx;
	y = dy;
}

Complex::~Complex()
{

	cout << "i never liked complex numbers anyways\n";
}

Complex& Complex::operator = (const Complex& c)
{
	// Avoid doing assign to myself
	if (this == &c)
		return *this;

	x = c.x;
	y = c.y;

	return *this;
}

Complex& Complex::operator += (const Complex& c)
{
		x += c.x;
		y += c.y;

		return *this;
}

Complex& Complex::operator -= (const Complex& c)
{
		x -= c.x;
		y -= c.y;

		return *this;
}


Complex& Complex::operator *= (const Complex& c)
{

	Complex tmp = (*this) * c;
	*this = tmp;

	return *this;

}


double Complex::xVal() const
{

	return x;
}

double Complex::yVal() const
{

	return y;
}

double real(const Complex& c)
{
	return c.x;
}

double imag(const Complex& c)
{
	return c.y;
}


double rad(const Complex& c)
{ // Distance from origin

	double res = ::sqrt((c.x*c.x) + (c.y*c.y));
	return res;
}

double modulus(const Complex& c)
{ // Distance from the origin (Same as the rad() function)

	return rad(c);
}

double abs(const Complex& c)
{ // Absolute value of the complex number

	return rad(c);
}

// Functionality
double Complex::distance (const Complex& c2)
{ // Euclidean distance

	return ::sqrt((x-c2.x)*(x-c2.x) + (y-c2.y)*(y-c2.y));
}


// Member operator overloading
Complex Complex::operator - () const
{ // The additive inverse of the current complex number

	return Complex(- x, - y);
}

Complex Complex::add(const Complex& c2) const
{ // Add two complex numbers

	Complex result;
	result.x = x + c2.x;
	result.y = y + c2.y;

	return result;
}

Complex Complex::operator + (const Complex& c2) const
{ // Add two complex numbers

	return Complex(x + c2.x, y + c2.y); // Anonymous object
}
Complex Complex::operator - (const Complex& c2) const
{ // Subtract two complex numbers

	return Complex(x - c2.x, y - c2.y);
}

Complex Complex::operator * (const Complex& c2) const
{ // Multiply two complex numbers

	return Complex((x * c2.x) - (y * c2.y),
		       (x * c2.y) + (y * c2.x));
}


// Global operator overloading
Complex operator * (const Complex& c, double d)
{ // Scaling by a double

	return Complex(c.x * d, c.y * d);
}	

Complex operator * (double d, const Complex& c)
{ // Scaling by a double

	// Reuse already made operator
	return c * d;
}


ostream& operator << (ostream& os, const Complex& cmp)
{ // Print the complex number

	os << "[" << cmp.x << ", " << cmp.y << "]\n";
	return os;
}
