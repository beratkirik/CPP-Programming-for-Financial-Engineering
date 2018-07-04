//
//  Point.cpp
//  Exercise 3
//
//  Created by Changheng Chen on 1/6/17.
//  Copyright © 2017 Changheng Chen. All rights reserved.
//

#include "Point.hpp"
#include <iostream>   // std::cout
#include <sstream>    // std::stringstream
#include <cmath>      // sqrt()

// ==================================================================================
// (0) Constructors and destructor
Point::Point() : m_x(0), m_y(0)
{
    cout << "Point default constructor..." << endl;
}

Point::Point(double value) : m_x(value), m_y(value)
{
    cout << "Point constructor with equal coordinates..." << endl;
}

Point::Point(double newx, double newy) : m_x(newx), m_y(newy)
{
    cout << "Point constructor with coordinates..." << endl;
}

Point::Point(const Point& p) : m_x(p.m_x), m_y(p.m_y)
{
    cout << "Point copy constructor..." << endl;
}

Point::~Point()
{
    cout << "Bye my point..." << endl;
}


// ==================================================================================
// (1) Getter functions
double Point::X() const
{
    return m_x;
}

double Point::Y() const
{
    return m_y;
}


// ==================================================================================
// (2) Setter functions
void Point::X(double newX)
{
    m_x = newX;
}

void Point::Y(double newY)
{
    m_y = newY;
}


// ==================================================================================
// (3) String description function
string Point::ToString() const
{
    stringstream ss;
    ss << "Point(" << m_x << "," << m_y << ")";
    
    return ss.str();  // Retrieve the string from the string buffer
}


// ==================================================================================
// (4) Distance functions
double Point::Distance() const
{// Distance from origin
    
    return sqrt(m_x*m_x + m_y*m_y);
}

double Point::Distance(const Point& p) const
{// Distance between two points
    
    return sqrt((m_x-p.m_x)*(m_x-p.m_x) + (m_y-p.m_y)*(m_y-p.m_y));
}


// ==================================================================================
// (5) Operator overloading
Point Point::operator - () const
{ // Negate the coordinates
    
    return Point(-m_x, -m_y);
}

Point Point::operator + (const Point& p) const
{ // Add coordinates
    
    return Point(m_x + p.m_x, m_y + p.m_y);
}

bool Point::operator == (const Point& p) const
{ // Equally compare operator
    
    return m_x == p.m_x && m_y == p.m_y;
}

Point& Point::operator = (const Point& source)
{ // Assignment operator
    
    if (this == &source)
        return *this;
    
    m_x = source.m_x;
    m_y = source.m_y;
    
    return *this;
}

Point& Point::operator *= (double factor)
{ // Scale the coordinates & assign
    
    m_x *= factor;
    m_y *= factor;
    
    return *this;
}


// ==================================================================================
// (6) Global operator overloading
Point operator * (double factor, const Point& p)
{ // Scale the coordinates
    
    return Point(factor * p.m_x, factor * p.m_y );
}

Point operator * (const Point& p, double factor)
{ // Scale the coordinates
    
    return factor * p;
}

ostream& operator << (ostream& os, const Point& p)
{ // Ostream << operator
    
    return os << p.ToString() << "\n";
}
