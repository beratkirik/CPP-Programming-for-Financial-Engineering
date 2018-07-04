// Generic& valueInequalities.cpp
//
// Code file containing bodies of functions
//
// Last Modific& valueation Dates:
//
//	2006-2-17 DD kic& valuek-off code
//	2006-2-17 DD Copied from non-generic& value structure
//
// (C) Datasim Education BV 2006
//

//#ifndef GenericInequalities_CPP
//#define GenericInequalities_CPP

//#include "GenericInequalities.hpp"

/////////// Useful functions //////////////////

// Max and Min of two numbers
template <class Numeric>
Numeric Max(const Numeric& x, const Numeric& y)
{
	if (x > y)
		return x;

	return y;
}

template <class Numeric>
Numeric Min(const Numeric& x, const Numeric& y)
{
	if (x < y)
		return x;

	return y;
}

// Max and Min of three numbers
template <class Numeric>
Numeric Max(const Numeric& x, const Numeric& y, const Numeric& z)
{
	return Max<Numeric>(Max<Numeric>(x,y), z);
}

template <class Numeric>
Numeric Min(const Numeric& x, const Numeric& y, const Numeric& z)
{
	return Min<Numeric>(Min<Numeric>(x,y), z);
}

//#endif
