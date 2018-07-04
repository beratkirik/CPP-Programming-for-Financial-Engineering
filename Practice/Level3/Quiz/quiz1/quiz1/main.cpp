//
//  main.cpp
//  quiz1
//
//  Created by Changheng Chen on 3/14/17.
//  Copyright © 2017 Changheng Chen. All rights reserved.
//

#include <stdio.h>
#include <iostream>


// (1)
#define sqr(x) (x * x) // CORRECT!!! NO ; in the end of this Macro

int main()
{
    printf("%.2f, ", sqr(10.0));     // 100
    printf("%.2f\n", sqr(10.0-5.0)); // 10-5 * 10-5 = 10 - 50 -5 = -45

    
    /* // (2)
     What statement is false about function name overloading?
    
    Two functions can have the same name as long as the number of input arguments are different.
    Two functions can have the same name as long as the output arguments have different types. (FALSE)
    Overloading works with both member functions and global functions.
    Two functions can have the same name as long as the input arguments have different types.
     */
    
    
    /* // (3)
    int* ip;
    *ip=10;
    printf("%d\n", ip); // assign (int *) to int, this code crashes at run-time!!!!
     */
    
    
    // (4)
    // The fastest way to pass a struct type called MyStruct to a function:
    // void F(struct MyStruct* s);
    
    
    // (5) The scanf() statement below reads in a string and an integer (separated by a space)
    char str[10];
    int i;
    scanf("%9s %d", str, &i);
    std::cout << str << ", " << i << std::endl;
    
    double x=3.14;
    printf("%f\n", x);
    
    // (6) File IO
    // File IO can be done with the file versions of IO functions like fprintf() and fscanf() that accept a FILE* as extra argument.
    // When finished with a file, you need to close it with the fclose() function.
    
    // (8) declares correctly a two-dimensional array
    int m1[2][2]={1, 2, 3, 4};
    int m2[3][3];
    
    // (9)
    typedef int (*ArrayPointer)[]; // Define a pointer to an array of 10 integers?
    int (*arr2)[5]; // This code declares a pointer to an array of ints.
    int* arr=(int*)malloc(10*sizeof(int)); // The best way to allocate 10 integers on the heap
    
}
