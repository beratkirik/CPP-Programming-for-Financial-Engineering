//
//  main.cpp
//  Exercise 1
//
//  Created by Changheng Chen on 1/19/17.
//  Copyright © 2017 Changheng Chen. All rights reserved.
//

#include <iostream>
#include "Array.hpp"
#include "Line.hpp"
#include "Circle.hpp"
using namespace chako::CAD;
using namespace chako::Containers;

int main()
{
    // Create an Array object and access an element that does not exist. Run the program. What happens?
    
    Array arr = Array(3);                // Create an array of Point with 3 elements
    //cout << arr[-1] << endl;           // Runtime error: terminating with uncaught exception of type int
    
    try
    {
        cout << arr[3] << endl;
    }
    catch (int err)
    {
        if (err == -1)
            cout << "Array index out of bounds..." << endl;
    }
    catch(...)
    {
        cout << "An unhandled exception has occurred..." << endl;
    }
    
    cout << arr.GetElement(2) << endl;
    
    return 0;
}
