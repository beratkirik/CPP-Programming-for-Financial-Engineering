//
//  Array.hpp
//  Exercise 2
//
//  Created by Changheng Chen on 1/19/17.
//  Copyright © 2017 Changheng Chen. All rights reserved.
//

#ifndef Array_hpp
#define Array_hpp

#include "Point.hpp"

namespace chako
{
    namespace Containers
    {
        class Array;
    }
}

class chako::Containers::Array
{
private:
    CAD::Point *m_data;
    int m_size;
    
public:
    // Constructors, destructor, and assigment operator
    Array();                                          // Default constructor
    Array(int size);                                  // Constructor with size
    Array(const Array& source);                       // Copy constructor
    virtual ~Array();                                 // Destructor
    Array& operator = (const Array& source);          // Assignment operator
    
    // Getter functions
    int Size() const;                                 // Get the size of array
    CAD::Point& GetElement(int index) const;          // Get the element with index "index"
    
    // Setter functions
    void SetElement(int index, const CAD::Point& p);  // Set the element with index "index"
    
    // Operator overloading
    CAD::Point& operator [] (int index);              // Square bracket operator for accessing element
    const CAD::Point& operator [] (int index) const;  // Return a constant reference to Point
};

#endif /* Array_hpp */
