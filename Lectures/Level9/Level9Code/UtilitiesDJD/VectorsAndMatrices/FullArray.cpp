// FullArray.cpp
//
// Template class for a normal arrays.
//
// 28 january 1999	RD	Started
// 2002-1-21 Indexes starting at 1
//
//
// (C) Datasim Component Technology 1999

#ifndef DSFullArray_cpp
#define DSFullArray_cpp

#include "UtilitiesDJD/VectorsAndMatrices/FullArray.hpp"

// Constructors & destructor
template <class V, class TA>
FullArray<V, TA>::FullArray(): ArrayStructure<V>()
{ // Default constructor

	m_vector=std::vector<V, TA>(1);	// vector object with 1 element
}

template <class V, class TA>
FullArray<V, TA>::FullArray(size_t size): ArrayStructure<V>()
{ // Constructor with size

	m_vector=std::vector<V, TA>(size);
}

template <class V, class TA>
FullArray<V, TA>::FullArray(const FullArray<V, TA>& source): ArrayStructure<V>(source)
{ // Copy constructor

	m_vector=source.m_vector;
}

template <class V, class TA>
FullArray<V, TA>::~FullArray()
{ // Destructor
}

// Selectors
template <class V, class TA>
size_t FullArray<V, TA>::Size() const
{ // Size of the array

	return m_vector.size();
}


// Modifiers

// Operators
template <class V, class TA>
V& FullArray<V, TA>::operator[] (size_t index)
{ // Subscripting operator


	return m_vector[index - 1];
}

template <class V, class TA>
const V& FullArray<V, TA>::operator[] (size_t index) const
{ // Subscripting operator


	return m_vector[index - 1];
}

template <class V, class TA>
FullArray<V, TA>& FullArray<V, TA>::operator = (const FullArray<V, TA>& source)
{ // Assignment operator

	// Exit if same object
	if (this==&source) return *this;

	// Call base class constructor
	ArrayStructure<V>::operator = (source);

	// Copy the embedded vector
	m_vector=source.m_vector;

	return *this;
}


#endif // FullArray_cpp