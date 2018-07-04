//
//  NumericArray.hpp
//  Exercise 2
//
//  Created by Changheng Chen on 1/24/17.
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
        
        /* Option I: Global functions (instead of "double factor", try "T factor" instead!!!) */
        //template <typename T> NumericArray<T> operator * (const NumericArray<T>& arr, double factor);
        //template <typename T> NumericArray<T> operator * (double factor, const NumericArray<T>& arr);
    }
}


template <typename T>
class chako::Containers::NumericArray : public Array<T>
{
private:
    
public:
    NumericArray();                                                // Default constructor
    NumericArray(int size);                                        // Constructor with size
    NumericArray(const NumericArray<T>& source);                   // Copy constructor
    virtual ~NumericArray();                                       // Destructor
    NumericArray<T>& operator = (const NumericArray<T>& source);   // Assignment operator
    
    NumericArray<T> operator + (const NumericArray<T>& arr) const; // Add array elements
    T DotProduct(const NumericArray<T>& arr) const;                // Dot product
    
    
    
    /* Option II: Does not work unless they are inline functions...
       Friend functions have to be implemented here for them to work!
       Alternatively, declare 'operator * ()' as global functions. */
    
    //friend NumericArray<T> operator * (const NumericArray<T>& arr, double factor);
    //friend NumericArray<T> operator * (double factor, const NumericArray<T>& arr);
   
    friend NumericArray<T> operator * (const NumericArray<T>& arr, double factor)
    { // Scale the array: arr * factor
        
        typename NumericArray<T>::NumericArray new_arr(arr.Size());
        
        for (int index=0; index<arr.Size(); index++)
            new_arr[index] = arr.GetElement(index) * factor;
        
        return new_arr;
    }
    
    friend NumericArray<T> operator * (double factor, const NumericArray<T>& arr)
    { // Scale the array, switch order of the operands: factor * arr
        
        typename NumericArray<T>::NumericArray new_arr(arr.Size());
        new_arr = arr * factor;
        
        return new_arr;
    }
};

#ifndef NumericArray_cpp     // Must be the same name as in source file #define
#include "NumericArray.cpp"
#endif

#endif /* NumericArray_hpp */
