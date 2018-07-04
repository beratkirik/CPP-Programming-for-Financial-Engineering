//
//  TestUnion.cpp
//  Tuple
//
//  Simple case to show how C union works. Later we discuss
//  Boost variant which is a type-safe version of union.
//
//  Created by Changheng Chen on 2/7/17.
//  Copyright © 2017 Changheng Chen. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;

/* Union is a data structure, which contains a number of elements, 
   but only one is active at any moment of time. */

union NumericDataType
{ // Union with three members
    
    int      i;
    float    f;
    double   d;
};

int main()
{
    NumericDataType Values; 
    
    Values.i = 10;
    cout << "Integer: " << Values.i << endl; // Prints 10
    
    Values.f = 1.098f;
    cout << "Float: " << Values.f << endl; // Prints 1.098
    
    Values.d = 3.1415;
    cout << "Correct double: " << Values.d << endl; // Prints 3.1415
    
    // The variables i and f will not have correct values
    // because the 'd' field is active;
    cout << "Incorrect float: " << Values.f << endl;
    cout << "Incorrect integer: " << Values.i << endl;
    
    NumericDataType Values2 = { 2 };  // Another way to initialize a union
    //NumericDataType Values3 = { 2.71 }; //Type 'double' cannot be narrowed to 'int' in initializer list
                                          // { static_cas<nt>(2.71) }
    return 0;
}
