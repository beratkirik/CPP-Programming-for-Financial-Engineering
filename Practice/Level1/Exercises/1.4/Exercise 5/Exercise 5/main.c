//
//  main.c
//  Exercise 5
//
//  Created by Changheng Chen on 11/11/16.
//  Copyright © 2016 Changheng Chen. All rights reserved.
//

#include <stdio.h>

int main()
{
    float Celsius, Fahrenheit;
    float start_temperature = 0.0;
    float end_temperature = 19.0;
    float step_size = 1.0;
    
    printf("   Celsius  Fahrenheit \n");  // Print a header
    
    Celsius = start_temperature;
    while (Celsius <= end_temperature)
    {
        Fahrenheit = Celsius * (9.0/5.0) + 32.0;
        printf("%10.1f  %10.1f \n", Celsius, Fahrenheit);
        Celsius = Celsius + step_size;  // Take steps of 1 degree
    }
    
    return 0;
}
