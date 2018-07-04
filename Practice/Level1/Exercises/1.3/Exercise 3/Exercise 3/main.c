//
//  main.c
//  Exercise 3
//
//  Created by Changheng Chen on 11/3/16.
//  Copyright © 2016 Changheng Chen. All rights reserved.
//

#include <stdio.h>

int main()
{
    int x;
    
    x = -3+4*5-6;
    printf("x = %d\n", x);  // x = 11; -3+20-6 = 17-6 = 11
    
    x = 3+4%5-6;
    printf("x = %d\n", x);  // x = 1;  3+4-6 = 7-6 = 1
    
    x = -3*4%-6/5;
    printf("x = %d\n", x);  // x = 0;  -12%(-6)/5 = 0/5 = 0
    
    x = (7+6)%5/2;
    printf("x = %d\n", x);  // x = 1;  13%5/2 = 3/2 = 1
    
    return 0;
}
