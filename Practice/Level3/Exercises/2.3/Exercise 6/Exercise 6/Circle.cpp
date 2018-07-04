//
//  Circle.cpp
//  Exercise 6
//
//  Created by Changheng Chen on 12/9/16.
//  Copyright © 2016 Changheng Chen. All rights reserved.
//

#include "Circle.hpp"
#include <iostream>       // std::cout
#include <sstream>        // std::stringstream
#include <cmath>          // M_PI
#define _USE_MATH_DEFINES

//================ Constructors and destructor ================
Circle::Circle(): m_center(Point()), m_radius(0.0)
{ // Default constructor
    
    //Point m_center;   // Initialize as (0,0)
    //m_radius = 0.0;   // Initialize as 0.0
    cout << "Hello my circle...\n";
}

Circle::Circle(Point center, double radius) : m_center(center), m_radius(radius)
{ // Constructor
    
    // m_center = center;
    // m_radius = radius;
    cout << "Hello my circle...\n";
}

Circle::Circle(const Circle& c) : m_center(c.m_center), m_radius(c.m_radius)
{ // Copy constructor
    
    // m_center = c.m_center;
    // m_radius = c.m_radius;
    cout << "Hello my circle...\n";
}

Circle::~Circle()
{ // Deconstructor
    
    cout << "Bye my circle...\n";
}


//============= Circle characteristics functions =============
Point Circle::CenterPoint() const
{ // Center point of circle
    return m_center;
}

double Circle::Radius() const
{ // Radius of circle
    return m_radius;
}

void Circle::CenterPoint(Point& new_m_center)
{
    m_center = new_m_center;
}

void Circle::Radius(double new_m_radius)
{
    m_radius = new_m_radius;
}

double Circle::Diameter() const
{ // Diameter of circle
    
    return 2.0 * m_radius;
}

double Circle::Area() const
{ // Area of circle
    
    return M_PI * m_radius * m_radius;
}

double Circle::Circumference() const
{ // Circumference of circle
    
    return 2 * M_PI * m_radius;
}

string Circle::ToString() const
{
    stringstream ss;
    ss << "Center point is Point(" << m_center.X() << "," << m_center.Y() << "); radius is " << m_radius;
    return ss.str();
}
