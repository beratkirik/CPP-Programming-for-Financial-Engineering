//
//  main.cpp
//  quiz4
//
//  Created by Changheng Chen on 3/14/17.
//  Copyright © 2017 Changheng Chen. All rights reserved.
//

#include <iostream>

class A
{
private:
    int m_data;
    
public:
    A(): m_data(GetValue()) {}
    int Calculate() { return m_data*1.5; }
    virtual int GetValue() { return 10; }
};

class B: public A
{
public:
    virtual int GetValue() { return 20; }  // with/without 'virtual' in the derived class, result's same
};

int main()
{
    A a; B b; A* ap;
    
    ap=&a; std::cout<<ap->GetValue()<<", "<<ap->Calculate()<<", ";      // 10, 15
    ap=&b; std::cout<<ap->GetValue()<<", "<<ap->Calculate()<<std::endl; // 20, 15
    
    return 0;
}

/*
class A
{
private:
    virtual int GetValue() { return 10; }
    
public:
    int Calculate() { return GetValue()*1.5; }
};

class B: public A
{
private:
    virtual int GetValue() { return 20; }
};

int main()
{
    A a; B b;
    std::cout<<a.Calculate()<<", "<<b.Calculate()<<std::endl;  // 15, 30
 
    return 0;
}

*/
