//
//  main.cpp
//  Multimap
//
//  Created by Changheng Chen on 2/6/17.
//  Copyright © 2017 Changheng Chen. All rights reserved.
//

#include <iostream>
#include <map>

int main()
{
    // Create multimap with key: char, val: int
    std::multimap<char, int> m;
    std::multimap<char, int>::iterator it;
    
    // Fill multimap
    m.insert(std::make_pair('a', 5));
    m.insert(std::make_pair('c', 4));
    m.insert(std::make_pair('b', 3));
    m.insert(std::make_pair('a', 1));
    m.insert(std::make_pair('c', 9));
    
    // Print number of same key elements (2, 1, 2)
    std::cout << "Nr. of 'a' elements: " << m.count('a') << std::endl;
    std::cout << "Nr. of 'b' elements: " << m.count('b') << std::endl;
    std::cout << "Nr. of 'c' elements: " << m.count('c') << std::endl;
    
    // Print all elements
    for (it=m.begin(); it!=m.end(); it++)
        std::cout << it->first << ", " << it->second << std::endl;
    
    return 0;
}
