//
//  Range.hpp
//  TestRange
//
//  A class that represents a closed interval [low, high]. This is
//  needed in many applications, for example candlestick charts in
//  financial futures.
//
//  Created by Changheng Chen on 1/22/17.
//  Copyright © 2017 Changheng Chen. All rights reserved.
//

#ifndef Range_hpp
#define Range_hpp

template <class Type = double>   // Default template parameter is double
class Range
{
    
private:
    Type lo;
    Type hi;
    
public:
    // Constructors
    Range();                                   // Default constructor
    Range(const Type& low, const Type& high);  // Low and high value
    Range(const Range<Type>& ran2);            // Copy constructor
    
    // Destructor
    virtual ~Range();
    
    // Getter functions
    Type low() const;                          // Lowest value in range
    Type high() const;                         // Highest value in range
    Type spread() const;                       // High - Low value
    
    // Modifier functions
    void low(const Type& t1);                  // Set low value to t1
    void high(const Type& t2);                 // Set high value to t2
    
    // Boolean functions
    bool left(const Type& value) const;        // Is the value to the left of the range?
    bool right(const Type& value) const;       // Is the value to the right of the range?
    bool contains(const Type& value) const;    // Does range contain value?
    
    // Operator overloading
    Range<Type>& operator = (const Range<Type>& ran2); 
};

#endif /* Range_hpp */
