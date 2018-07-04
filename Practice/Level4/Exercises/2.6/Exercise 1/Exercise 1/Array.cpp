//
//  Array.cpp
//  Exercise 1
//
//  Created by Changheng Chen on 1/7/17.
//  Copyright © 2017 Changheng Chen. All rights reserved.
//

#include "Array.hpp"
#include "iostream"

namespace chako
{
    namespace Containers
    {
        // =================================================================
        // Constructors, destructor, and assignment operator
        Array::Array()
        { // Default constructor
    
            m_size = 10;
            m_data = new CAD::Point[m_size];
    
            //cout << "Array default constructor..." << endl;
        }

        Array::Array(int size)
        { // Constructor with size
    
            m_size = size;
            m_data = new CAD::Point[m_size];
    
            //cout << "Array constructor with size..." << endl;
        }

        Array::Array(const Array& source)
        { // Copy constructor
    
            m_size = source.m_size;
            m_data = new CAD::Point[m_size];
    
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
            m_size = source.m_size;
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
            if (index >= m_size)
                return m_data[0];
    
            return m_data[index];
        }

        // Setter function
        void Array::SetElement(int index, const CAD::Point& p)
        {
            if (index < 0 || index >= m_size)
            {
                // Ignore 'set'
            }
            else
            {
                m_data[index] = p;
            }
        }

        // Operator overloading
        CAD::Point& Array::operator [] (int index)
        {
            if (index < 0 || index >= m_size)
                return m_data[0];
    
            return m_data[index];
        }
        
        const CAD::Point& Array::operator [] (int index) const
        {
            if (index < 0 || index >= m_size)
                return m_data[0];
            
            return m_data[index];
        }
    }
}
