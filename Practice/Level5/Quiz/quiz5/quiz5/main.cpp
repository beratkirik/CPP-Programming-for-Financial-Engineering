//
//  main.cpp
//  quiz5
//
//  Created by Changheng Chen on 3/14/17.
//  Copyright © 2017 Changheng Chen. All rights reserved.
//

#include <iostream>

class A
{
private:
    int m_da;
    
public:
    A(int da): m_da(da) {}
    int GetA() { return m_da; }
    A& operator = (const A& source)
    { m_da=source.m_da; return *this; }
};

class B: public A
{
private:
    int m_db;
    
public:
    B(int da, int db): A(da), m_db(db) {}
    int GetB() { return m_db; }
    B& operator = (const B& source)
    { m_db=source.m_db; return *this; }
    //{ A::operator=(source); m_db=source.m_db; return *this; }
};

int main()
{
    B b1(10, 20); B b2(30, 40);
    b1=b2;  // 10->10; 20->40
    std::cout<<b1.GetA()<<", "<<b1.GetB()<<std::endl; // 10. 40
    return 0;
}
