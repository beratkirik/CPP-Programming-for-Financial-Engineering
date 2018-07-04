//
//  main.cpp
//  List
//
//  Created by Changheng Chen on 2/6/17.
//  Copyright © 2017 Changheng Chen. All rights reserved.
//

#include <iostream>
#include <list>

int main()
{
    std::list<int> l;   // Create list
    
    l.push_back(10);    // Add element
    l.push_front(20);   // Add element
    l.push_back(30);    // Add element
    
    l.sort();           // Sort the list
    l.reverse();        // Reverse the list
    
    // Print the list
    std::copy(l.begin(), l.end(), std::ostream_iterator<int>(std::cout, " "));
    std::cout << std::endl;
    
    l.clear();
    
    return 0;
}
