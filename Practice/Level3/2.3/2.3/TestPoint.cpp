//
//  TestPoint.cpp
//  2.3
//
//  Simple examples of using Point class. NOT all fucntionality in there yet.
//
//  Created by Changheng Chen on 12/2/16.
//  Copyright © 2016 Changheng Chen. All rights reserved.
//

#include "Point.hpp"
#include "LineSegment.hpp"

#include <iostream>
using namespace std;

//void print(Point pt) // otherwise create a new point by copying to the stack
//*void print(Point& pt)
void print(const Point& pt)
{
    cout << "(" << pt.X() << "," << pt.Y() << ")" << endl;  // X(), Y() have to be const for this to work
    //pt.X(1111111); //*
}

int main()
{
    // Create a point
    Point p1;
    
    double d = p1.X();
    
    cout << d << endl;
    
    Point p2(1.0, 2.0);
    cout << "(" << p2.X() << "," << p2.Y() << ")" << endl;
    
    cout << "(" << p2.X() << "," << p2.Y() << ")" << endl;
    print(p2);  // creates 1 point, call by value
    
    // LineSegment
   // LineSegment L1(p2, p2);  // creates 2 points
    
    return 0;
}
