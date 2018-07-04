//
//  Array.cpp
//  Exercise 2
//
//  Created by Changheng Chen on 1/19/17.
//  Copyright © 2017 Changheng Chen. All rights reserved.
//

#include "OutOfBoundsException.hpp"
#include "Array.hpp"
#include "iostream"

namespace chako
{
    namespace Containers
    {
        // =================================================================
        // Constructors, destructor, and assignment operator
        
        Array::Array() : m_size(10), m_data(new CAD::Point[10])
        { // Default constructor
        
            //cout << "Array default constructor..." << endl;
        }

        Array::Array(int size) : m_size(size), m_data(new CAD::Point[size])
        { // Constructor with size
    
            //cout << "Array constructor with size..." << endl;
        }

        Array::Array(const Array& source) : m_size(source.m_size), m_data(new CAD::Point[source.m_size])
        { // Copy constructor
    
            for (int i = 0; i < m_size; i++)
                m_data[i] = source.m_data[i];
            
            cout << "Array copy constructor..." << endl; 
        }

        Array::~Array()
        { // Destructor
    
            delete [] m_data;
            //cout << "By my array..." << endl;
        }

        Array& Array::operator = (const Array& source)
        { // Assignment operator
    
            if (this == &source)
                return *this;
    
            delete [] m_data;
            m_size = source.m_size; // WARNING: new array size can be different!
            m_data = new CAD::Point[m_size];
    
            for (int i = 0; i < m_size; i++)
                m_data[i] = source.m_data[i];
    
            return *this;
        }

        // =================================================================
        // Getter functions
        int Array::Size() const
        {
            return m_size;
        }

        CAD::Point& Array::GetElement(int index) const
        {
            if (index >= m_size || index < 0)
                throw OutOfBoundsException(index);
    
            return m_data[index];
        }

        // Setter function
        void Array::SetElement(int index, const CAD::Point& p)
        {
            if (index >= m_size || index < 0)
                throw OutOfBoundsException(index);
    
            m_data[index] = p;
        }

        // Operator overloading
        CAD::Point& Array::operator [] (int index)
        {
            if (index >= m_size || index < 0)
                throw OutOfBoundsException(index); 
    
            return m_data[index];
        }
        
        const CAD::Point& Array::operator [] (int index) const
        {
            if (index >= m_size || index < 0)
                throw OutOfBoundsException(index);
            
            return m_data[index];
        }
    }
}
