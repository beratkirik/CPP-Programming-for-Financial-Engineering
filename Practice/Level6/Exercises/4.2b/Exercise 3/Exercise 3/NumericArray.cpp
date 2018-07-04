//
//  NumericArray.cpp
//  Exercise 3
//
//  Created by Changheng Chen on 1/24/17.
//  Copyright © 2017 Changheng Chen. All rights reserved.
//

#ifndef NumericArray_cpp
#define NumericArray_cpp

#include "SizeMismatchException.hpp"
#include "NumericArray.hpp"
#include <iostream>

namespace chako
{
    namespace Containers
    {
        
        //===================== Constructors, destructor and assignment operator =====================
        template <typename T>
        NumericArray<T>::NumericArray() : Array<T>::Array()  // Call default constructor of base class
        {
            //cout << "Numeric array default constructor..." << endl;
        }
        
        template <typename T>
        NumericArray<T>::NumericArray(int size) : Array<T>::Array(size)
        {
            //cout << "Numeric array constructor with array size..."
        }
        
        template <typename T>
        NumericArray<T>::NumericArray(const NumericArray<T>& source) : Array<T>::Array(source)
        {
            //cout << "Numeric array copy constructor..." << endl;
        }
        
        template <typename T>
        NumericArray<T>::~NumericArray()
        {
            //cout << "Numeric array deconstructor..." << endl; 
        }
        
        template <typename T>
        NumericArray<T>& NumericArray<T>::operator = (const NumericArray<T>& source)
        {
            if (this == &source)
                return *this;
            
            Array<T>::operator = (source);
            return *this;
        }
        
        
        //=================================== Numeric functionality ===================================
        template <typename T>
        NumericArray<T> NumericArray<T>::operator + (const NumericArray<T>& arr) const
        { // operator + ()
            
            if (this->Size() != arr.Size())
                throw SizeMismatchException("mismatch");
            
            typename NumericArray<T>::NumericArray new_arr(arr.Size());
            for (int index = 0; index < arr.Size(); index++)
            {
                new_arr[index] = arr.GetElement(index) + this->GetElement(index);
            }
            
            return new_arr;
        }
        
        template <typename T>
        T NumericArray<T>::DotProduct(const NumericArray<T>& arr) const
        { // Function DotProduct()
        
            if (this->Size() != arr.Size())
                throw SizeMismatchException("mismatch");
            
            T dot_product(0);
            for (int index = 0; index < arr.Size(); index++)
                dot_product += (this->GetElement(index) * arr.GetElement(index));
            
            return dot_product;
        }
        
        //=================================== Global functionality ====================================
        template <typename T>
        NumericArray<T> operator * (double factor, const NumericArray<T>& arr)
        {
            typename NumericArray<T>::NumericArray new_arr(arr.Size());
            
            for (int index = 0; index < arr.Size(); index++)
                new_arr[index] = arr.GetElement(index) * factor;
            
            return new_arr;
        }
        
        template <typename T>
        NumericArray<T> operator * (const NumericArray<T>& arr, double factor)
        {
            typename NumericArray<T>::NumericArray new_arr(arr.Size());
            new_arr = factor * arr;
            
            return new_arr;
        }
    }
}

#endif /* NumericArray_cpp */
