//
//  PointArray.hpp
//  Exercise 5
//
//  Created by Changheng Chen on 2/2/17.
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
        class PointArray : public Array<CAD::Point>
        {
        private:
            
        public:
            PointArray();                                      // Default constructor
            PointArray(int size);                              // Constructor with array size
            PointArray(const PointArray& source);              // Copy constructor
            virtual ~PointArray();                             // Destructor
            PointArray& operator = (const PointArray& source); // Assignment operator
            
            double Length() const;                             // Total length of the points in the array
        };
    }
}

#ifndef NumericArray_cpp
#include "NumericArray.cpp"
#endif

#endif /* PointArray_hpp */
