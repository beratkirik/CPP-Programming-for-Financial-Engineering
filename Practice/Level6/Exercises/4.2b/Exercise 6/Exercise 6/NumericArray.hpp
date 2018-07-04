//
//  NumericArray.hpp
//  Exercise 6
//
//  Created by Changheng Chen on 2/2/17.
//  Copyright © 2017 Changheng Chen. All rights reserved.
//

#ifndef NumericArray_hpp
#define NumericArray_hpp

#include "Array.hpp"
#include <iostream>

using namespace std;


namespace chako
{
    namespace Containers
    {
        template <typename T> class NumericArray;
        template <typename T> NumericArray<T> operator * (const NumericArray<T>& arr, double factor);
        template <typename T> NumericArray<T> operator * (double factor, const NumericArray<T>& arr);
    }
}


template <typename T>
class chako::Containers::NumericArray : public Array<T>
{
private:
    
public:
    NumericArray();                                                // Default constructor
    NumericArray(int size);                                        // Constructor w/ size
    NumericArray(const NumericArray<T>& source);                   // Copy constructor
    virtual ~NumericArray();                                       // Destructor
    NumericArray<T>& operator = (const NumericArray<T>& source);   // Assignment operator
    
    NumericArray<T> operator + (const NumericArray<T>& arr) const; // Add array elements
    T DotProduct(const NumericArray<T>& arr) const;                // Dot product
};

#ifndef NumericArray_cpp
#include "NumericArray.cpp"
#endif

#endif /* NumericArray_hpp */
