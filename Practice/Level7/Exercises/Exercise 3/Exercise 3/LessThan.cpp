//
//  LessThan.cpp
//  Exercise 3
//
//  Created by Changheng Chen on 2/6/17.
//  Copyright © 2017 Changheng Chen. All rights reserved.
//

#include <iostream>
#include "LessThan.hpp"


LessThan::LessThan(double value) : benchmark(value)
{ // Set threshold value in constructor
    
}

LessThan::~LessThan()
{ // Destructor
    
}

bool LessThan::operator () (double val)
{ // Member function
    
    return (val < threshold);
}
