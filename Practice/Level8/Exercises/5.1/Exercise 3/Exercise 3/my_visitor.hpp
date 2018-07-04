//
//  my_visitor.h
//  Exercise 3
//
//  Created by Changheng Chen on 2/10/17.
//  Copyright © 2017 Changheng Chen. All rights reserved.
//

#ifndef my_visitor_h
#define my_visitor_h

#include <boost/variant.hpp>
#include "Line.hpp"
#include "Circle.hpp"
using namespace chako::CAD;

class my_visitor : public boost::static_visitor<void>
{
private:
    double m_dx;
    double m_dy;
    
public:
    my_visitor();                                      // Default constructor
    my_visitor(double dx, double dy);                  // Constructor with m_dx and m_dy
    my_visitor(const my_visitor& visitor);             // Copy constructor
    virtual ~my_visitor();                             // Destructor
    my_visitor& operator = (const my_visitor& source); // Assignment operator
    
    void operator () (Point& p) const;                 // operator () for Point
    void operator () (Line& l) const;                  // operator () for Line
    void operator () (Circle& c) const;                // operator () for Circle
};

#endif /* my_visitor_h */
