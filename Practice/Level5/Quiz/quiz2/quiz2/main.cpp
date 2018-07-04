//
//  main.cpp
//  quiz2
//
//  Created by Changheng Chen on 3/14/17.
//  Copyright © 2017 Changheng Chen. All rights reserved.
//

#include <iostream>

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
