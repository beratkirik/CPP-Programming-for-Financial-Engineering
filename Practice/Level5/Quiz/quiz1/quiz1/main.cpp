//
//  main.cpp
//  quiz1
//
//  Created by Changheng Chen on 3/14/17.
//  Copyright © 2017 Changheng Chen. All rights reserved.
//

#include <iostream>

class A
{
public:
    virtual std::string F() = 0;
};

class B: public A
{
public:
    std::string F() { return "B"; }
};

int main()
{
    //A a;  // ERROR: variable type 'A' is an abstract base class
    B b;
    A* ap=&b; // Assign the address of b to ap
    //A* ap = b; // No viable conversion from 'B' to 'A *'!
    
    //B* bp = &b; // OK
    
    std::cout<<b.F()<<", ";        // B
    std::cout<<ap->F()<<std::endl; // B
    
    return 0;
}
