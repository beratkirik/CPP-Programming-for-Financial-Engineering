//
//  main.cpp
//  Exercise 1
//
//  Created by Changheng Chen on 1/6/17.
//  Copyright © 2017 Changheng Chen. All rights reserved.
//

#include "Point.hpp"
#include <iostream>

int main()
{
    // Pointers to objects
    Point *p1, *p2, *p3;
    p1 = new Point;                       // Default constructor
    p2 = new Point(1.0);                  // Constructor (explicit)
    p3 = new Point(3.0, 4.0);             // Constructor with coordinates
    Point *p4 = new Point(*p3);           // Copy constructor
    
    cout << (*p1).Distance(*p4) << endl;  // Distance between p1 and p4
    cout << (*p2).Distance() << endl;     // Distance between p2 and origin
    cout << *p3 << endl;                  // Print p3
    
    delete p1; delete p2; delete p3; delete p4;
    
    
    /*
    // Compiler error: Arrays on the stack must have the size set at compile time.
    int N;
    cout << "Enter the size of the array of points to be created: " << endl;
    cin >> N;
    
    // Create array on the stack
    Point pp[N];    // Error: Variable length array of non-POD element type 'Point'
    cout << pp[1] << endl;
     */
    
    
    // Pointers to arrays
    int N = 10;
    Point *pp;
    pp = new Point[N];                    // Cannot call other than default constructor
    cout << pp[0];                        // Contrast: cout << *pp[0] << endl in Exercise 2
    delete [] pp;
    
    return 0;
}
