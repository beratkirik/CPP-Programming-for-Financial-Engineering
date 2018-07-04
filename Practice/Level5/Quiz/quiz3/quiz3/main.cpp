//
//  main.cpp
//  quiz3
//
//  Created by Changheng Chen on 3/14/17.
//  Copyright © 2017 Changheng Chen. All rights reserved.
//

#include <iostream>

class A
{
public:
    std::string F() { return "A"; }
    //virtual std::string F() {return "A"; }
    //virtual std::string F() = 0;
};

class B: public A
{
public:
    std::string F() { return "B"; }
};

int main()
{
    A a;
    B b;
    A* ap;
    
    std::cout<<a.F()<<", "; // A
    std::cout<<b.F()<<", "; // B
    
    ap=&a; std::cout<<ap->F()<<", ";      // A
    ap=&b; std::cout<<ap->F()<<std::endl; // A, if base class is abstract, then B
    
    
    B* bp;
    //bp=&a; std::cout<<bp->F()<<", ";       // Assigning to 'B *' to incompatiable type 'A *'
    bp=&b; std::cout<<bp->A::F()<<std::endl; // A
    bp=&b; std::cout<<bp->F()<<std::endl;    // B
    
    return 0;
}

/*
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
    A a; B b;
    A* ap=&b;
    
    std::cout<<b.F()<<", ";
    std::cout<<ap->F()<<std::endl;
    
    return 0;
}
 */

/*
class A
{
public:
    virtual std::string F() { return "A"; }
};

class B: public A
{
public:
    std::string F() { return "B"; }
};

int main()
{
    A a; B b;
    A* ap;
    
    std::cout<<a.F()<<", "; // A
    std::cout<<b.F()<<", "; // B
    
    ap=&a; std::cout<<ap->F()<<", ";      // A
    ap=&b; std::cout<<ap->F()<<std::endl; // B
    
    return 0;
}
*/
