//
//  Array.cpp
//  Exercise 3
//
//  Created by Changheng Chen on 1/6/17.
//  Copyright © 2017 Changheng Chen. All rights reserved.
//

#include "Array.hpp"
#include "iostream"

// =================================================================
// Constructors, destructor, and assignment operator
Array::Array()
{ // Default constructor
    
    m_size = 10;
    m_data = new Point[m_size];
    
    cout << "Array default constructor..." << endl;
}

Array::Array(int size)
{ // Constructor with size
    
    m_size = size;
    m_data = new Point[m_size];
    
    cout << "Array constructor with size..." << endl;
}

Array::Array(const Array& source)
{ // Copy constructor
    
    m_size = source.m_size;
    m_data = new Point[m_size];
    
    for (int i = 0; i < m_size; i++)
        m_data[i] = source.m_data[i];
}

Array::~Array()
{ // Destructor
    
    delete [] m_data;
    cout << "By my array..." << endl;
}

Array& Array::operator = (const Array& source)
{ // Assignment operator
    
    if (this == &source)
        return *this;
    
    delete [] m_data;
    m_size = source.m_size;
    m_data = new Point[m_size];
    
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

Point& Array::GetElement(int index) const
{
    if (index < 0 || index >= m_size)
        return m_data[0];
    
    return m_data[index];
}

// Setter function
void Array::SetElement(int index, const Point& p)
{
    if (index < 0 || index >= m_size)
    {
        // Ignore the 'set'
    }
    else
    {
        m_data[index] = p;
    }
}

// Operator overloading
Point& Array::operator [] (int index)
{
    if (index < 0 || index >= m_size)
        return m_data[0];
    
    return m_data[index];
}

const Point& Array::operator [] (int index) const
{ // Return a constant reference to Point
    
    if (index < 0 || index >= m_size)
        return m_data[0];
    
    return m_data[index];
}
