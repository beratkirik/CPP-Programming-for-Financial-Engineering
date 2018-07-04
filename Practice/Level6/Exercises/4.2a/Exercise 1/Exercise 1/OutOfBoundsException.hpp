//
//  OutOfBoundsException.hpp
//  Exercise 1
//
//  Created by Changheng Chen on 1/23/17.
//  Copyright © 2017 Changheng Chen. All rights reserved.
//

#ifndef OutOfBoundsException_hpp
#define OutOfBoundsException_hpp

#include "ArrayException.hpp"
#include <string>
#include <sstream>
using namespace std;

class OutOfBoundsException : public ArrayException
{
private:
    int m_index;
    
public:
    OutOfBoundsException(int index)
    { // Constructor with the erroneous array "index" as input, and store to data member
        
        m_index = index;
    }
    
    string GetMessage()
    { // Return the array index in the error message
        
        stringstream ss;
        ss << "The index " << m_index << " is out of bounds." << endl;
        return ss.str();
    }
};

#endif /* OutOfBoundsException_hpp */
