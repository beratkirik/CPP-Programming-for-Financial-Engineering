//
//  freq.c
//  Exercise 6
//
//  Created by Changheng Chen on 11/11/16.
//  Copyright © 2016 Changheng Chen. All rights reserved.
//

#include <stdio.h>

int main()
{
    char numbers;
    int numbers_of_0 = 0;
    int numbers_of_1 = 0;
    int numbers_of_2 = 0;
    int numbers_of_3 = 0;
    int numbers_of_4 = 0;
    int numbers_of_others = 0;
    
    printf("Enter numbers for evaluation: \n");
    numbers = getchar();

    while (numbers != EOF) // WARNING: (CTRL+Z) is not EOF on this Mac, use (CTRL+D) instead!!
    {
        switch (numbers)
        {
            case '0':
                numbers_of_0++; break;
            case '1':
                numbers_of_1++; break;
            case '2':
                numbers_of_2++; break;
            case '3':
                numbers_of_3++; break;
            case '4':
                numbers_of_4++; break;
            default:
                numbers_of_others++; break;
        }
        
        numbers = getchar();
    }
    
    int numbers_of[6] = {numbers_of_0, numbers_of_1, numbers_of_2, numbers_of_3, numbers_of_4};
    for (int i=0; i<5; i++)
    {
        printf("The number %d has been typed %d times.\n", i, numbers_of[i]);
    }
    printf("Other characters have been typed %d times.\n", numbers_of_others);
    
    return 0; 
}
