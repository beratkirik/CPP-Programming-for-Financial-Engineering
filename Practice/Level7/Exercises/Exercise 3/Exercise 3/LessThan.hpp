//
//  LessThan.hpp
//  Exercise 3
//
//  Created by Changheng Chen on 2/6/17.
//  Copyright © 2017 Changheng Chen. All rights reserved.
//

#ifndef LessThan_hpp
#define LessThan_hpp

// The global variable
extern double threshold;


class LessThan
{
private:
    double benchmark;       // Threshold value
    
public:
    LessThan(double value); // Constructor with a threshold value
    ~LessThan();            // Destructor
    
    bool operator () (double val); // Member function
};


// Global function template
template <typename T>
bool less_than(const T& val)
{ // Using global variable instead of hard-coding
    
    return (val < threshold);
}

#endif /* LessThan_hpp */
