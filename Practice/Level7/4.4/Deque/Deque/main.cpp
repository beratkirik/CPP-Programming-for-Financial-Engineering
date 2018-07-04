//
//  main.cpp
//  Deque
//
//  Created by Changheng Chen on 2/6/17.
//  Copyright © 2017 Changheng Chen. All rights reserved.
//

#include <iostream>
#include <deque>

int main()
{
    std::deque<int> q;  // Create deque with ints
    q.push_back(10);    // Add element
    q.push_front(20);   // Add element
    q[0]=30;            // Change first element
    
    std::cout << "element 0: " << q[0] << std::endl;  // 30
    std::cout << "element 1: " << q[1] << std::endl;  // 10
    std::cout << "Front: " << q.front() << std::endl; // 30
    std::cout << "Back: " << q.back() << std::endl;   // 10
    std::cout << "Size: " << q.size() << std::endl;   // 2
    
    q.clear();
    
    return 0;
}
