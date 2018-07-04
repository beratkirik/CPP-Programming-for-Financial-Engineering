//
//  Point.cpp
//  2.3
//
//  Header file for Points in two dimensions. A given Point has 3 coordinates
//  for compatibility with other systems. However, it is not possible to
//  influence the third coordinate and futhermore, the delivered functionality
//  is typically two-dimensional.
//
//  Last Modifications:
//  2016-12-02 Copy this file from QuantNet
//
//  Created by Changheng Chen on 12/2/16.
//  Copyright © 2016 Changheng Chen. All rights reserved.
//

#include "Point.hpp"
#include <cmath>

Point::Point() : x(0), y(0)  // Colon syntax!!!!! more efficient way of initialization
{// Default constructor
    
  //  x = y = 0.0;    // do not have to declare x, y again, since they are data member
}

Point::Point(double newx, double newy): x(newx), y(newy)
{// Initialize using newx and newy
    
  //  x = newx;
  //  y = newy;
}

Point::~Point()
{// Des...
    
    cout << "bye my point...\n";
}

double Point::X() const  // change along with X in *.hpp
{
    return x;
}

void Point::X(double newX)
{
    x = newX;
}

double Point::Y() const // change along with Y in *.hpp
{
    return y;
}

void Point::Y(double newY)
{
    y = newY;
}
