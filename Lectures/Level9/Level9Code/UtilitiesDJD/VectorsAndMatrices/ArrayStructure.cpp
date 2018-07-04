// ArrayStructure.cpp
//
// Base class for Array storage structure.
// A size_t is used for indexing. Indexing starts at 0.
//
// 28 january 1999	RD	Started
// 2002-4-8 DD small changes
//
// (C) Datasim Component Technology 1999

#ifndef ArrayStructure_cpp
#define ArrayStructure_cpp

#include "UtilitiesDJD/VectorsAndMatrices/ArrayStructure.hpp"


// Constructors & destructor
template <class V>
ArrayStructure<V>::ArrayStructure()
{ // Default constructor
}

template <class V>
ArrayStructure<V>::ArrayStructure(const ArrayStructure<V>& source)
{ // Copy constructor
}

template <class V>
ArrayStructure<V>::~ArrayStructure()
{ // Destructor
}

// Selectors
template <class V>
inline const V& ArrayStructure<V>::Element(size_t index) const
{ // Get element at position

	// Use the subscript operator in derived classes
	return ((*this)[index]);
	
}

template <class V>
size_t ArrayStructure<V>::MinIndex() const
{ // Return the minimum index

	// Always ONE
	return 1;
}

template <class V>
size_t ArrayStructure<V>::MaxIndex() const
{ // Return the maximum index


	return Size();
}

// Modifiers
template <class V>
inline void ArrayStructure<V>::Element(size_t index, const V& val)
{ // Change element at position

	// Use the subscript operator in derived classes
	(*this)[index]=val;
}

template <class V>
ArrayStructure<V>& ArrayStructure<V>::operator = (const ArrayStructure<V>& source)
{ // Assignment operator
	
	return *this;
}

#endif	// ArrayStructure_cpp
