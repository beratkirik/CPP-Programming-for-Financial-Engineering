//
//  Point.hpp
//  Exercise 4
//
//  Created by Changheng Chen on 12/8/16.
//  Copyright © 2016 Changheng Chen. All rights reserved.
//

#ifndef Point_hpp
#define Point_hpp

#include <string>
using namespace std;

class Point
{
private:
    // Data members
    double m_x;                            // X coordinate
    double m_y;                            // Y coordinate
    
public:
    // Member functions
    
    // Constructors, copy constructor, and destructor
    Point();
    Point(double xval, double yval);
    Point(const Point& p);
    ~Point();
    
    // Getter functions
    double X() const;                      // Access the x-coordinate
    double Y() const;                      // Access the y-coordinate
    
    // Setter functions
    void X(double newX);                   // Set the x-coordinate
    void Y(double newY);                   // Set the y-coordinate
    
    // String description function
    string ToString() const;
    
    // Distance functions
    double Distance() const;               // Calculate distance to origin (0,0)
    double Distance(const Point& p) const; // Calculate distance between two points; call by reference
};

#endif /* Point_hpp */
