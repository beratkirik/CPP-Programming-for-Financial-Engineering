//
//  Line.hpp
//  Exercise 5
//
//  Created by Changheng Chen on 12/8/16.
//  Copyright © 2016 Changheng Chen. All rights reserved.
//

#ifndef Line_hpp
#define Line_hpp

#include "Point.hpp"

class Line
{
private:
    Point startPoint;   // Declare start point of line
    Point endPoint;     // Declare end point of line
    
public:
    
    // Constructors and destructor
    Line();                                 // Line with both end Points at the origin
    Line(const Point& p1, const Point& p2); // Line with end Points [p1, p2]
    Line(const Line& l);                    // Copy constructor
    virtual ~Line();                        // Destructor
    
    // Accessing functions
    Point P1() const;                       // Synonym for startPoint
    Point P2() const;                       // Synonym for endPoint
    
    // Modifiers
    void P1(const Point& pt);               // Set startPoint
    void P2(const Point& pt);               // Set endPoint
    
    // String description function
    string ToString() const;
    
    // Arithemetic
    double Length() const;                  // Length of line
    
    // Interaction with Points
    Point midPoint() const;                 // Middle point of line
};

#endif /* Line_hpp */
