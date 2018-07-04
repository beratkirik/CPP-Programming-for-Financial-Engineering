//
//  TestPoint.cpp
//  Exercise 3
//
//  Created by Changheng Chen on 12/8/16.
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
    
    // Create a point and set the coordinates to (m_x,m_y)
    Point p1; p1.X(m_x); p1.Y(m_y);
    
    // Print description of p1 using ToString()
    cout << p1.ToString() << endl;
    
    // Print description of p1 using GetX() and GetY()
    cout << "Point(" << p1.X() << "," << p1.Y() << ")" << endl;
    
    // Get distance between (0,0) and p1
    cout << "Distance between Point(0,0) and " << p1.ToString() << " is ";
    cout << p1.Distance() << endl;
    
    // Get distance between p1 and p2(4.0,5.0) (created arbitrarily)
    Point p2(4.0,5.0);
    cout << "Distance between " << p1.ToString() << " and " << p2.ToString() << " is ";
    cout << p1.Distance(p2) << endl;
    
    return 0;
}
