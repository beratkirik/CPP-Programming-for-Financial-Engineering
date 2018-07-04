//
//  main.c
//  Exercise 4
//
//  Created by Changheng Chen on 11/11/16.
//  Copyright © 2016 Changheng Chen. All rights reserved.
//

#include <stdio.h>

int main()
{
    float Fahrenheit, Celsius;
    float start_temperature = 0.0;
    float end_temperature = 300.0;
    float step_size = 20.0;
   
    printf("Fahrenheit    Celsius \n");   // Print a header
    
    Fahrenheit = start_temperature;
    while (Fahrenheit <= end_temperature)
    {
        Celsius = (5.0/9.0) * (Fahrenheit - 32.0);
        printf("%10.1f %10.1f \n", Fahrenheit, Celsius);
        Fahrenheit = Fahrenheit + step_size;  // Take steps of 20 degrees
    }
    
    return 0;
}
