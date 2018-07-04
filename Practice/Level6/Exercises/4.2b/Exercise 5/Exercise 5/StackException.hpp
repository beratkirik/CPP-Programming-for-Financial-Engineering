//
//  StackException.hpp
//  Exercise 5
//
//  Created by Changheng Chen on 2/2/17.
//  Copyright © 2017 Changheng Chen. All rights reserved.
//

#ifndef StackException_hpp
#define StackException_hpp

#include <string>
using namespace std;

class StackException
{
public:
    virtual string GetMessage() = 0;
};

#endif /* StackException_hpp */
