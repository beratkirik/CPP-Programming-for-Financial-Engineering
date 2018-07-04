//
//  main.cpp
//  Exercise 6
//
//  Created by Changheng Chen on 2/2/17.
//  Copyright © 2017 Changheng Chen. All rights reserved.
//

#include "Point.hpp"
#include "Array.hpp"
#include "Stack.hpp"
#include <iostream>
#include <iomanip>
using namespace chako::CAD;
using namespace chako::Containers;

int main()
{
    /* "Only stacks with the same size template argument can be copied/assigned." */
    
    // Create stack objects for tests
    Stack<int,10> stack_obj1;                // Stack of integers of size 10
    Stack<int,10> stack_obj2;                // Stack of integers of size 10
    Stack<int,12> stack_obj3;                // Stack of integers of size 12
    //Stack<int,12> stack_obj4(stack_obj2);  // Copy constructor. NOT POSSIBLE
    
    // Push elements into stack_obj1 and try to assign it to stack_obj2 and stack_obj3
    for (int i = 0; i < 10; i++)
        stack_obj1.Push(i);
    
    try
    {
        stack_obj2 = stack_obj1;
        //stack_obj3 = stack_obj1; // NOT POSSIBLE: No viable overloaded '='
    }
    catch(ArrayException& ex)
    {
        cout << ex.GetMessage() << endl;
    }
    
    cout << "All works. Test ends." << endl;

    return 0;
}
