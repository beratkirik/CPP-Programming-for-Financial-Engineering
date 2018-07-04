//
//  WrongShapeException.h
//  Exercise 3
//
//  Created by Changheng Chen on 2/10/17.
//  Copyright © 2017 Changheng Chen. All rights reserved.
//

#ifndef WrongShapeException_h
#define WrongShapeException_h

#include <string>
#include <sstream>
using namespace std;

class WrongShapeException
{
private:
    string m_chars;
    
public:
    WrongShapeException(string chars)
    { // Constructor with "chars" as input, and store to data member
        
        m_chars = chars;
    }
    
    string GetMessage()
    { // Return the the error message
        
        stringstream ss;
        ss << "Shape '" << m_chars << "' does not exist." << endl;
        
        return ss.str();
    }
};

#endif /* WrongShapeException_h */
