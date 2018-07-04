//
//  Complex.cpp
//  Operator
//
//  Code file for the class of complex numbers in two dimensional geometry.
//
//  Created by Changheng Chen on 12/15/16.
//  Copyright © 2016 Changheng Chen. All rights reserved.
//

#include "Complex.hpp"
#include <iostream>
#include <cmath>
using namespace std;   // std::ostream, std::sqrt

// This could be a STATIC object but that's an optimization at this stage.
Complex mpi(const Complex& z)
{ // Multiply z by i == sqrt(-1)
    
    return Complex(-z.y, z.x);
}


// =================== Constructors and Destructor ===================
Complex::Complex() : x(1.0), y(1.0)
{ // Default constructor
    
    //x = 1.0;
    //y = 1.0;
}

Complex::Complex(double real) : x(real), y(0.0)
{
    //x = real;
    //y = 0.0;
}

Complex::Complex(double dx, double dy)
{
    x = dx;
    y = dy;
}

Complex::Complex(const Complex& p) : x(p.x), y(p.y)
{ // Copy initializor
    
    //x = p.x;
    //y = p.y;
}

Complex::~Complex()
{
    cout << "I never liked complex numbers anyways\n";
}


// ======================= Accessing Functions =======================
double Complex::xVal() const
{
    return x;
}

double Complex::yVal() const
{
    return y;
}


// =================== Member operator overloading ===================
Complex Complex::operator - () const
{ // The additive inverse of the current complex number
    
    return Complex(- x, - y);
}

// WRONG!!!
/*Complex& Complex::operator - ()
{
    Complex tmp = Complex(- x, - y);
    *this = tmp;
    
    return *this;   // tmp lifetime shorter than the function body...
}*/


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

Complex Complex::add(const Complex& c2) const
{ // Add two complex numbers
    
    //Complex result;
    //result.x = x + c2.x;
    //result.y = y + c2.y;
    
    //return result;
    
    return Complex(x + c2.x, y + c2.y);
}

Complex Complex::operator + (const Complex& c2) const
{ // Add two complex numbers
    
    return Complex(x + c2.x, y + c2.y);  // Anonymous object
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


// =========================== Functionality ===========================
double Complex::distance(const Complex& c2)
{ // Euclidean distance
    
    return sqrt((x-c2.x)*(x-c2.x) + (y-c2.y)*(y-c2.y));
}


// ===================== Global accessing function =====================
// No scope resolution operator Complex::, cannot access x, y
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
    
    //double res = sqrt((c.x*c.x) + (c.y*c.y));
    //return res;
    
    return sqrt((c.x*c.x) + (c.y*c.y)); // Anonymous object
}

double mod(const Complex& c)
{ // Distance from the origin (Same as the rad() function)
    
    return rad(c);
}

double abs(const Complex& c)
{ // Absolute value of the complex number
    
    return rad(c);
}


// ==================== Global operator overloading ====================
Complex operator * (const Complex& c, double d)
{ // Scaling by a double
    
    return Complex(c.x * d, c.y * d);
}

Complex operator * (double d, const Complex& c)
{ // Scaling by a double
    
    return c * d;
}

Complex operator + (const Complex& c, double d)
{
    return Complex(c.x +d, c.y);
}

Complex operator + (double d, const Complex& c)
{
    return c + d;
}

Complex operator - (const Complex& c, double d)
{
    return Complex(c.x - d, c.y);
}

Complex operator - (double d, const Complex& c)
{
    return c - d;
}

ostream& operator << (ostream& os, const Complex& cmp)
{ // Print the complex number
    
    //os << "[" << cmp.x << ", " << cmp.y << "]\n";
    //return os;
    
    return os << "[" << cmp.x << ", " << cmp.y << "]\n";
}
