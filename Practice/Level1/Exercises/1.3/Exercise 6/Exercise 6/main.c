//
//  main.c
//  Exercise 6
//
//  Created by Changheng Chen on 11/4/16.
//  Copyright © 2016 Changheng Chen. All rights reserved.
//

#include <stdio.h>

int bitwise_shift(int shifted_i)
{ // Define a function to output whether arithmetic/logical right-shift is performed
    
    if (shifted_i<0)
        printf("1 is inserted left; arithmetic right-shifts are performed.\n\n");
    else
        printf("0 is inserted left; logical/arithmetic right-shifts are performed.\n\n");
    
    return 0;
}


int main()
{
    /* In a left arithmetic/logical shift, zeros are shifted in on the right. Therefore, logical and arithmetic left-shifts are exactly the same.
       
       In a right arithmetic shift, the sign bit (the MSB in two's complement) is shifted in on the left. Thus, the sign of the operand is preserved (not necessarily consistent across platforms). 
       In contrast, a logical right-shift inserts value 0 bits into the most significant bit, instead of copying the sign bit.
       The logical right-shift is ideal for unsigned binary numbers, while the arithmetic right-shift is ideal for signed two's complement binary numbers. */
    
    
    // Example of logical shift: 0 is inserted left
    int i = 9;
    printf("i = %d. i >> 2 evaluates to %d.\n", i, i >> 2);
    bitwise_shift(i >> 2);
    /* Essentially, in this case the logical right-shift is the same as arithmetic right-shift. */
    
    
    // Example of arithmetic shift: 1 is inserted left
    i = -9;
    printf("i = %d. i >> 2 evaluates to %d.\n", i, i >> 2);
    bitwise_shift(i >> 2);
    
    return 0;
}
