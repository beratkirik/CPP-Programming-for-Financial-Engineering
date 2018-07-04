//
//  main.c
//  Exercise 4
//
//  Created by Changheng Chen on 11/11/16.
//  Copyright © 2016 Changheng Chen. All rights reserved.
//

#include <stdio.h>

void printnumber(long int i)
{ // Create a recursive function to print nubmer digit by digit
    
    if (i<0)
    { // Print '-' first, if number is negative
        
        i = -i;
        putchar('-');
        printf("\n");
    }
    
    if (i/10)
    { // Determine the digit to print
        
        printnumber(i/10);
    }
    
    // Use % to calculate the argument for the recursive call
    // Convert a digit to the corresponding character by simply adding '0':
    putchar(i%10+'0');
    printf("\n");
}


int main()
{
    long int i;
    
    printf("Enter an integer for printing: \n");
    scanf("%ld", &i);
    
    printnumber(i);
    
    return 0;
}
