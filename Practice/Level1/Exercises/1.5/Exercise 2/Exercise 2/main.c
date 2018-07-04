//
//  main.c
//  Exercise 2
//
//  Created by Changheng Chen on 11/11/16.
//  Copyright © 2016 Changheng Chen. All rights reserved.
//

#include <stdio.h>

// Return type should be long, or even long long (to allow for larger results)
long long unsigned factorial(unsigned int n) // 'unsigned int' precludes negatives
{ // Create a recursive factorial function
    
    if (n == 0)
    {
        return 1;
    }
    
    return factorial(n-1) * n;
}

int main()
{
    unsigned int n;
    
    printf("Enter an integer to calculate its factorial: \n");
    scanf("%d", &n);
    
    printf("%u! = %llu \n", n, factorial(n));
    
    return 0;
}
