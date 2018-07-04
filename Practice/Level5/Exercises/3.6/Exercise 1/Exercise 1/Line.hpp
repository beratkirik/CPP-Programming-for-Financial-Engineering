//
//  Line.hpp
//  Exercise 1
//
//  Created by Changheng Chen on 1/19/17.
//  Copyright © 2017 Changheng Chen. All rights reserved.
//

#ifndef Line_hpp
#define Line_hpp

#include "Point.hpp"


namespace chako
{
    namespace CAD
    {
        class Line;
        
        // Ostream << operator, a global function
        ostream& operator << (ostream& os, const Line& l); // Send to ostream
    }
}


class chako::CAD::Line : public Shape
{
private:
    Point startPoint;   // Declare start point of line
    Point endPoint;     // Declare end point of line
    
public:
    
    // Constructors and destructor
    Line();                                 // Default constructor
    Line(const Point& p1, const Point& p2); // Constructor
    Line(const Line& l);                    // Copy constructor
    Line& operator = (const Line& source);  // Assignment operator
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
    
    // Pure virtual member function
    void Draw() const;
};

#endif /* Line_hpp */
