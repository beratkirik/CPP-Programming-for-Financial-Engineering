//
//  main.cpp
//  Exercise 4
//
//  Created by Changheng Chen on 1/29/17.
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
    /* Using another class as data member is called composition. In this case the Stack class uses internally an Array class. Forwarding functionality to another class is called delegation. Here the Stack class delegates the storage of elements to the Array class. */
    
    
    // (0) Create stack objects for tests
    Stack<int> stack_obj1;                    // Default constructor with default array size 12
    Stack<int> stack_obj2(5);                 // Stack of integers of size 5
    Stack<int> stack_obj3(6);                 // Stack of integers of size 6
    
    
    // (1) Push elements into the stacks
    for (int i = 0; i < 5; i++)
        stack_obj2.Push(i);
    
    for (int i = 0; i < 6; i++)
        stack_obj3.Push(i);
    
    Stack<int> stack_obj4(stack_obj3);        // Copy constructor
    
    
    // (2) Pop elements from the stacks
    cout << "stack_obj3  stack_obj4" << endl; // Display popped out elements, should be the same
    for (int i = 0; i < 6; i++)
    {
        cout << setw(5)  << stack_obj3.Pop() << setw(13) << stack_obj4.Pop() << endl;
    }
    cout << endl;
    
    
    // (3) Catch Size Mismatch Exception with using assignment operator = ()
    try
    {
        cout << "Size of array in stack_obj1: " << stack_obj2.GetArraySize() << endl;
        cout << "Size of array in stack_obj2: " << stack_obj3.GetArraySize() << endl;
        stack_obj1 = stack_obj2;
    }
    catch (ArrayException& ex)                // Catch exception object
    {
        cout << ex.GetMessage() << endl;      // Print the error message
    }
    catch(...)
    {
        cout << "An unhandled exception has occurred..." << endl;
    }
    cout << endl;
    
    
    // (4.1) Catch Out of Bound Exception with using Push()
    try
    {
        cout << "i  " << "m_current  " << "m_array[i]" << endl;
        for (int i = 0; i < 1000; i++)        // 12 is default size of the array in stack_obj1
        {
            stack_obj1.Push(i);
            cout << i << setw(8) << stack_obj1.GetCurrentIndex()
                 << setw(10) << stack_obj1.GetArrayElement(i) << endl;
        }
    }
    catch (ArrayException& ex)                // Catch exception object
    {
        cout << ex.GetMessage() << endl;      // Print the error message
    }
    catch(...)
    {
        cout << "An unhandled exception has occurred..." << endl;
    }
    cout << endl;

    // (4.2) Catch Out of Bound Exception with using Pop()
    try
    {
        cout << "After Push(), m_current is "
             << stack_obj1.GetCurrentIndex() << endl;
        cout << "i  " << "m_array[i]  " << "m_current" << endl;
        for (int i = 0; i < 100; i++)         // 12 is default size of the array in stack_obj1
        {
            cout << i << setw(8) << stack_obj1.Pop()
                 << setw(10) << stack_obj1.GetCurrentIndex() << endl;
        }
        
    }
    catch (ArrayException& ex)                // Catch exception object
    {
        cout << ex.GetMessage() << endl;      // Print the error message
    }
    catch(...)
    {
        cout << "An unhandled exception has occurred..." << endl;
    }
    cout << "m_current is set back to " << stack_obj1.GetCurrentIndex() << endl;

    return 0;
}
