//
//  main.cpp
//  Exercise 7
//
//  Created by Changheng Chen on 12/9/16.
//  Copyright © 2016 Changheng Chen. All rights reserved.
//

#include "Point.hpp"
#include <iostream>
using namespace std;

int main()
{
    // Create a point at origin
    Point p1;
    cout << "p1 is " << p1.ToString() << endl;
    cout << endl;
    
    // Test setter function (default inline)
    cout << "Testing default inline function..." << endl;
    p1.X(1.2); p1.Y(3.4);
    cout << "p1 is " << p1.ToString() << endl;
    cout << endl;
    
    // Test getter function (normal inline)
    cout << "Testing normal inline function..." << endl;
    cout << "x-coordinate of p1 is " << p1.X() << endl;
    cout << "y-coordinate of p1 is " << p1.Y() << endl;
    cout << endl; 

    return 0;
}
