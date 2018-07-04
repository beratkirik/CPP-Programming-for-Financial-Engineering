//
//  freq.c
//  Exercise 7
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
    
    printf("Enter numbers for evaluatons: \n");
    numbers = getchar();
    
    while (numbers != EOF) // (CTRL+Z) is not EOF on this Mac, use (CTRL+D) instead!!
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
    
    switch (numbers_of_3)
    {
        case 0:
            printf("The number three appears zero time.\n"); break;
        case 1:
            printf("The number three appears one time.\n"); break;
        case 2:
            printf("The number three appears two times.\n"); break;
        default:
            printf("The number three appears more than two times.\n"); break;
    }

    return 0;
}
