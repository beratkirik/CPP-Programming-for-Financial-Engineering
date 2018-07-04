//
//  main.cpp
//  Exercise 3
//
//  Created by Changheng Chen on 1/6/17.
//  Copyright © 2017 Changheng Chen. All rights reserved.
//

#include "Point.hpp"
#include <iostream>
using namespace std;

int main()
{
    /* //Without explicit specifier, the code compiles and output is "Equal!", as
    "Point constructor with the single double argument is implicitly used to
    convert the number in the if statement to a Point object. Thus constructors
    are used as implicit conversion operators."
    
    Point p(1.0, 1.0);
    if (p == 1.0)
        cout << "Equal!" << endl;
    else
        cout << "Not equal" <<endl; */
    
    Point p(1.0, 1.0);
    cout << p << endl;
    cout << (Point)1.0 << endl;
    
    if (p == (Point)1.0)
        cout << "Equal!" << endl;
    else
        cout << "Not equal" <<endl;
    
    return 0;
}
