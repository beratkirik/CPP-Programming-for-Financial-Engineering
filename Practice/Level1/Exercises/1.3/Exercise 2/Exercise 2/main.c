//
//  main.c
//  Exercise 2
//
//  Created by Changheng Chen on 11/3/16.
//  Copyright © 2016 Changheng Chen. All rights reserved.
//

#include <stdio.h>

int main()
{
    double base, height, surface;
    
    // Get height from user input
    printf("Please enter value of height\n");
    scanf("%lf",&height);
    
    // Get base from user input
    printf("Please enter value of base\n");
    scanf("%lf",&base);
    
    // Calculate surface
    surface = base * height / 2.0;
    
    printf("The surface of the tirangle is %f\n", surface);
    
    return 0;
}
