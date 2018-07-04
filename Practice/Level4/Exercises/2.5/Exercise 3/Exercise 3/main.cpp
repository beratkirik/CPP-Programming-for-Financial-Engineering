//
//  main.cpp
//  Exercise 3
//
//  Created by Changheng Chen on 1/6/17.
//  Copyright © 2017 Changheng Chen. All rights reserved.
//

#include "Array.hpp"
#include <iostream>

int main()
{
    // Test constructors and assignment operator
    Array arr1;           // Default constructor
    cout << "Default constructor tested. \n" << endl;
    
    Array arr2(3);        // Constructor with size
    cout << "Constructor with size tested. \n" << endl;

    Array arr3(arr2);     // Copy constructor
    cout << "Copy constructor tested. \n" << endl;
    
    cout << "Size of arr1: " << arr1.Size() << endl;
    arr1 = arr3;          // Assignment operator, different sizes!!
    cout << "Size of arr1: " << arr1.Size() << endl;
    cout << "Assignment operator tested. \n" << endl;
    
    
    // Test getter and setter functions
    cout << "arr1[0]: " << arr1.GetElement(0) << endl;   // Get the 1st element
    
    Point p1(3.0, 4.0);
    arr1.SetElement(2, p1);                              // Set the 3rd element to p1
    cout << "arr1[2]: " << arr1.GetElement(2) << endl;
    
    
    // Test square bracket operator function
    Point p2 = arr1[1];        // Read the 2nd element and set it to p2
    cout << p2 << endl;

    cout << p1 << endl;
    arr1[2] = p1;              // Call the non-constant operator []
    cout << arr1[2] << endl;
    
    /* const Point& operator [] (int index) const;
       returns constant reference to Point, whose value cannot be changed, and
       will not modify any data member of the class.
       By using the "const" qualifiers, the array elements cannot be changed. */
    
    return 0;
}
