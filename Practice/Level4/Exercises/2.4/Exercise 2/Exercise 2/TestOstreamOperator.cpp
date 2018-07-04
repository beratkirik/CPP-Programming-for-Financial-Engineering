//
//  TestOstreamOperator.cpp
//  Exercise 2
//
//  Created by Changheng Chen on 1/6/17.
//  Copyright © 2017 Changheng Chen. All rights reserved.
//

#include "Line.hpp"
#include "Circle.hpp"
#include <iostream>

int main()
{
    // Test Ostream << operator for class Point
    Point pt(1.0, 2.0);
    cout << pt.ToString() << endl;   // Use member function to print
    cout << pt << endl;              // Use Ostream << operator to print
    
    
    // Test Ostream << operator for class Line
    Point p1, p2(1.0, 2.0);
    Line line(p1, p2);
    cout << line.ToString() << endl; // Use member function to print
    cout << line << endl;            // Use Ostream << operator to print
    
    
    // Test Ostream << operator for class Circle
    double radius = 1.0;
    Circle c(pt, radius);
    cout << c.ToString() << endl;    // Use member function to print
    cout << c << endl;               // Use Ostream << operator to print
    
    return 0;
}
