//
//  TestPoint.cpp
//  Exercise 1
//
//  A test program for the Point class.
//
//  Created by Changheng Chen on 12/2/16.
//  Copyright © 2016 Changheng Chen. All rights reserved.
//

#include "Point.hpp"
#include <iostream>

int main()
{
    // Get x- and y-coordinate from user input
    double m_x, m_y;
    cout << "Enter x- and y-coordinate for Point(x,y): " << endl;
    cin >> m_x >> m_y;
    
    // Create a point
    Point p1;
    
    // Set the coordinates to (m_x,m_y)
    p1.SetX(m_x);
    p1.SetY(m_y);
    
    // Print description of p1 using ToString()
    cout << p1.ToString() << endl;
    
    // Print description of p1 using GetX() and GetY()
    cout << "Point(" << p1.GetX() << "," << p1.GetY() << ")" << endl;
    
    return 0;
}
