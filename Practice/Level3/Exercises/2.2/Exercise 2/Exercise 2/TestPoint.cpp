//
//  TestPoint.cpp
//  Exercise 2
//
//  Created by Changheng Chen on 12/8/16.
//  Copyright © 2016 Changheng Chen. All rights reserved.
//

#include "Point.hpp"
#include <iostream>
using namespace std;

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
    cout << endl;
    
    // Get distance between (0,0) and p1
    cout << "Distance between Point(0,0) and " << p1.ToString() << " is " << p1.DistanceOrigin() << endl;
    
    // Get distance between p1 and p2(4.0,5.0) (created arbitrarily)
    Point p2;
    p2.SetX(4.0);
    p2.SetY(5.0);
    cout << "Distance between " << p1.ToString() << " and " << p2.ToString() << " is " << p1.Distance(p2) << endl;
    
    return 0;
}
