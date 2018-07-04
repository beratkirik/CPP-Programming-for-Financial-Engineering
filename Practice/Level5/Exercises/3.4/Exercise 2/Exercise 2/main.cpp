//
//  main.cpp
//  Exercise 2
//
//  Created by Changheng Chen on 1/19/17.
//  Copyright © 2017 Changheng Chen. All rights reserved.
//

#include <iostream>
#include "Line.hpp"
using namespace chako::CAD;

int main()
{
    Shape s;                           // Create shape.
    Point p(10, 20);                   // Create point.
    Line l(Point(1,2), Point(3, 4));   // Create line.
    
    cout<<s.ToString()<<endl;          // Print shape by calling member function.
    cout<<p.ToString()<<endl;          // Print point by calling member function.
    cout<<l.ToString()<<endl;          // Print line by calling member function.
    
    cout<<"Shape ID: "<<s.ID()<<endl;  // ID of the shape.
    cout<<"Point ID: "<<p.ID()<<endl;  // ID of the point. Does this work? Yes.
    cout<<"Line ID: "<<l.ID()<<endl;   // ID of the line. Does this work? Yes.
                                       /* Both work, as derived objects behaves as base objects and
                                          guarantee to have base functionality. */
    
    Shape* sp;                         // Create pointer to a shape variable.
    //sp = &p;                         // Point in a shape variable. Possible? Yes.
    sp = new Point;
    cout<<sp->ToString()<<endl;        // What is printed? ID of Point p.
    delete sp;                         /* The base class pointer (sp) points to the derived object (p).
                                          However,the base function Shape::ToString() is called, and the
                                          ID of Point p is printed. Here, pointer sp can only access 
                                          functions of base class. */
    
    // Create and copy Point p to new point.
    Point p2;
    p2 = p;
    cout<<p2<<", "<<p2.ID()<<endl;     // Is the ID copied if you do not call the base class assignment
                                       // in point? No, without calling the base class assignment, only
                                       // the data members of the derived class are copied, and the data
                                       // member of the base class is assigned by the system.
    
    return 0;
}
