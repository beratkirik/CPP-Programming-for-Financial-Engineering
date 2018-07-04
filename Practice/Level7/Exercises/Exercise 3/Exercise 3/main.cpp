//
//  main.cpp
//  Exercise 3
//
//  Created by Changheng Chen on 2/6/17.
//  Copyright © 2017 Changheng Chen. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <vector>
#include "LessThan.hpp"
using namespace std;

// Define a global variable
double threshold = 3.0; // The user may change this value once and for all

int main()
{
    // Create a vector and assign values to it
    int size = 5;
    vector<double> v(size);
    for (int i = 0; i < v.size(); ++i)
    {
        v[i] = i + 1.0; // 1.0, 2.0, 3.0, 4.0, 5.0
    }
    
    // Use the global function less_than
    cout << "Global function: number of elements smaller than " << threshold << ": " << endl;
    cout << count_if(v.begin(), v.end(), less_than<double>) << endl << endl; 
    
    // Use the class LessThan
    cout << "Function object: number of elements smaller than " << threshold << ": " << endl;
    cout << count_if(v.begin(), v.end(), LessThan(threshold)) << endl;
    
    return 0;
}
