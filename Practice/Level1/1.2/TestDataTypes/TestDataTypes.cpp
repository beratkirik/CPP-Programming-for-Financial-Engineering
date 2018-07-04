//
//  TestDataTypes.cpp
//
//  Created by Changheng Chen on 11/2/16.
//  Copyright © 2016 Changheng Chen. All rights reserved.
//
//
//  Initial encounters with basic data types. Note that we use iostream
//  library for I/O operations.
//
//  You get an idea of data types and their limits.
//

#include <limits.h>  // Least and greatest representation of integer types
#include <float.h>   // Least and greatest representation of floating point types
#include <iostream>  // C++ style
#include <stdio.h>   // C style
using namespace std;

int main()
{
    // Test with C style printing
    printf("V1: %d, V2: %f\n", 10, 30.0);
    printf("value1 = %d, value2 = %f\n", 10, 20.0);
    cout << endl;
    
    // Create some variables and their values
    typedef int feet;     // Create a new name for the existing type "int"
    feet i = 42;
    long index = 0L;
    
    double d1 = 2564.45677;
    double d2 = 3.1415*d1;
    
    cout << "Values: " << i << ", " << index << ", " << d2 << ", " << d2*i << endl << endl;
    
    
    // Enumerated types: enum enum-name { list of names } var-list;
    enum color {red, yellow=5, green} r, y, g;
    double re, ye, gr;    // Define variables in a seperate line with a different type??
    r = red;
    y = yellow;
    g = green;
    
    re = red;
    ye = yellow;
    gr = green;
    
    cout << r << ", " << re << ", " << y << ", " << g << endl << endl;
    
    
    // Some limits of basic data types
    cout << "int characteristics: " << sizeof(int) << ", " << INT_MIN << ", " << INT_MAX << endl;
    cout << "long characteristics: " << sizeof(long) << ", " << LONG_MIN << ", " << LONG_MAX << endl;
    cout << "float characteristics: " << sizeof(float) << ", " << FLT_MIN << ", " << FLT_MAX << endl;
    cout << "double characteristics: " << sizeof(double) << ", " << DBL_MIN << ", " << DBL_MAX << endl;
    cout << "long double characteristics: " << sizeof(long double) << ", " << LDBL_MIN << ", " << LDBL_MAX << endl << endl;
    
    
    // Some other tests
    cout << "Size of char : " << sizeof(char) << endl;
    cout << "Size of int : " << sizeof(int) << endl;
    cout << "Size of short int : " << sizeof(short int) << endl;
    cout << "Size of long int : " << sizeof(long int) << endl;
    cout << "Size of float : " << sizeof(float) << endl;
    cout << "Size of double : " << sizeof(double) << endl;
    cout << "Size of wchar_t : " << sizeof(wchar_t) << endl << endl;

    
    // What happens here? Put a big number in too small a space..
    float f = FLT_MAX + 100000.0;   // No effect
    cout << f << endl;              // Can also replace endl with \n
    
    return 0;
}
