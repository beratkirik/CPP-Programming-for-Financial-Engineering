//
//  main.cpp
//  quiz4
//
//  Created by Changheng Chen on 3/14/17.
//  Copyright © 2017 Changheng Chen. All rights reserved.
//

#include <iostream>

struct MyStruct
{
    char c[5];
    short s;
};

int main()
{
    //struct MyStruct s={"Hello World", 14}; // Error: Initializer-string for char array is too long;
    //printf("%d\n", sizeof(s));
    
    struct MyStruct s={"Hell", 14}; // Initializer-string for char array is too long, should be 4 chars
    printf("%lu\n", sizeof(s)); // 8, system dependent
    
    
    int* p1, p2; // p1 is a variable containing a pointer to an int. p2 contains an int directly.
    p2 = 10;
    p1 = &p2;
    
    std::cout << *p1 << std::endl;
}
