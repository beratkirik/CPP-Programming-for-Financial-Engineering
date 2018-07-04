//
//  Point.cpp
//  Exercise 7
//
//  Created by Changheng Chen on 12/9/16.
//  Copyright © 2016 Changheng Chen. All rights reserved.
//

#include "Point.hpp"
#include <string>     // std::string
#include <iostream>   // std::cout
#include <sstream>    // std::stringstream
#include <cmath>      // sqrt()
using namespace std;

// (0) Default constructor and destructor
Point::Point() : m_x(0), m_y(0)   // Colon syntax, more efficient way of initialization
{
    //  m_x = m_y = 0.0;
    cout << "Hello my point...\n";
}

Point::Point(double newx, double newy) : m_x(newx), m_y(newy)
{// Initialize using newx and newy
    
    //  m_x = newx;
    //  m_y = newy;
    cout << "Hello my point...\n";
}

Point::Point(const Point& p) : m_x(p.m_x), m_y(p.m_y)
{
    //  m_x = p.m_x;
    //  m_y = p.m_y;
    cout << "Hello my Point...\n";
}

Point::~Point()
{
    cout << "Bye my point...\n";
}

// (1) String description function
string Point::ToString() const
{
    stringstream ss;
    ss << "Point(" << m_x << "," << m_y << ")";
    
    return ss.str();  // Retrieve the string from the string buffer
}


// (2) Distance functions
double Point::Distance() const
{// Distance from origin
    return sqrt(m_x*m_x + m_y*m_y);
}

double Point::Distance(const Point& p) const
{// Distance between two points
    return sqrt((m_x-p.m_x)*(m_x-p.m_x) + (m_y-p.m_y)*(m_y-p.m_y));
}
