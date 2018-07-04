//
//  main.cpp
//  STLAlgorithms
//
//  A subset of the 70-8- algorithms in STL. The objective is to show
//  how to use them.
//
//  Use this code as a base for extra examples from Jossuttis' book.
//
//  Created by Changheng Chen on 2/5/17.
//  Copyright © 2017 Changheng Chen. All rights reserved.
//

#include <numeric>      // Numerica algorithms
#include <functional>   // For function objects
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>

using namespace std;

template <typename T>
void print(const vector<T>& l, const string& comment)
{ // A generic print function for vectors
    
    cout << comment << ": ";
    
    // We must use a const interator here, otherwise we get a compiler error.
    typename vector<T>::const_iterator i;
    for (i = l.begin(); i != l.end(); ++i)
    {
        cout << *i << ",";
    }
    cout << endl;
}


// C functions that can be used with STL algorithms
template <typename T>
void MultiplyByTwo(T& t)
{ // Modifier function
    
    t *=2;
}

template <typename T>
T Square(const T& t)
{ // Selector function
    
    return t*t;
}


int main()
{
    
    // ================================== A. NUMERIC ALGORITHMS ==================================
    int size = 4;
    vector<int> vec(size);
    for (int i = 0; i < vec.size(); ++i)
    {
        vec[i] = i+1;
    }
    vec[1] = 5;
    
    print(vec, string("original vector vec: "));
    
    // (1.1) Accumulate: Compute the result of one sequence.
    int initVal = 1;                                        // Must be initialized to a value
    int acc1 = accumulate(vec.begin(), vec.end(), initVal); // Add initVal to all elements
    cout << "Sum 1: " << acc1 << endl;                      // 1 + 1 + 5 + 3 + 4 = 14
    
    // (1.2) Multiply (using predefined function object) each element by initVal and sum them
    int acc2 = accumulate(vec.begin(), vec.end(), initVal, multiplies<int>());
    cout << "Sum 2: " << acc2 << endl;                      // 1 * 5 * 3 * 4 * 1 = 60
    
    // (2.1) Sums of products + initVal
    int ip1 = inner_product(vec.begin(), vec.end(), vec.begin(), initVal);
    cout << "Inner product1: " << ip1 << endl;              // 1 + 1*1 + 5*5 + 3*3 + 4*4 = 52
    
    // (2.2) Using two predefined function objects using inner and outer operations
    
    // Product of sums: multiplies( initVal, plus(*vec, *vec2) )
    vector<int> vec2(vec);
    double ip2 = inner_product(vec.begin(), vec.end(), vec2.begin(), initVal,
                               multiplies<int>(),  // outer
                               plus<int>());       // inner
    cout << "Inner product2: " << ip2 << endl;
    
    // Sum of products: plus( initVal, multiplies(*vec, *vec2) )
    double ip3 = inner_product(vec.begin(), vec.end(), vec2.begin(), initVal,
                               plus<int>(),        // outer
                               multiplies<int>()); // inner
    cout << "Inner product3: " << ip3 << endl;
    
    
    // ================================ B. NONMODIFYING ALGORITHMS ===============================
    
    // (1) Count the number of elements equal to a given value.
    double val = 5;
    cout << "Number of elements equal to " << val << " = " << count(vec.begin(), vec.end(), val) << endl;
    
    // (2) Search for elements; find the first element in a container equal to a given value;
    int searchValue = 5;
    vector<int>::iterator posS = find(vec.begin(), vec.end(), searchValue);
    
    // Test if value has been found
    if (posS != vec.end())
    {
        cout << "Value: " << *posS << endl;
    }
    else
    {
        cout << "Value not found\n";
    }
    
    
    // ================================= C. MODIFYING ALGORITHMS =================================
    
    // (1) Modifier, user-defined function
    for_each(vec.begin(), vec.end(), MultiplyByTwo<int>);
    print(vec, string("Modifier, for each(): "));
    
    // (2) Modifier, user-defined function
    transform(vec.begin(), vec.end(), vec.begin(), Square<int>); // Overwrite itself from the beginning
    print(vec, string("Modifier, transform(): "));
    
    // (3) Replacing elements
    int M = 10;
    vector<char> vecChar(M, 'd');
    
    char oldChar = 'd';
    char newChar = 'D';
    replace(vecChar.begin(), vecChar.end(), oldChar, newChar);
    print(vecChar, string("After replace (all): "));
    
    
    // ================================= D. MUTATING ALGORITHMS =================================
    
    // (1) Reversing the order of elements
    reverse(vec.begin(), vec.end());
    print(vec, string("Modifier, vector reversed: "));
    
    // (2) Rotating elements in a sequence
    vector<int> myVec(8);
    for (int i = 0; i < myVec.size(); ++i)
    {
        myVec[i] = i + 1;
    }
    
    cout << "Number of shifts (< 0 to right, > 0 to left): "; int shift; cin >> shift;
    
    // Try to call 1 function to do the following?
    if (shift > 0)
    {
        rotate(myVec.begin(), myVec.begin() + shift, myVec.end());
        print(myVec, string("Modifier, vector rotated: "));
    }
    else
    {
        rotate(myVec.begin(), myVec.end() + shift, myVec.end());
        print(myVec, string("Modifier, vector rotated: "));
    }
    
    return 0;
}
