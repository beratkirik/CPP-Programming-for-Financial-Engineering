//
//  Hello.cpp
//  HelloWorld
//
//  Created by Changheng Chen on 11/2/16.
//  Copyright © 2016 Changheng Chen. All rights reserved.
//

// Preprocessor for including files
#include <stdio.h>       // C style I/O
#include <iostream>      // C++ style I/O using operator overloading
using namespace std;     // The C++ logical collection of functions

void hello_C()
{
    printf("Hello Quantnet, C style! \n");
}

void hello_CPP()
{
    // Using (binary) operator overloading
    cout << "Hello Quantnet, C++ style! \n";
}
