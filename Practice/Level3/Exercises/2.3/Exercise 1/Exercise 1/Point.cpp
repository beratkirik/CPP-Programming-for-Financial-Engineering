//
//  Point.cpp
//  Exercise 1
//
//  Created by Changheng Chen on 12/8/16.
//  Copyright © 2016 Changheng Chen. All rights reserved.
//

#include "Point.hpp"
#include <string>     // std::string
#include <iostream>   // std::cout
#include <sstream>    // std::stringstream, std:stringbuf
#include <cmath>
using namespace std;

// (0) Constructors and destructor
Point::Point() : m_x(0), m_y(0)   // Colon syntax, more efficient way of initialization
{
    //  m_x = m_y = 0.0;
    cout << "Default constructor: Point()...\n";
}

Point::Point(double newx, double newy) : m_x(newx), m_y(newy)
{// Initialize using newx and newy
    
    //  m_x = newx;
    //  m_y = newy;
    cout << "Constructor: Point(double newx, double newy)...\n";
}

Point::Point(const Point& p) : m_x(p.m_x), m_y(p.m_y)
{
    //  m_x = p.m_x;
    //  m_y = p.m_y;
    cout << "Copy Constructor: Point(const Point& p)...\n";
}

Point::~Point()
{
    cout << "Bye my point...\n";
}


// (1) Getter functions
double Point::GetX()
{
    return m_x;
}

double Point::GetY()
{
    return m_y;
}


// (2) Setter functions
void Point::SetX(double newX)
{
    m_x = newX;
}

void Point::SetY(double newY)
{
    m_y = newY;
}


// (3) String description function
string Point::ToString()
{
    stringstream ss;
    ss << "Point(" << m_x << "," << m_y << ")";
    
    return ss.str();  // Retrieve the string from the string buffer
}


// (4) Distance functions
double Point::DistanceOrigin()
{// Distance from origin
    
    return sqrt(m_x*m_x + m_y*m_y);
}

double Point::Distance(Point p)
{// Distance between two points
    
    return sqrt((m_x-p.m_x)*(m_x-p.m_x) + (m_y-p.m_y)*(m_y-p.m_y));
}
