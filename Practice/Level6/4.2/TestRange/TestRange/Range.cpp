//
//  Range.cpp
//  TestRange
//
//  Created by Changheng Chen on 1/22/17.
//  Copyright © 2017 Changheng Chen. All rights reserved.
//

#ifndef Range_CPP
#define Range_CPP

#include "Range.hpp"

// ============ Constructors and destructor =============
template <class Type>
Range<Type>::Range()
{ // Default constructor
    
    Type def(0); // Need this, set to 0, same as Type def = 0;
    lo = def;
    hi = def;
}

template <class Type>
Range<Type>::Range(const Type& l, const Type& h)
{
    if (l < h)
    {
        lo = l;
        hi = h;
    }
    else
    {
        hi = l;
        lo = h;
    }
}

template <class Type>
Range<Type>::Range(const Range<Type>& r2)
{ // Copy constructor
    
    lo = r2.lo;
    hi = r2.hi;
}

template <class Type>
Range<Type>::~Range()
{ // Deconstructor
    
}

// ================== Getter functions ==================
template <class Type>
Type Range<Type>::low() const
{ // Return the lower bound of range
    
    return lo;
}

template <class Type>
Type Range<Type>::high() const
{ // Return the higher bound of range
    
    return hi;
}

template <class Type>
Type Range<Type>::spread() const
{ // Return the higher bound of the range
    
    return hi - lo;
}


// ================= Modifier functions =================
template <class Type>
void Range<Type>::low(const Type& t1)
{ // The low value of the range will be set to the value t1
    
    lo = t1;
}

template <class Type>
void Range<Type>::high(const Type& t2)
{ // The high value of the range will be set to the value t2
    
    hi = t2;
}

// ================= Boolean functions =================
template <class Type>
bool Range<Type>::left(const Type& val) const
{ // Check if current value is to the left of the range
    
    if (val < lo)
        return true;
    
    return false;
}

template <class Type>
bool Range<Type>::right(const Type& val) const
{ // Check if the current value is to the right of the range
    
    if (val > hi)
        return true;
    
    return false;
}

template <class Type>
bool Range<Type>::contains(const Type& t) const
{ // Does range contain t
    
    if ((lo<=t) && (hi>=t))
        return true;
    
    return false;
}

// =============== Operator overloading ================
template <class Type>
Range<Type>& Range<Type>::operator = (const Range<Type>& r2)
{ // Assignment operator
    
    hi = r2.hi;
    lo = r2.lo;
    
    return *this;
}

#endif
