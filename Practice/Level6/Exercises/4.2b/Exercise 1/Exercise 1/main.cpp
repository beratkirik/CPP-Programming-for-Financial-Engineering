//
//  main.cpp
//  Exercise 1
//
//  Created by Changheng Chen on 1/23/17.
//  Copyright © 2017 Changheng Chen. All rights reserved.
//

#include <iostream>
#include "Array.hpp"
#include "Line.hpp"
#include "Circle.hpp"
using namespace chako::CAD;
using namespace chako::Containers;

int main()
{ // Default array size is set to 12 (d_size = 12)
    
    Array<int> intArray1;
    Array<int> intArray2;
    Array<double> doubleArray;
    
    cout << intArray1.DefaultSize() << endl;   // 12
    cout << intArray2.DefaultSize() << endl;   // 12
    cout << doubleArray.DefaultSize() << endl; // 12
    
    intArray1.DefaultSize(15);

    cout << intArray1.DefaultSize() << endl;   // 15
    cout << intArray2.DefaultSize() << endl;   // 15
    cout << doubleArray.DefaultSize() << endl; // 12
    
    /* What values are printed? Can you explain the result?
     
       Each instantiation of the template class 'Array' is associated with
       its own static template member variable 'd_size';
   
       When the default size of an instantiation is changed using its setter, the 
       default size of all future default-constructed Array objects is reset.
     
       The default size of integer array class 'Array<int>' is changed to 15.
       The default size of double array class 'Array<double>' remains 12.
     */
    
    return 0;
}
