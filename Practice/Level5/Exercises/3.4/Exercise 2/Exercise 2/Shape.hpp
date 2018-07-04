//
//  Shape.hpp
//  Exercise 2
//
//  Created by Changheng Chen on 1/19/17.
//  Copyright © 2017 Changheng Chen. All rights reserved.
//

#ifndef Shape_hpp
#define Shape_hpp

#include <string>
using namespace std;

class Shape
{
private:
    int m_id;
    
public:
    Shape();                                 // Default constructor
    Shape(int id);                           // Copy constructor
    virtual ~Shape();                        // Destructor
    Shape& operator = (const Shape& source); // Assignment operator
    
    int ID() const;                          // ID retrive function
    string ToString() const;                 // String description function
};

#endif /* Shape_hpp */
