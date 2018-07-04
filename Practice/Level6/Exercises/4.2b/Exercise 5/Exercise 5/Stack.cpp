//
//  Stack.cpp
//  Exercise 5
//
//  Created by Changheng Chen on 2/2/17.
//  Copyright © 2017 Changheng Chen. All rights reserved.
//

#ifndef Stack_cpp
#define Stack_cpp

#include "Stack.hpp"
#include "SizeMismatchException.hpp"
#include "OutOfBoundsException.hpp"
#include "StackFullException.hpp"
#include "StackEmptyException.hpp"

namespace chako
{
    namespace Containers
    {
        
        // Constructors, destructor and assignment operator
        template <typename T>
        Stack<T>::Stack() : m_current(0), m_array()
        {
            //cout << "Stack default constructor..." << endl;
        }
        
        template <typename T>
        Stack<T>::Stack(int size) : m_current(0), m_array(size)
        {
            //cout << "Stack constructor with size..." << endl;
        }
        
        template <typename T>
        Stack<T>::Stack(Stack& source) : m_current(source.m_current), m_array(source.m_array)
        {
            //cout << "Stack copy constructor..." << endl;
        }
        
        template <typename T>
        Stack<T>::~Stack()
        {
            //cout << "Bye my Stack..." << endl;
        }
        
        template <typename T>
        Stack<T>& Stack<T>::operator = (const Stack<T>& source)
        { // Assignment operator =
            
            if (this == &source)
                return *this;
            
            m_current = source.m_current;
            m_array = source.m_array;

            return *this;
        }
        
        
        // Functionality
        template <typename T>
        void Stack<T>::Push(T element)
        {
            try
            {
                m_array[m_current] = element;
                m_current++;
            }
            catch (OutOfBoundsException& ex)
            {
                throw StackFullException("full");
            }
        }
        
        template <typename T>
        T Stack<T>::Pop()
        {
            try
            {
                --m_current;
                return m_array[m_current];
            }
            catch(OutOfBoundsException& ex)
            {
                m_current = 0;
                throw StackEmptyException("empty");
            }
        }


        // Additional functions for testing...
        template <typename T>
        int Stack<T>::GetCurrentIndex()
        {
            return m_current; 
        }
        
        template <typename T>
        int Stack<T>::GetArraySize()
        {
            return m_array.Size();
        }
        
        template <typename T>
        T Stack<T>::GetArrayElement(int index)
        {
            return m_array[index];
        }
    }
}

#endif /* Stack_cpp */
