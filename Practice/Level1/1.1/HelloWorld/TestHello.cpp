//
//  TestHello.cpp
//  HelloWorld
//
//  Created by Changheng Chen on 11/2/16.
//  Copyright © 2016 Changheng Chen. All rights reserved.
//

// Showing how to call a function from another file in the main function.

#include "Hello.hpp"     // User-defined include file

int main()               // Return type of main() expects and int
{
    hello_C();           /* In C */
    
    hello_CPP();         // In C++
    
    return 0;
}
