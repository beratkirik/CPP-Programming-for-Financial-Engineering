//
//  StackEmptyException.hpp
//  Exercise 6
//
//  Created by Changheng Chen on 2/2/17.
//  Copyright © 2017 Changheng Chen. All rights reserved.
//

#ifndef StackEmptyException_hpp
#define StackEmptyException_hpp

#include "StackException.hpp"
#include <sstream>

class StackEmptyException : public StackException
{
private:
    string m_chars;
    
public:
    StackEmptyException(string chars)
    { // Constructor with "chars" as input, and store to data member
        
        m_chars = chars;
    }
    
    string GetMessage()
    { // Return the the error message
        
        stringstream ss;
        ss << "The stack is " << m_chars << "." << endl;
        
        return ss.str();
    }
};

#endif /* StackEmptyException_hpp */
