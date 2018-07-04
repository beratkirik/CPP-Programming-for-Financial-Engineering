//
//  main.cpp
//  Exercise 2
//
//  Created by Changheng Chen on 1/6/17.
//  Copyright © 2017 Changheng Chen. All rights reserved.
//

#include "Point.hpp"
#include <iostream>
using namespace std;

int main()
{
    /* Create an array of Point pointers with 3 elements on the stack.
       Create for each element in the array a point on the heap. 
     
     WARNING: 
     A pointer is allocated on the STACK, while the object (so the data that it carries,
     as well as access to its methods) pointed by the pointer is allocated on the HEAP.
     */
    
    
    int N = 3;
    Point* *pp;                    // pp -> pointers to Point pointers (Point*)
    pp = new Point*[N];            // Create an array of Point pointers
    
    pp[0] = new Point();           // pp[0] -> pointer to a Point (Default constructor)
    pp[1] = new Point(3.0, 4.0);   // pp[1] -> pointer to a Point (Constructor with coordinates)
    pp[2] = new Point(*pp[1]);     // pp[2] -> Pointer to a Point (Copy constructor)
    
    for(int n = 0; n < N; n++)
        cout << *pp[n];            // Contrast: cout << pp[0]; in Exercise 1
    
    for(int n = 0; n < N; n++)
        delete pp[n];              // Delete pointers pp[0], pp[1], and pp[2]
    
    delete [] pp;                  // Delete pointer pp
    
    
    /* Drawing of the memory layout:
     
     A pointer is just a variable on the stack that holds a memory address. Each 
     element in the pointer array holds a pointer to a Point object on the heap.
     
     On the stack is a pointer that points to N=3 Point pointers (on the stack):
     _________
     |       |
     |   pp  |                      ------------>  Stack
     |       |
     ---------
         |
         V
     _________________________
     |       |       |       |
     | pp[0] | pp[1] | pp[2] |      ------------>  Stack
     |       |       |       |
     -------------------------
         |       |       |
         V       V       V
     _________________________
     |       |       |       |
     | Point | Point | Point |      ------------>  Heap
     |       |       |       |
     -------------------------
     On the heap are N=3 Point objects. */
    
    return 0;
}
