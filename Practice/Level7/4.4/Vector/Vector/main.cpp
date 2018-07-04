//
//  main.cpp
//  Vector
//
//  Created by Changheng Chen on 2/6/17.
//  Copyright © 2017 Changheng Chen. All rights reserved.
//

#include <iostream>
#include <vector>

int main()
{
    std::vector<int> v;   // Create vector with ints
    v.reserve(10);        // Reserve space for 10 elements

    v.push_back(10);      // Add element
    v.push_back(20);      // Add element
    v[0]=30;              // Change first element
    
    std::cout << "element 0: " << v[0] << std::endl;        // 30
    std::cout << "element 1: " << v[1] << std::endl;        // 20
    std::cout << "Size: " << v.size() << std::endl;         // 2
    std::cout << "Capacity: " << v.capacity() << std::endl; // 10
 
    v.clear();            // Clear vector
    
    return 0;
}
