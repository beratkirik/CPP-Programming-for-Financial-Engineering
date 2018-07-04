//
//  Point.cpp
//  QN_Boost_V1
//
//  Created by Changheng Chen on 2/7/17.
//  Copyright © 2017 Changheng Chen. All rights reserved.
//

#include "Point.hpp"
#include <cmath>

Point::Point() : x(0), y(0) // Colon syntax!!!!!!!!!!!!!!!!!
{// Default constructor
    
    //      x = y =0.0;
}

Point::Point(double newx, double newy) : x(newx), y(newy)
{// Initialize using newx and newy
    
    /*      x = newx;
     y = newy;*/
}
Point::~Point()
{// Des...
    
    cout << "bye my point..\n";
}

double Point::X() const
{
    return x;
}

void Point::X(double newX)
{
    x = newX;
}


double Point::Y() const
{
    return y;
}

void Point::Y(double newY)
{
    y = newY;
}

ostream& operator << (ostream& os, const Point& pt)
{
    
    os << "(" << pt.x << "," << pt.y << ")";
    return os;
}
