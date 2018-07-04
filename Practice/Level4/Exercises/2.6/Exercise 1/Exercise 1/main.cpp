//
//  main.cpp
//  Exercise 1
//
//  Created by Changheng Chen on 1/7/17.
//  Copyright © 2017 Changheng Chen. All rights reserved.
//

#include <iostream>
#include "Line.hpp"
#include "Circle.hpp"
#include "Array.hpp"

int main()
{
   /*
    Full class name including namespace for the Point used in the Array class. 
    Note that you can use only the CAD part of the namespace without the YourName part 
    because the Point is also in the YourName namespace.
    
    In the main program, 
    1) the full namespace for Point class.
    2) using declaration for using a single class (Line).
    3) using declaration for a complete namespace (Containers).
    4) using the Circle class by creating a shorter alias for the YourName::CAD namespace. 
    */
    
    
    // 1) Explicit access qualification
    chako::CAD::Point p(3.0, 4.0);    // Create a point p
    cout << "Distance of " << p << "from the origin is " << p.chako::CAD::Point::Distance() << endl;
    
    // 2) Using declaration
    using chako::CAD::Line;
    Line l;                           // Create a line l
    l.Line::P2(p);                    // Set end point to p
    cout << "\nMidle point of l is " << l.Line::midPoint() << endl;
    
    // 3) Using directive
    using namespace chako::Containers;
    Array arr1 = Array(3);            // Create an array of points with 3 elements
    arr1.SetElement(0, p);            // Set the first element to p
    cout << "\narr1[0] becomes " << arr1.GetElement(0) << endl;
    
    // 4) Alias namespaces
    namespace CC = chako::CAD;        // Create an alias for namespace chako::CAD
    double r = 1.0;                   // Define radius of circle
    CC::Circle c(p, r);               // Create a circle at p and with radius r
    cout << "\nArea of the circle is " << c.CC::Circle::Area() << endl;
    
    return 0;
}
