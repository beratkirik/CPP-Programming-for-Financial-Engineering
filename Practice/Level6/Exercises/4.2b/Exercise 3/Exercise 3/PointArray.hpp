//
//  PointArray.hpp
//  Exercise 3
//
//  Created by Changheng Chen on 1/24/17.
//  Copyright © 2017 Changheng Chen. All rights reserved.
//

#ifndef PointArray_hpp
#define PointArray_hpp

#include "Point.hpp"
#include "Array.hpp"
#include <iostream>


namespace chako
{
    namespace Containers
    {
        class PointArray;
    }
}


class chako::Containers::PointArray : public Array<CAD::Point>
{
private:
    
public:
    PointArray();                                      // Default constructor
    PointArray(int size);                              // Constructor with array size
    PointArray(const PointArray& source);              // Copy constructor
    ~PointArray();                                     // Destructor
    PointArray& operator = (const PointArray& source); // Assignment operator
    
    double Length() const;                             // Total length between the points in the array
};

#endif /* PointArray_hpp */
