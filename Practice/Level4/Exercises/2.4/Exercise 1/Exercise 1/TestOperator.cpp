//
//  TestOperator.cpp
//  Exercise 1
//
//  Created by Changheng Chen on 1/6/17.
//  Copyright © 2017 Changheng Chen. All rights reserved.
//

#include "Point.hpp"
#include "Line.hpp"
#include "Circle.hpp"
#include <iostream>
using namespace std;

int main()
{
    // (1.1) Test "operator -", "operator +", and the assignment operator
    Point p1(-1, 3);     // Create a point
    cout << "p1 is " << p1.ToString() << endl;
    Point p2(2, 2);
    p2 = p2 + (-p1);
    cout << "p2 is " << p2.ToString() << endl;
    cout << endl;
    
    
    // (1.2) Test "operator *" and "operator *="
    double f = 2.0;
    p1 *= f;
    cout << "p1 *= f gives " << p1.ToString() << endl;
    p2 = p2 * f;        // The same as p2 = f * p2;
    cout << "p2 = p2 * f gives " << p2.ToString() << endl;
    cout << endl;
    
    
    // (1.3) Test "operator =="
    cout << ((p1 == p2) ? "p1 == p2" : "p1 != p2") << endl << endl;

    
    // (2) Test assignment operator for classes Line and Circle
    Line line1 = Line(p1, p2);
    cout << "line1 is " << line1.ToString() << endl;
    Line line2 = line1;
    cout << "line2 is " << line2.ToString() << endl;
    cout << endl;
    
    Circle circle1 = Circle(p1, f);
    cout << "circle1 is " << circle1.ToString() << endl;
    Circle circle2 = circle1;
    cout << "circle2 is " << circle2.ToString() << endl;
    
    return 0;
}
