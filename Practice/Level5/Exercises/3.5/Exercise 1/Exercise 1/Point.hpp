//
//  Point.hpp
//  Exercise 1
//
//  Created by Changheng Chen on 1/19/17.
//  Copyright © 2017 Changheng Chen. All rights reserved.
//

#ifndef Point_hpp
#define Point_hpp

#include "Shape.hpp"


namespace chako
{
    namespace CAD
    {
        class Point;
    }
}


class chako::CAD::Point  : public Shape
{
private:
    // Data members
    double m_x;                              // X coordinate
    double m_y;                              // Y coordinate
    
public:
    // Member functions
    
    // Constructors and destructor
    Point();                                 // Default constructor
    explicit Point(double value);            // Constructor
    Point(double xval, double yval);         // Constructor
    Point(const Point& p);                   // Copy constructor
    Point& operator = (const Point& source); // Assignment operator
    virtual ~Point();                        // Destructor
    
    // Getter functions
    double X() const;                        // Access the x-coordinate
    double Y() const;                        // Access the y-coordinate
    
    // Setter functions
    void X(double newX);                     // Set the x-coordinate
    void Y(double newY);                     // Set the y-coordinate
    
    // String description function
    string ToString() const;
    
    // Distance functions
    double Distance() const;                 // Calculate distance to origin (0,0)
    double Distance(const Point& p) const;   // Calculate distance between two points
    
    // Operator overloading
    Point operator - () const;               // Negate the coordinates
    Point operator + (const Point& p) const; // Add coordinates
    bool operator == (const Point& p) const; // Equally compare operator
    Point& operator *= (double factor);      // Scale the coordinates & assign
    
    // Global operator overloading
    friend Point operator * (double factor, const Point& p);   // Scale the coordinates
    friend Point operator * (const Point& p, double factor);   // Scale the coordinates
    friend ostream& operator << (ostream& os, const Point& p); // Send to ostream
};

#endif /* Point_hpp */
