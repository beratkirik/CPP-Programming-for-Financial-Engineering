//
//  ArrayException.hpp
//  Exercise 2
//
//  Created by Changheng Chen on 2/10/17.
//  Copyright © 2017 Changheng Chen. All rights reserved.
//

#ifndef ArrayException_hpp
#define ArrayException_hpp

#include <string>
using namespace std;

class ArrayException
{
public:
    virtual string GetMessage() = 0;
};

#endif /* ArrayException_hpp */
