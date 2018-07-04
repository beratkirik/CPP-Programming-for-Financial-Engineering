//
//  Line.cpp
//  Exercise 1
//
//  Created by Changheng Chen on 1/19/17.
//  Copyright © 2017 Changheng Chen. All rights reserved.
//

#include "Line.hpp"
#include <iostream>   // std::cout
#include <sstream>    // std::stringstream

namespace chako
{
    namespace CAD
    {
        // (0) Constructors and destructor
        Line::Line() : Shape(), startPoint(), endPoint()
        {
            //cout << "Line default constructor...\n";
        }
        
        Line::Line(const Point& p1, const Point& p2) : Shape(), startPoint(p1), endPoint(p2)
        {
            //cout << "Line constructor...\n";
        }
        
        Line::Line(const Line& l) : Shape(l), startPoint(l.startPoint), endPoint(l.endPoint)
        {
            //cout << "Line copy constructor...\n";
        }
        
        Line::~Line()
        {
            //cout << "Bye my line...\n";
        }
        
        Line& Line::operator = (const Line& source)
        { // Assignment operator
            
            if (this == &source)
                return *this;
            
            Shape::operator = (source);
            
            startPoint = source.startPoint;
            endPoint = source.endPoint;
            
            return *this;
        }
        
        
        // (1) Getter and setter functions
        Point Line::P1() const    // Start point
        {
            return startPoint;
        }
        
        Point Line::P2() const    // End point
        {
            return endPoint;
        }
        
        void Line::P1(const Point& pt)
        {
            startPoint = pt;
        }
        
        void Line::P2(const Point& pt)
        {
            endPoint = pt;
        }
        
        
        // (2) String description function
        string Line::ToString() const
        { // Delegation: using X() and Y() on embedded Point objects
            
            stringstream ss;
            ss << "Line: startPoint(" << startPoint.X() << "," << startPoint.Y() << "), " << "endPoint(" << endPoint.X() << "," << endPoint.Y() << ")";
            
            return ss.str();   // Retrieve the string from the string buffer
        }
        
        
        // (3) Length function
        double Line::Length() const
        { // Delegation: using Distance() on embedded Point objects
            
            return startPoint.Distance(endPoint);
        }
        
        
        // (4) Midpoint function
        Point Line::midPoint() const
        { // Delegation: using X() and Y() on embedded Point objects

            return Point((startPoint.X() + endPoint.X())/2, (startPoint.Y() + endPoint.Y())/2);
        }
        
        
        // (5) Ostream << operator
        ostream& operator << (ostream& os, const Line& l)
        {
            return os << l.ToString();
        }
    }
}
