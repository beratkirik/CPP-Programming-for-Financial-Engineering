//
//  Shape.cpp
//  Exercise 1
//
//  Created by Changheng Chen on 1/19/17.
//  Copyright © 2017 Changheng Chen. All rights reserved.
//

#include "Shape.hpp"
#include <iostream>       // std::cout
#include <sstream>        // std::stringstream
#include <stdlib.h>       // rand()


// Constructors, destructor, and assignment operator
Shape::Shape() : m_id(rand())
{
    //cout << "Shape default constructor..." << endl;
}

Shape::Shape(int id) : m_id(id)
{
    //cout << "Shape copy constructor.." << endl;
}

Shape::~Shape()
{
    //cout << "Bye my shape..." << endl;
}

Shape& Shape::operator = (const Shape& source)
{ // Assignment operator
    
    if (this == &source)
        return *this;
    
    m_id = source.m_id;
    return *this;
}


// ID retrieve and description functions
int Shape::ID() const
{
    return m_id;
}

string Shape::ToString() const
{
    stringstream ss;
    ss << "ID: " << m_id;
    
    return ss.str();  // Retrieve the string from the string buffer
}

// Template Method Pattern
void Shape::Print() const
{
    cout << ToString() << endl; 
}
