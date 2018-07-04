//
//  Macros.c
//  Excercise 2
//
//  Created by Changheng Chen on 11/17/16.
//  Copyright © 2016 Changheng Chen. All rights reserved.
//

#include <stdio.h>
#include "Defs.h"

int main()
{
    int x = 1, y = 2, z = 3;
    
    printf("Max value of [%d, %d] is %d.\n", x, y, Max2(x,y));
    printf("Max value of [%d, %d, %d] is %d.\n", x, y, z, Max3(x,y,z));
    
    return 0;
}
