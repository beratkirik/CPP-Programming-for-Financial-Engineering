//
//  main.cpp
//  Exercise 2
//
//  Created by Changheng Chen on 1/19/17.
//  Copyright © 2017 Changheng Chen. All rights reserved.
//

#include <iostream>
#include "OutOfBoundsException.hpp"
#include "Array.hpp"
#include "Shape.hpp"
#include "Point.hpp"
using namespace std;
using namespace chako::CAD;
using namespace chako::Containers;

int main()
{
    Array arr = Array(3);                // Create an array of points with 3 elements
    
    try
    {
        cout << arr[3] << endl;          // Access an element out of bounds
    }
    catch (ArrayException& ex)           // Catch exception object
    {
        cout << ex.GetMessage() << endl; // Print the error message
    }
    catch(...)
    {
        cout << "An unhandled exception has occurred..." << endl;
    }
    
    cout << arr.GetElement(2) << endl;   // An extra test after catching exception object...
    
    return 0;
}
