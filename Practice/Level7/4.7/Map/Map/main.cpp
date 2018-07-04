//
//  main.cpp
//  Map
//
//  Created by Changheng Chen on 2/6/17.
//  Copyright © 2017 Changheng Chen. All rights reserved.
//

#include <iostream>
#include <map>

// Compare function object for const char*
struct Comp
{
    bool operator () (const char* s1, const char* s2) const
    {
        return strcmp(s1, s2)<0;
    }
};


// Print function for maps
template <typename T1, typename T2, typename C>
void PrintMap(const std::map<T1, T2, C>& m)
{
    typename std::map<T1, T2, C>::const_iterator it=m.begin();
    
    for (it=m.begin(); it!=m.end(); it++)
        std::cout << it->first << ": " << it->second << std::endl;
    
    std::cout << std::endl;
}


int main()
{
    // Create map with key: const char*, val: double and functor
    std::map<const char*, double, Comp> price;
    std::map<const char*, double, Comp>::iterator it;
    
    // Set the value of elements. (prices of products)
    // If key doesn't exist element will be added automatically.
    price["Milk"] = 1.29;
    price["Butter"] = 0.99;
    price["Pudding"] = 2.29;
    price["Ice"] = 4.29;
    price["Milk"] = 1.25;      // This will change the price
    
    PrintMap(price);           // Print map
    
    // Find the price of Milk
    std::cout << "Milk price: " << price["Milk"] << std::endl;
    
    // Find the price of butter
    it = price.find("Butter");
    std::cout << "Butter price: " << it->second << std::endl;
}
