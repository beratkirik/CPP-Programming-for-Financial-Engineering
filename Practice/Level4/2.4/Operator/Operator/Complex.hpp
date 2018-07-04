//
//  Complex.hpp
//  Operator
//
//  Class of complex number in two-dimensional space. Simple example JUST
//  to show how to use operator overloading.
//
//  The goal of this code is to show the difference facets of operator overloading.
//
//  Created by Changheng Chen on 12/15/16.
//  Copyright © 2016 Changheng Chen. All rights reserved.
//

#ifndef Complex_hpp
#define Complex_hpp

#include <iostream>
using namespace std;                          // std::ostream

class Complex
{
private:
    double x, y;
    friend Complex mpi(const Complex& z);     // Multiply z by i == sqrt(-1)

public:
    // Constructors
    Complex();                                // Default constructor
    Complex(double real);                     // Special case is real numbers
    Complex(double real, double imag);        // Cartesian form
    Complex(const Complex& p);                // Copy constructor
    virtual ~Complex();
    
    // Member accessing functions
    double xVal() const;
    double yVal() const;
    
    // Member operator overloading
    //Complex& operator-();
    Complex  operator -  () const;
    Complex& operator =  (const Complex& c);
    Complex& operator += (const Complex& c);
    Complex& operator -= (const Complex& c);
    Complex& operator *= (const Complex& c);
    
    Complex  add(const Complex& c2) const;    // For compatibility reasons
    Complex  operator + (const Complex& c2) const;
    Complex  operator - (const Complex& c2) const;
    Complex  operator * (const Complex& c2) const;
    
    // Functionality
    double distance (const Complex& c2);      // Euclidean distance
    
    // Global accessing functions
    friend double real(const Complex& c);     // Real part of number
    friend double imag(const Complex& c);     // Imaginary part of number
    friend double  rad(const Complex& c);     // Distance from origin
    friend double  mod(const Complex& c);     // Distance from origin, 'modulus' conflicits with internal function
    friend double  abs(const Complex& c);     // Absolute value of complex number
    
    // Global operator overloading
    friend Complex operator * (const Complex& c, double d);
    friend Complex operator * (double d, const Complex& c);
    
    friend Complex operator + (const Complex& c, double d);
    friend Complex operator + (double d, const Complex& c);
    
    friend Complex operator - (const Complex& c, double d);
    friend Complex operator - (double d, const Complex& c);
    
    friend ostream& operator << (ostream& os, const Complex& cmp);
};

#endif /* Complex_hpp */
