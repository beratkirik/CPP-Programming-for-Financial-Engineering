//
//  Stack.hpp
//  Exercise 6
//
//  Created by Changheng Chen on 2/2/17.
//  Copyright © 2017 Changheng Chen. All rights reserved.
//

#ifndef Stack_hpp
#define Stack_hpp

#include <iostream>
#include "Array.hpp"
using namespace chako::Containers;

namespace chako
{
    namespace Containers
    {
        template <typename T, int size> class Stack;
    }
}

template <typename T, int size>
class chako::Containers::Stack
{
private:
    int m_current;                           // Current index
    Array<T> m_array;                        // Data storage
    
public:
    Stack();                                 // Default constructor
    Stack(Stack& source);                    // Copy Constructor
    virtual ~Stack();                        // Destructor
    Stack& operator = (const Stack& source); // Assignment operator
    
    void Push(T element);                    // Add an element to the top of the stack
    T Pop();                                 // Remove and return the top element from the stack
    
    // Additional functions for testing...
    int GetCurrentIndex();                   // Return m_current
    int GetArraySize();                      // Return size of m_array
    T GetArrayElement(int index);            // Return indexed element in m_array
};

#ifndef Stack_cpp
#include "Stack.cpp"
#endif

#endif /* Stack_hpp */
