//
//  Point.cpp
//  Exercise 5
//
//  Created by Changheng Chen on 12/8/16.
//  Copyright © 2016 Changheng Chen. All rights reserved.
//

#include "Point.hpp"
#include <iostream>   // std::cout
#include <sstream>    // std::stringstream
#include <cmath>      // sqrt()

// (0) Constructors and destructor
Point::Point() : m_x(0), m_y(0)   // Colon syntax, more efficient way of initialization
{
    cout << "Point default constructor: Hello my point...\n";
}

Point::Point(double newx, double newy) : m_x(newx), m_y(newy)
{
    cout << "Point constructor: Hello my point...\n";
}

Point::Point(const Point& p) : m_x(p.m_x), m_y(p.m_y)
{
    cout << "Point copy constructor: Hello my Point...\n";
}

Point::~Point()
{
    cout << "Bye my point...\n";
}


// (1) Getter functions
double Point::X() const
{
    return m_x;
}

double Point::Y() const
{
    return m_y;
}


// (2) Setter functions
void Point::X(double newX)
{
    m_x = newX;
}

void Point::Y(double newY)
{
    m_y = newY;
}


// (3) String description function
string Point::ToString() const
{
    stringstream ss;
    ss << "Point(" << m_x << "," << m_y << ")";
    
    return ss.str();  // Retrieve the string from the string buffer
}


// (4) Distance functions
double Point::Distance() const
{// Distance from origin
    
    return sqrt(m_x*m_x + m_y*m_y);
}

double Point::Distance(const Point& p) const
{// Distance between two points
    
    return sqrt((m_x-p.m_x)*(m_x-p.m_x) + (m_y-p.m_y)*(m_y-p.m_y));
}
