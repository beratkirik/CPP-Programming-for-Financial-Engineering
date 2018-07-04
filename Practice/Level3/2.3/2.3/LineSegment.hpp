//
//  LineSegment.h
//  2.3
//
//  (Finite) line segments in 2 dimensions. This class represents an undirected
//  line segment.
//  The functionality is basic. If you wish to get more functions then convert the
//  line segment to a vector or to a line and use their respective member functions.
//
//  This is a good example of Composition (a line segment consists of two points()
//  the Delegation principle. For example, the member fucntion that calculates the
//  length of a line is implemented as the distance function between the line's end
//  points.
//
//  Stripped version.
//
//
//  Created by Changheng Chen on 12/2/16.
//  Copyright © 2016 Changheng Chen. All rights reserved.
//

#ifndef LineSegment_HPP
#define LineSegment_HPP

#include "Point.hpp"
#include <iostream>
using namespace std;

class LineSegment
{
private:
    
    Point startPoint;   // e1
    Point endPoint;     // e2

public:
    
    // Constructors
    LineSegment();                                 // Line with both end Points at the origin
    LineSegment(const Point& p1, const Point& p2); // Line with end Points [p1, p2]
    LineSegment(const LineSegment& l);             // Copy constructor
    virtual ~LineSegment();                        // Destructor
    
    // Accessing functions
    Point start() const;                           // Synonym for startPoint
    Point end() const;                             // Synonym for endPoint
    
    // Modifiers
    void start(const Point& pt);                   // Set Point pt1
    void end(const Point& pt);                     // Set Point pt2
    
    // Arithemetic
    double length() const;                         // Length of line
    
    // Interaction with Points
    Point midPoint() const;
};

#endif // LineSegment_HPP
