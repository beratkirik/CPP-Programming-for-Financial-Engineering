//
//  TestVariables.cpp
//
//  Created by Changheng Chen on 11/3/16.
//  Copyright © 2016 Changheng Chen. All rights reserved.
//
//  1. Declaring and initializing variables
//  2. Using operators
//  3. Postfix/prefix operators
//  4. Expressions and precedence

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <float.h>

using namespace std;

int main()
{
    // PART I: test converstions
    double D1 = 1.004;
    double D2 = 1.00004e+3;
    float f1, f2;
    int i1, i2;

    f1 = D1;
    f2 = D2;
    i1 = D1;
    i2 = D2;

    printf("Assigning float to 1.004 is %f\n", f1);        // 1.004000
    printf("Assigning float to 1.00004e+3 is %f\n", f2);   // 1000.039978

    printf("Assigning int to 1.004 is %d\n", i1);          // 1
    printf("Assigning int to 1.00004e+3 is %d\n", i2);     // 1000



    // PART II: test variables
    // Random tests
    double a = 1/2;
    cout << "Value of a: " << a << endl;  // 0

    a = 1.0;  // Reset
    a /= 0;   // inf
    cout << "Value of a: " << a << endl;

    
    // Arithmetic operator
    double d1 = 3.1415; double d2 = -2.0; double d3 = 2.71;
    double d4;
    
    d4 = d1 + d2/d3; cout << d4 << endl;
    d4 = (d1 + d2)/d3; cout << d4 << endl;
    
    
    // Combined assignment operators
    d4 += d1;    // d4 = d4 + d1 // less efficient
    d3 *= d2;    // d3 = d3 * d2 // less efficient
    
    
    // Prefix/postfix
    int i = 3;
    int j = ++i; cout << j << ", " << i << endl;  // 4, 4
    
    i =3;
    int k = i++; cout << k << ", " << i << endl;  // 3, 4
    
    // Comma operator
    int y = 5;
    int c;
    
    c = y +=4, y + 5;      // Don't use comma operator in practice!
    
    cout << "Value of c: " << c << endl;  // 9
    cout << "Value of y: " << y << endl;  // 9
    
    y = 5; // Reset
    int c2 = (y +=4, y+5);
    cout << "Value of c2: " << c2 << endl;  // 14
    cout << "Value of  y: " <<  y << endl;  // 9

    // Replacing "," with ";"
    y = 5; // Reset
    int d = y +=4; y + 5;
    cout << "Value of d: " << d << endl;  // 9
    cout << "Value of y: " << y << endl;  // 9

    return 0;
}
