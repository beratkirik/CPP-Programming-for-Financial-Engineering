//
//  main.c
//  Exercise 7
//
//  Created by Changheng Chen on 11/4/16.
//  Copyright © 2016 Changheng Chen. All rights reserved.
//

#include <stdio.h>

int main()
{
    int i, n;
    
    printf("Enter an integer for 'i':\n");
    scanf("%d", &i);
    printf("Enter n for taking the operation 'i*2^n': \n");
    scanf("%d", &n);
    
    /* A left shift by n is equivalent to multiplying by 2n (provided the value does not overflow);
       while a right arithmetic shift by n of a two's complement value is equivalent to dividing 
       by 2n and rounding toward negative infinity. */
    
    i = i << n;
    printf("i << n results in i*2^n = %d.\n", i);
    
    return 0;
}
