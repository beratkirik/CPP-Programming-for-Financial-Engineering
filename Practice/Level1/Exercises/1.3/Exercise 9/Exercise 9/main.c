//
//  main.c
//  Exercise 9
//
//  Created by Changheng Chen on 11/4/16.
//  Copyright © 2016 Changheng Chen. All rights reserved.
//

#include <stdio.h>

int main()
{
    int x=1;
    int y=1;
    //int z=1; // not used
    
    /* (expr) ? expt : expf
       If expr (a Boolean expression) evaluates to true,
       the expt is performed and otherwise the expf is performed. */
    
    x+=y+=x;                          // y = y+x = 1+1 = 2; x = x+y = 1+2 = 3;
    
    printf("%d\n", (x<y)?y:x);        // 3 { (3<2) ? 2:3 --> 3 }
    printf("%d\n", (x<y)?x++:y++);    // 2 { (3<2) ? x++:y++; first print y (2), then calculate y=y+1=3 }
    printf("%d\n", x);                // 3
    printf("%d\n\n", y);              // 3
    
    // Extra test
    printf("%d\n", (x<y)?++x:++y);    // 4 { (3<3) ? ++x:++y; first calculate y=y+1, then print y --> 4 }
    printf("%d\n", x);                // 3
    printf("%d\n", y);                // 4
    
    return 0;
}
