//
//  Point.hpp
//  2.3
//
//  Header file for Points in two dimensions. A give Point has 3 coordinates
//  for compatibility with other systems. However, it is not possible to
//  influence the third coordinate and furthermore, the delivered functionality
//  is typically two-dimensional.
//
//  Created by Changheng Chen on 12/2/16.
//  Copyright © 2016 Changheng Chen. All rights reserved.
//

#ifndef Point_HPP
#define Point_HPP

#include <iostream>
using namespace std;

class Point
{
private:
    double x;   // X coordinate
    double y;   // Y coordinate
    
public:
    // Constructors and destructor
    Point();                              // Default constructor
    Point(double xval, double yval);      // Initialize with x and y value
    
    ~Point();
    
    // Accessing functions
    double X() const;                // The x-coordinate
    void X(double newX);
    double Y() const;                // The y-coordinate
    void Y(double newY);
};

#endif // Point_HPP

// V2
// Accessing functions
/*double getX() const;         // The x-coordinate
 void setX(double newX);
 double getY() const;          // The y_coordinate
 void setY(double newY);
 
 double Distance(const Point& pt) const;
 Point Add(const Point& pt) const;*/
