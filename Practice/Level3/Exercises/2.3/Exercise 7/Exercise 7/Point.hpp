//
//  Point.hpp
//  Exercise 7
//
//  Created by Changheng Chen on 12/9/16.
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
    
    // Constructors and destructor
    Point();
    Point(double xval, double yval);
    Point(const Point& p);
    ~Point();

    // Getter functions
    double X() const;                      // Get the x-coordinate
    double Y() const;                      // Get the y-coordinate
    
    //*** Default inline for setter functions!!!
    void X(double newX) {m_x = newX;}      // Set the x-coordinate
    void Y(double newY) {m_y = newY;}      // Set the y-coordinate
    
    // String description function
    string ToString() const;
    
    // Distance functions
    double Distance() const;               // Calculate distance to origin (0,0)
    double Distance(const Point& p) const; // Calculate distance between two points; call by reference
};

//**** Normal inline for getter functions!!!
inline double Point::X() const {return m_x;}
inline double Point::Y() const {return m_y;}

#endif /* Point_hpp */
