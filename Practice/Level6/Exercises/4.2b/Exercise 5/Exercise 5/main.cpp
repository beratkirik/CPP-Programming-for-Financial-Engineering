//
//  main.cpp
//  Exercise 5
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
    
    // (0) Create a stack object for tests
    Stack<int> stack_obj;                     // Default constructor with default array size 12
    
    
    // (1) Catch Stack Full Exception
    try
    {
        cout << "i  " << "m_current  " << "m_array[i]" << endl;
        for (int i = 0; i < 100; i++)         // 12 is default size of the array in stack_obj
        {
            stack_obj.Push(i);
            cout << i << setw(8) << stack_obj.GetCurrentIndex()
            << setw(10) << stack_obj.GetArrayElement(i) << endl;
        }
    }
    catch (StackException& ex)                // Catch exception object
    {
        cout << ex.GetMessage() << endl;      // Print the error message
    }
    catch(...)
    {
        cout << "An unhandled exception has occurred..." << endl;
    }
    cout << endl;

    
    // (2) Catch Stack Empty Exception
    try
    {
        cout << "After Push(), m_current is "
        << stack_obj.GetCurrentIndex() << endl;
        cout << "i  " << "m_array[i]  " << "m_current" << endl;
        for (int i = 0; i < 100; i++)         // 12 is default size of the array in stack_obj
        {
            cout << i << setw(8) << stack_obj.Pop()
            << setw(10) << stack_obj.GetCurrentIndex() << endl;
        }
        
    }
    catch (StackException& ex)                // Catch exception object
    {
        cout << ex.GetMessage() << endl;      // Print the error message
    }
    catch(...)
    {
        cout << "An unhandled exception has occurred..." << endl;
    }
    
    // Check if m_current is set back to 0
    cout << "In the end, m_current is " << stack_obj.GetCurrentIndex() << endl;

    return 0;
}
