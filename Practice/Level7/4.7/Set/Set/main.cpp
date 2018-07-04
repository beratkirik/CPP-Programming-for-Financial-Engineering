//
//  main.cpp
//  Set
//
//  Created by Changheng Chen on 2/6/17.
//  Copyright © 2017 Changheng Chen. All rights reserved.
//

#include <iostream>
#include <set>


template <typename T, typename C>
void PrintSet(const std::set<T, C>& s)
{
    std::copy(s.begin(), s.end(), std::ostream_iterator<T>(std::cout, ", "));
    std::cout<<std::endl;
}


int main()
{ // Fill two arrays with values
    double arr1[6]={8.5, 9.2, 4.1, 3.5, 8.5, 8.1};
    double arr2[6]={5.3, 6.2, 4.1, 8.5, 6.5, 1.1};
    
    std::set<double> s1(arr1, arr1+6);          // Create set of arr1
    std::set<double> s2(arr2, arr2+6);          // Create set of arr2
    std::set<double, std::greater<double> > s3; // Set with sort FO
    
    // Make union of s1 and s2 and insert result in s3
    std::set_union(s1.begin(), s1.end(), s2.begin(), s2.end(), std::inserter(s3, s3.begin()));
    
    // Print sets
    PrintSet(s1);  // 3.5, 4.1, 8.1, 8.5, 9.2
    PrintSet(s2);  // 1.1, 4.1, 5.3, 6.2, 6.5, 8.5
    PrintSet(s3);  // 9.2, 8.5, 8.1, 6.5, 6.2, 5.3, 4.1, 3.5, 1.1
    
    return 0;
}
