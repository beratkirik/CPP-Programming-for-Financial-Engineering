//
//  main.c
//  Exercise 8
//
//  Created by Changheng Chen on 11/4/16.
//  Copyright © 2016 Changheng Chen. All rights reserved.
//

#include <stdio.h>

int main()
{
    int x=2;
    int y;
    int z;
    
    x*=3+2;
    printf("x=%d\n", x); // x = x*(3+2) = 2*(3+2) = 10
    
    x*=y=z=4;
    printf("x=%d\n", x); // z = 4; y = z = 4; x = x*y = 10*4 = 40
    
    x=y==z;
    printf("x=%d\n", x); // y==z (4==4) evaluates as 1; x = 1
}
