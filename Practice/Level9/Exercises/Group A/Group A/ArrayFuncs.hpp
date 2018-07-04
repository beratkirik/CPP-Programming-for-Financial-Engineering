//
//  ArrayFuncs.hpp
//  Group A
//
//  Functions for creating one dimensional mesh arrays, and
//  printing 1, 2, or 3 one dimensional array(s) side by side.
//
//  Created by Changheng Chen on 2/20/17.
//  Copyright © 2017 Changheng Chen. All rights reserved.
//

#ifndef ArrayFuncs_hpp
#define ArrayFuncs_hpp

#include <vector>
#include <iomanip>   // std::setw
#include <iostream>
using namespace std;

template <typename T>
vector<T> MeshArray(T start, T end, T interval)
{ // Generate a mesh array of T separated by a mesh size 'interval'
    
    vector<T> arr;
    
    T temp = start;
    while (temp <= end)
    {
        arr.push_back(temp);
        temp = temp + interval;
    }
    
    return arr;
}

template <typename T>
void PrintArray(const vector<T>& arr)
{ // Print a one dimensional array
    
    for (int i = 0; i < arr.size(); i++)
        cout << arr[i] << endl;
}

template <typename T, typename S>
void PrintArray(const vector<T>& arr1, const vector<S>& arr2)
{ // Print 2 one dimensional arrays with the same size side-by-side
    
    for (int i = 0; i < arr1.size(); i++)
    {
        cout << right << setw(4) << arr1[i] << ", "
        << left <<  setw(12) << arr2[i] << endl;
    }
}

template <typename T, typename S, typename I>
void PrintArray(const vector<T>& arr1, const vector<S>& arr2, const vector<I>& arr3)
{ // Print 3 one dimensional arrays with the same size side-by-side
    
    for (int i = 0; i < arr1.size(); i++)
    {
        cout << right << setw(4) << arr1[i] << ", " << setw(12)
        << arr2[i] << ", " << left << setw(12) << arr3[i] << endl;
    }
}

#endif /* ArrayFuncs_hpp */
