//
//  TestPoint.cpp
//  Exercise 4
//
//  Created by Changheng Chen on 12/8/16.
//  Copyright © 2016 Changheng Chen. All rights reserved.
//

#include "Point.hpp"
#include <iostream>

int main()
{
    const Point cp(1.5,3.9);   // Create a const point
    
    // cp.X(0.3);              // Error: cannot change a const object
    cout << cp.X() << endl;    // Make sure function X() is a const function
    
    // Print description of cp using ToString()
    cout << cp.ToString() << endl;
    
    
    // Get distance between cp and origin (0,0)
    cout << "Distance between Point(0,0) and " << cp.ToString() << " is ";
    cout << cp.Distance() << endl;
    
    // Get distance between cp and cp1
    const Point cp1(4.5,-0.1); // Create a second const point
    cout << "Distance between " << cp.ToString() << " and " << cp1.ToString() << " is ";
    cout << cp.Distance(cp1) << endl;

    return 0;
}
