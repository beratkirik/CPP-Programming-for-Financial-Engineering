//
//  main.cpp
//  quiz3
//
//  Created by Changheng Chen on 3/14/17.
//  Copyright © 2017 Changheng Chen. All rights reserved.
//

#include <iostream>


class E
{
public:
    virtual std::string GetMessage() { return "Exception E"; }
};

class EA: public E
{
public:
    virtual std::string GetMessage() { return "Exception EA"; }
};

class EB: public E
{
public:
    virtual std::string GetMessage() { return "Exception EB"; }
};

void F()
{
    throw EA();
}


// When having the following code, what is the catch syntax for combining a polymorphic net with an explicit net?

int main()
{
    try
    {
        F();
    }
    catch (EA& ex)
    {
        std::cout<<"Handling EA"<<std::endl;  // Once catch, the next catch is escaped...
    }
    catch (E& ex)
    {
        std::cout<<ex.GetMessage()<<std::endl;
    }
    
    return 0;
}
