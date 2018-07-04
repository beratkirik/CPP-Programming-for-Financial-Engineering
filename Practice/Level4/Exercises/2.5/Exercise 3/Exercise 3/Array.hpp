//
//  Array.hpp
//  Exercise 3
//
//  Created by Changheng Chen on 1/6/17.
//  Copyright © 2017 Changheng Chen. All rights reserved.
//

#ifndef Array_hpp
#define Array_hpp

#include "Point.hpp"

class Array
{
private:
    Point *m_data;
    int m_size;
    
public:
    // Constructors, destructor, and assigment operator
    Array();                                      // Default constructor
    Array(int size);                              // Constructor with size
    Array(const Array& source);                   // Copy constructor
    ~Array();                                     // Destructor
    Array& operator = (const Array& source);      // Assignment operator

    // Getter functions
    int Size() const;                             // Get the size of array
    Point& GetElement(int index) const;           // Get the element with index "index"
    
    // Setter functions
    void SetElement(int index, const Point& p);   // Set the element with index "index"
    
    // Operator overloading
    Point& operator [] (int index);               // Square bracket operator for accessing element
    const Point& operator [] (int index) const;   // Return a constant reference to Point
};

#endif /* Array_hpp */
