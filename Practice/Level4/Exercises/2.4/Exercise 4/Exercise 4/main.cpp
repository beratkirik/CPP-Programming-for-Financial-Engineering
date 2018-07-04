//
//  main.cpp
//  Exercise 4
//
//  Created by Changheng Chen on 1/6/17.
//  Copyright © 2017 Changheng Chen. All rights reserved.
//

#include "Point.hpp"
#include <iostream>

int main()
{
    // Test Ostream << operator for class Point
    Point pt(1.0, 2.0);
    cout << pt.ToString() << endl;   // Use member function to print
    cout << pt << endl;              // Use Ostream << operator to print
    
    return 0;
}
