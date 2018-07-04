//
//  main.cpp
//  Exercise 4
//
//  Created by Changheng Chen on 11/3/16.
//  Copyright © 2016 Changheng Chen. All rights reserved.
//

#include <stdio.h>

int main()
{
    int married = 0;    // 0 --> false, not married; otherwise true!
    
    // (condition) ? (if_true) : (if_false)
    //printf("John is married? %s\n", married ? "Yes." : "No.");
    
    // The following solution is better
    //printf(married ? "married" : "not married");
    printf(!married ? "not married" : "married");
    
    
    /* Example: value = (expr) ? exprt : exprf; // value = exprt or value = exprf
    int a = 10;
    int b = 20;
    int c;

    c = (a>b) ? a : b;
    
    printf("%d\n", c); */
  
    return 0;
}
