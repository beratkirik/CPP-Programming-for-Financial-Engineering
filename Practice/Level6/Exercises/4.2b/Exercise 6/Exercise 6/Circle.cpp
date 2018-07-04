//
//  Circle.cpp
//  Exercise 6
//
//  Created by Changheng Chen on 2/2/17.
//  Copyright © 2017 Changheng Chen. All rights reserved.
//

#include "Circle.hpp"
#include <iostream>       // std::cout
#include <sstream>        // std::stringstream
#include <cmath>          // M_PI
#define _USE_MATH_DEFINES

namespace chako
{
    namespace CAD
    {
        //================ Constructors and destructor ================
        Circle::Circle() : Shape(), m_center(), m_radius(0)
        { // Default constructor
            
            //cout << "Hello my circle...\n";
        }
        
        Circle::Circle(Point center, double radius) : Shape(), m_center(center), m_radius(radius)
        { // Constructor
            
            //cout << "Hello my circle...\n";
        }
        
        Circle::Circle(const Circle& c) : Shape(c), m_center(c.m_center), m_radius(c.m_radius)
        { // Copy constructor
            
            //cout << "Hello my circle...\n";
        }
        
        Circle::~Circle()
        { // Deconstructor
            
            //cout << "Bye my circle...\n";
        }
        
        Circle& Circle::operator = (const Circle& source)
        { // Assignment operator
            
            if (this == &source)
                return *this;
            
            Shape::operator = (source);
            
            m_center = source.m_center;
            m_radius = source.m_radius;
            
            return *this;
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
        
        void Circle::CenterPoint(const Point& new_m_center)
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
            ss << Shape::ToString() << ". Center point is Point("
            << m_center.X() << "," << m_center.Y() << "); radius is "
            << m_radius;
            
            return ss.str();
        }
        
        ostream& operator << (ostream& os, const Circle& c)
        {
            return os << c.ToString();  // An alternative method
        }
        
        void Circle::Draw() const
        {
            cout << "Drawing circle..." << endl;
        }
    }
}
