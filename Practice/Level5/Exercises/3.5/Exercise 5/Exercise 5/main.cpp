//
//  main.cpp
//  Exercise 5
//
//  Created by Changheng Chen on 1/19/17.
//  Copyright © 2017 Changheng Chen. All rights reserved.
//

#include "Line.hpp"
#include "Circle.hpp"
#include <iostream>
using namespace chako::CAD;

int main()
{ // Template Method Pattern
    
    /* "Print() does all the functionality common to all derived classes. Only the part of Print() that is different for each derived class is delegated to a polymorphic function (ToString()). This mechanism is an often used design pattern called the 'Template Method Pattern'."
     */
     
    Point p(3.0, 4.0);                        // Create a Point object
    Line l(Point(1.0, 2.0), Point(3.0, 4.0)); // Create a Line object
    Circle c(p, 1.0);                         // Create a Circle object
    
    p.Print();                                // Print info of Point p
    l.Print();                                // Print info of Line l
    c.Print();                                // Print info of Circle c
    
    return 0;
}
