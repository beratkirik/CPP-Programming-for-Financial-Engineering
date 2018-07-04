// FullMatrix.cpp
//
// Template class for normal matrices.
// A size_t is used for indexing. Indexing starts at 1.
//
// 2002-4-8 DD Another possibility FArray<FArray <TValue> >; Use or redundant values nr, nc
//
// (C) Datasim Component Technology 1999

#ifndef DSFullMatrix_cpp
#define DSFullMatrix_cpp

#include "UtilitiesDJD/VectorsAndMatrices/FullMatrix.hpp"

// Constructors & destructor
template <class V, class TA>
FullMatrix<V, TA>::FullMatrix(): MatrixStructure<V>()
{ // Default constructor

	m_structure=FullArray<FullArray<V, TA>, std::allocator<FullArray<V, TA> > >();

	nr = nc = 1;
}

template <class V, class TA>
FullMatrix<V, TA>::FullMatrix(size_t rows, size_t columns): MatrixStructure<V>()
{ // Constructor with size

	// Create the rows
	m_structure=FullArray<FullArray<V, TA>, std::allocator<FullArray<V, TA> > >(rows);

	// Add the colums to the rows
	for (size_t i=1; i<=m_structure.Size(); i++) m_structure[i]=FullArray<V, TA>(columns);

	nr = rows; nc = columns;
}

template <class V, class TA>
FullMatrix<V, TA>::FullMatrix(const FullMatrix<V, TA>& source): MatrixStructure<V>(source)
{ // Copy constructor

	m_structure=source.m_structure;

	nr = sopurce.nr; nc = source.nc;
}

template <class V, class TA>
FullMatrix<V, TA>::~FullMatrix()
{ // Destructor
}

// Selectors
template <class V, class TA>
size_t FullMatrix<V, TA>::Rows() const
{ // Number of rows

	return nr;
}

template <class V, class TA>
size_t FullMatrix<V, TA>::Columns() const
{ // Number of columns

	return nc;
}

// Modifiers
// Operators
template <class V, class TA>
ArrayStructure<V>& FullMatrix<V, TA>::operator[] (size_t row)
{ // Subscripting operator

	return m_structure[row];
}

template <class V, class TA>
const ArrayStructure<V>& FullMatrix<V, TA>::operator[] (size_t row) const
{ // Subscripting operator

	return m_structure[row];
}

template <class V, class TA>
FullMatrix<V, TA>& FullMatrix<V, TA>::operator = (const FullMatrix<V, TA>& source)
{ // Assignment operator

	// Exit if same object
	if (this==&source) return *this;

	// Call base class assignment
	MatrixStructure<V>::operator = (source);

	m_structure=source.m_structure;

	nr = source.nr; nc = source.nc;

	return *this;
}



#endif	// DSFullMatrix_cpp
