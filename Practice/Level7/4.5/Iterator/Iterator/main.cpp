//
//  main.cpp
//  Iterator
//
//  Created by Changheng Chen on 2/6/17.
//  Copyright © 2017 Changheng Chen. All rights reserved.
//

#include <iostream>
#include <list>
#include <vector>

int main()
{
    std::list<int> l;        // Empty list
    std::vector<int> v(10);  // Vector with 10 elements
    
    for (int i=0; i<10; i++)
        l.push_back(i);      // Fill list
    
    // Copy list elements to vector
    std::list<int>::iterator il=l.begin();
    std::vector<int>::iterator iv=v.begin();
    while (il!=l.end())
    {
        *(iv++)=*(il++);
    }
    
    // Print vector
    for (iv=v.begin(); iv!=v.end(); iv++)
    {
        std::cout<<(*iv)<<", ";
    }
    std::cout<<std::endl;
    
    return 0;
}
