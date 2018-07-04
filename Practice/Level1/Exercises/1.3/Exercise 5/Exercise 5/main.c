//
//  main.c
//  Exercise 5
//
//  Created by Changheng Chen on 11/4/16.
//  Copyright © 2016 Changheng Chen. All rights reserved.
//
//  This code intends to show the clear difference between --i and i--.

#include <stdio.h>

int main(int argc, const char * argv[])
{
    int i = 1;
    int x;
    
    // Value of i will not be decreased before assignment
    // After expression value of i is decreased
    x = i--;  // x = i = 1; i = i-1 = 1-1 = 0
    printf("Operation is x = i--. Then, x and i become %d, %d \n", x, i); // 1, 0
    
    // Value of i is decreased before assignment
    x = --i;  // i = i-1 = 0-1 = -1; x = -1
    printf("Operation is x = --i. Then, x and i become %d, %d \n", x, i); // -1, -1
    
    return 0;
}
