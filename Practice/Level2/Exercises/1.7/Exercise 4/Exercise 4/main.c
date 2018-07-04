//
//  main.c
//  Exercise 4
//
//  Created by Changheng Chen on 11/17/16.
//  Copyright © 2016 Changheng Chen. All rights reserved.
//

#include <stdio.h>

void DayName();

int main()
{
    int i = 4;   // Test: Day 4 is Wednesday.
    DayName(i);
    
    return 0;
}

void DayName(int i)
{
    // An array of pointers
    char* day_name[] = {"Sunday","Monday","Tuesday","Wednesday","Thursday","Friday","Saturday"};
    printf("Day %i is %s.\n", i, day_name[i-1]);
}
