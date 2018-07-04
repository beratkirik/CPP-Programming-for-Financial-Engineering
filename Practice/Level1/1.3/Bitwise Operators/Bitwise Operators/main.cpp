//
//  main.cpp
//  Bitwise Operators
//
//  Created by Changheng Chen on 11/4/16.
//  Copyright © 2016 Changheng Chen. All rights reserved.
//

#include <iostream>

int main()
{
    int i;
    
    i = -3;      // Left bit (sign bit) equals 1
    printf("i=%d\n", i);
    i = i >> 1;
    printf("i >> 1 evaluates to: %d \n", i);
    
    if (i < 0)
    {
        printf("Negative, a 1 was inserted left\n");
    }
    else
    {
        printf("Positive, a 0 was inserted left\n");
    }
    
    return 0;
}
