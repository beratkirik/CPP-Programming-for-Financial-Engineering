//
//  StackFullException.hpp
//  Exercise 5
//
//  Created by Changheng Chen on 2/2/17.
//  Copyright © 2017 Changheng Chen. All rights reserved.
//

#ifndef StackFullException_hpp
#define StackFullException_hpp

#include "StackException.hpp"
#include <sstream>

class StackFullException : public StackException
{
private:
    string m_chars;
    
public:
    StackFullException(string chars)
    { // Constructor with "chars" as input, and store to data member
        
        m_chars = chars;
    }
    
    string GetMessage()
    { // Return the array index in the error message
        
        stringstream ss;
        ss << "\nThe stack is " << m_chars << "." << endl;
        
        return ss.str();
    }
};

#endif /* StackFullException_hpp */
