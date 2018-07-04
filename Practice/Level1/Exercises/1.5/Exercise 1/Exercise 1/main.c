//
//  main.c
//  Exercise 1
//
//  Created by Changheng Chen on 11/11/16.
//  Copyright © 2016 Changheng Chen. All rights reserved.
//

#include <stdio.h>

double minus(double num1, double num2)
{ // Create a minus function
    
    return num1 - num2;
}

int main()
{
    double a = 3.14;
    double b = 6.28;
    
    printf("%f - %f = %f \n", a, b, minus(a, b));
    
    return 0;
}
