// Range.cpp
//
// Range class
//
// Last modification dates.
//
// dm 24-5-1994 The main fumctions were tested and modified accordingly.
// dm 25-5-1994 The functions to return the low and high values in ranges were added.
// dm 7-6-1994 the void functions high and low are added.
// dm 17-6-1994 the function cover was added    
// AM 03-08-1994 Changed the name of range from DSGENRANGE to DSRange
// AM 04-08-1994 Changed set_low() and set_high() to low() and high()
// AM 08-08-1994 Changed code to use the min() and max() function again
// dm 25-08-1994 Corrections made to code so all functions work
// AM 25-03-1996 Created function contains
// AM 25-03-1996 Changed subset, intersects modified to use contains
// 2001-1-30 DD length() function
// 20023-1-21 DD Lite version for book
//
// (C) Datasim Education BV 1994-2006


#ifndef Range_CPP
#define Range_CPP

#include "Range.hpp"

// Constructors
template <class Type>
Range<Type>::Range()
{ // Default constructor.
	
	Type def(0); // Need this
	lo = def;
	hi = def;
}

template <class Type> 
Range<Type>::Range(const Type& l, const Type& h)
{ //
	if(l < h)
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
{ // Destructor

}


template <class Type>
void Range<Type>::low(const Type& t1)
{// The low value of the range will be set with the value t1


	lo = t1;
}

template <class Type>
void Range<Type>::high(const Type& t1)
{// The high value of the range will be set with the value t1


	hi = t1;
}

template <class Type>
Type Range<Type>::low() const
{// Returns the lower bound of the range

	return lo;
}

template <class Type>
Type Range<Type>::high() const
{// Returns the higher bound of the range

	return hi;
}

template <class Type>
Type Range<Type>::spread() const
{// Returns the higher bound of the range

	return hi - lo;
}


template <class Type>
bool Range<Type>::left(const Type& val) const
{ // Check if current value is to the left of the range

	if(val < lo)
		return true;

	return false;
}

template <class Type>
bool Range<Type>::right(const Type& val) const
{ // Check if current value is to the right of the range

	if(val > hi)
		return true;

	return false;
}

template <class Type>
bool Range<Type>::contains(const Type& t) const
{// Does range contain t

	if((lo <= t) && (hi >= t))
		return true;

	return false;
}

// Operator overloading
template <class Type>
Range<Type>& Range<Type>::operator = (const Range<Type>& r2)
{ // Assignment operator

	hi = r2.hi;
	lo = r2.lo;

	return *this;
}


#endif	// Range_CPP
