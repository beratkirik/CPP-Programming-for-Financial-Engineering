//
//  Point.cpp
//  Exercise 1
//
//  Created by Changheng Chen on 12/2/16.
//  Copyright © 2016 Changheng Chen. All rights reserved.
//

#include "Point.hpp"
#include <iostream>   // std::cout
#include <sstream>    // std::stringstream

// (0) Default constructor and destructor
Point::Point() : m_x(0), m_y(0)   // Colon syntax, more efficient way of initialization
{
    //  m_x = m_y = 0.0;
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
