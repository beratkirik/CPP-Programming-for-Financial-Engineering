//
//  main.c
//  Exercise 1
//
//  Created by Changheng Chen on 11/17/16.
//  Copyright © 2016 Changheng Chen. All rights reserved.
//

#include <stdio.h>

int main()
{
    int c;
    
    printf("Enter characters: \n");
    while ((c = getchar()) != 1)
    {
        putchar(c);
    }
    
    // WARNING: Press "CTRL + A" first, THEN press "Enter" to terminate
    if (c == 1) printf("CTRL + A is a correct ending.\n");
    
    return 0;
}
