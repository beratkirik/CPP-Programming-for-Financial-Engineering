// MatrixStructure.cpp
//
// Base class for matrix storage structure.
// A size_t is used for indexing. Indexing starts at 1.
//
// 1 february 1999	RD Started
//
// (C) Datasim Component Technology 1999

#ifndef MatrixStructure_cpp
#define MatrixStructure_cpp

#include "UtilitiesDJD/VectorsAndMatrices/MatrixStructure.hpp"


// Constructors & destructor
template <class V>
MatrixStructure<V>::MatrixStructure()
{ // Default constructor
}

template <class V>
MatrixStructure<V>::MatrixStructure(const MatrixStructure<V>& source)
{ // Copy constructor
}

template <class V>
MatrixStructure<V>::~MatrixStructure()
{ // Destructor
}

// Selectors
template <class V>
inline const V& MatrixStructure<V>::Element(size_t row, size_t column) const
{ // Get element at position

	// Use the subscripting operator of derived class
	return (*this)[row][column];
}

template <class V>
size_t MatrixStructure<V>::MinRowIndex() const
{ // Return the minimum row index

	// Always ONE
	return 1;
}

template <class V>
size_t MatrixStructure<V>::MaxRowIndex() const
{ // Return the maximum row index

	// Always row size . use the Rows() function of derived classes
	return Rows();
}

template <class V>
size_t MatrixStructure<V>::MinColumnIndex() const
{ // Return the minimum column index

	// Always ONE
	return 1;
}

template <class V>
size_t MatrixStructure<V>::MaxColumnIndex() const
{ // Return the maximum column index

	// Always column size. use the Columns() function of derived classes
	return Columns();
}

// Modifiers
template <class V>
inline void MatrixStructure<V>::Element(size_t row, size_t column, const V& val)
{ // Change element at position


	// Use the subscripting operator of derived class
	(*this)[row][column]=val;
}

// Operators
template <class V>
MatrixStructure<V>& MatrixStructure<V>::operator = (const MatrixStructure<V>& source)
{ // Assignment operator

	return *this;
}

template <class V>
inline V& MatrixStructure<V>::operator () (size_t row, size_t column)
{ // Get element at position


	// Use the subscripting operator of derived class
	return (*this)[row][column];
}

template <class V>
inline const V& MatrixStructure<V>::operator () (size_t row, size_t column) const
{ // Get element at position


	// Use the subscripting operator of derived class
	return (*this)[row][column];
}

#endif	// MatrixStructure_cpp