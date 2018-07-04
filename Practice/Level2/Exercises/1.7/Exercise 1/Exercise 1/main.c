//
//  main.c
//  Exercise 1
//
//  Created by Changheng Chen on 11/17/16.
//  Copyright © 2016 Changheng Chen. All rights reserved.
//

#include <stdio.h>

void Swap(int* i, int* j)
{
    int temp;
    
    temp = *i;
    *i = *j;
    *j = temp;
}

int main()
{
    int i = 123, j = 456;
    
    printf("Before swap: i = %d, j = %d.\n", i, j);
    Swap(&i, &j);
    printf("After swap: i = %d, j = %d.\n", i, j);
    
    return 0;
}
