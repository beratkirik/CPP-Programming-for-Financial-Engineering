//
//  main.c
//  Exercise 3
//
//  Created by Changheng Chen on 11/17/16.
//  Copyright © 2016 Changheng Chen. All rights reserved.
//

/* Predict what will be printed on the screen */

#include <stdio.h>

#define PRD(a) printf("%d", (a) ) // Print decimal
#define NL printf("\n"); // Print new line

// Create and initialize array
int a[]={0, 1, 2, 3, 4};

int main()
{
    int i;
    int* p;
    
    // Print a from a[0] to a[4]
    for (i=0; i<=4; i++) PRD(a[i]); // 1: 0 1 2 3 4
    NL;
    
    // p gets address a[0] first, then a[0], a[1],...,a[4]
    for (p=&a[0]; p<=&a[4]; p++) PRD(*p); // 2: 0 1 2 3 4
    NL;
    NL;
    
    // p gets address a[0] first, then the adress increases with i
    for (p=&a[0], i=0; i<=4; i++) PRD(p[i]); // 3: 0 1 2 3 4
    NL;
    
    // p gets address a[0] by receiving the array name 'a'
    // *(p+i) points to a[0], a[3], a[5] subsequently
    // a+4 is the address a[4]
    for (p=a, i=0; p+i<=a+4; p++, i++) PRD(*(p+i)); // 4: 0 2 4
    NL;
    NL;
    
    // p points to a[4] first, then jumps back to a[0] one array element a time
    for (p=a+4; p>=a; p--) PRD(*p); // 5: 4 3 2 1 0
    NL;
    
    // p points to a[4] first, then decreases to a[3], a[2], a[1], a[0]
    for (p=a+4, i=0; i<=4; i++) PRD(p[-i]); // 6: 4 3 2 1 0
    NL;
    
    // p points to a[5] first, p-a changes from 4, 3, 2, 1 to 0
    for (p=a+4; p>=a; p--) PRD(a[p-a]); // 7: 4 3 2 1 0
    NL;
    
    return 0;
}
