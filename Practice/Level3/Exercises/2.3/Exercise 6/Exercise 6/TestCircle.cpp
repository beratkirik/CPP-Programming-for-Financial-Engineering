//
//  TestCircle.cpp
//  Exercise 6
//
//  Created by Changheng Chen on 12/9/16.
//  Copyright © 2016 Changheng Chen. All rights reserved.
//

#include "Circle.hpp"
#include <iostream>

int main()
{
    // Create an arbitrary circle
    Point p1;           // Point at origin
    Circle c(p1,1.0);   // Circle with radius = 1 at origin
    cout << endl;
    
    // Print basic info of circle (center point and radius) in two different ways
    cout << c.ToString() << endl;                     // Use ToString()
    
    cout << "Center point is ";                       // Alternatively, use CenterPoint() and Radius()
    cout << (c.CenterPoint()).ToString() << "; ";     // Use anonymous object, same as the former two lines
    cout << "radius is " << c.Radius() << endl;
    cout << endl; 
    
    // Change circle setting
    Point p2(1.0,2.0);
    c.CenterPoint(p2); c.Radius(2.5);
    cout << "New circle: " << c.ToString() << endl;
    
    // Print characteristics of circle
    cout << "Diameter is " << c.Diameter() << endl;
    cout << "Area is " << c.Area() << endl;
    cout << "Circumference is " << c.Circumference() << endl;
    cout << endl;
    
    return 0;
}
