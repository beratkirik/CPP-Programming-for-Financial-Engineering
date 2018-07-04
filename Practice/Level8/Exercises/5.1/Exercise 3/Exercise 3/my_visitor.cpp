//
//  my_visitor.cpp
//  Exercise 3
//
//  Created by Changheng Chen on 2/10/17.
//  Copyright © 2017 Changheng Chen. All rights reserved.
//

#include "my_visitor.hpp"

//================= Constructors, destructor, and assignment operator =================

my_visitor::my_visitor() : m_dx(1.0), m_dy(2.0)
{
    // cout << "Default constructor..." << endl;
}

my_visitor::my_visitor(double dx, double dy) : m_dx(dx), m_dy(dy)
{
    // cout << "Constructor with m_dx and m_dy..." << endl;
}

my_visitor::my_visitor(const my_visitor& visitor) : m_dx(visitor.m_dx), m_dy(visitor.m_dy)
{
    // cout << "Copy constructor..." << endl;
}

my_visitor::~my_visitor()
{
    // cout << "Destructor..." << endl;
}

my_visitor& my_visitor::operator = (const my_visitor &source)
{ // Assignment operator
    
    if (this == &source)
        return *this;
    
    m_dx = source.m_dx;
    m_dy = source.m_dy;
    
    return *this;
}


// ============================== Operator () for Shapes ==============================

void my_visitor::operator () (Point& p) const
{ // Visit a point
    
    p.X(p.X() + m_dx);
    p.Y(p.Y() + m_dy);
}

void my_visitor::operator () (Line& l) const
{ // Visit a line
        
    l.P1(Point((l.P1()).X() + m_dx, (l.P1()).Y() + m_dy));
    l.P2(Point((l.P2()).X() + m_dx, (l.P2()).Y() + m_dy));
}

void my_visitor::operator () (Circle& c) const
{ // Visit a circle
    
    c.CenterPoint(Point(c.CenterPoint().X() + m_dx, c.CenterPoint().Y() + m_dy));
}
