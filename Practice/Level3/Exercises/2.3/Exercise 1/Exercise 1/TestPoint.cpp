//
//  TestPoint.cpp
//  Exercise 1
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
    
    // Create a point and set the coordinates to (m_x,m_y)
    Point p1; p1.SetX(m_x); p1.SetY(m_y);
    
    // Create a second point using constructor Point(double newx, double newy)
    Point p2(4.0,5.0);                         // Choose an arbitrary coordinate
    double distance = p1.Distance(p2);         // Distance between p1 and p2
    
    cout << "Distance between " << p1.ToString() << " and " << p2.ToString() << " is ";
    cout << distance << endl;
    
    
    /* Without declaring copy constructor Point(const Point& p):
       A third point besides p1 and p2 is "constructed" by copying p2 to
       the stack by Distance(Point p) without calling any constructor.
       But deconstructor ~Point() is called three times to free
       p1, p2, and the third point from the stack.
       Thus, constructors are called twice to create p1 and p2, and
       ~Point() is called three times to free all the three points.
    
       While with declaring copy constructor Point(const Point& P):
       Each of the three constructors is called once, and deconstructor 
       is called three times. 
       Thus, the number of constructor calls now is the same as
       the number of destructor calls. */
    
    /* "When calling the Distance() function, the input point is copied (call by value).
       You will get the copy constructor 'for free' when you do not create one yourself." */
    
    return 0;
}
