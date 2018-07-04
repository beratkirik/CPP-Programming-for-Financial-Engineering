// Array.hpp
//
// Array class. It uses an ArrayStructure for the actual storage.
// This class acts like a kind of adapter class since it defines a common 
// interface for different array structures like normal arrays and
// sparse arrays. The array structure to use is given as template argument.
//
// (C) Datasim Component Technology 1999-2006

#ifndef Array_hpp
#define Array_hpp

#include "UtilitiesDJD/VectorsAndMatrices/ArrayStructure.hpp"
#include "UtilitiesDJD/VectorsAndMatrices/FullArray.cpp"

// Default structure is FullArray with default allocator. Default integral type is int.
template <class V, class I=int, class S=FullArray<V> >
class Array
{
private:
	S m_structure;			// The array structure
	I m_start;				// The start index

public:
	// Constructors & destructor
	Array();							// Default constructor
	Array(I size);					// Constructor with size. Start index=1.
	Array(I size, I start);		// Constructor with size & start index
	Array(I size, I start, const V& value);	// Size, start and value
	Array(const Array<V, I, S>& source);		// Copy constructor
	virtual ~Array();					// Destructor

	// Selectors
	I MinIndex() const;								// Return the minimum index
	I MaxIndex() const;								// Return the maximum index
	I Size() const;							// The size of the array

	// Operators
	virtual V& operator [] (I index);				// Subscripting operator
	virtual const V& operator [] (I index) const;	// Subscripting operator

	Array<V, I, S>& operator = (const Array<V, I, S>& source);
};

#endif	// Array_hpp