//
//  main.cpp
//  Exersice 1
//
//  Created by Changheng Chen on 1/19/17.
//  Copyright © 2017 Changheng Chen. All rights reserved.
//

#include <iostream>
#include "Line.hpp"
using namespace chako::CAD;

int main()
{
    /* Without using colon sytax for the Line default constructor:
     
       (1) 'startPoint' and 'endPoint' are created and initialised by the system, and
       the Point default constructor is called 1+1 times;
     
       (2) 'startPoint' and 'endPoint' are initialzed again in the Line default constructor by calling the Point default constructor, so the Point default constructor is called 1+1 times again.
     
       So, creating a line object, the Point default constructor is called 4 times, and 
       the Point deconstructor is called 4 times as well.
     
       Using colon sytax for the Line default constructor:
     
       'startPoint' and 'endPoint' are initialized upon creation, and 
       the Point default constructor is called 2 times, so is the Point destructor.
     */
    
                                    // With colon sytax (startPoint and endPoint):
    Line l1;                        // Point default constructor (2 times)
    Line l2 = l1;                   // Point copy constructor (2 times)
    Line l3(Point(1,2),Point(3,4)); // Point constructor with coordinates (2 times) and
                                    // Point copy constructor (2 times)
    l3 = l2;                        // Point assignment operator (2 times)
                                    // Point destructor (8 times: l1, l2, l3, Point(1,2), Point(3,4))
    //Point p;
    //p = p;
    
    return 0;
}
