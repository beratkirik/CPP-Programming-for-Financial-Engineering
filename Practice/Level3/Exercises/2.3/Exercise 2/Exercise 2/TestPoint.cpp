//
//  TestPoint.cpp
//  Exercise 2
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
    Point p1; p1.SetX(m_x); p1.SetY(m_y);
    
    Point p2(4.0,5.0);                     // Choose an arbitrary coordinate
    double distance = p1.Distance(p2);     // Distance between p1 and p2
                                           // Same statement for both call by reference and value!
    
    cout << "Distance between " << p1.ToString() << " and " << p2.ToString() << " is ";
    cout << distance << endl << endl;
    
    /* Distance(const Point& p):
       Point p is passed to Distance() “by reference” so that no copy is made, and 
       “const reference” means p cannot be changed within the Distance() function. */
    
    return 0;
}
