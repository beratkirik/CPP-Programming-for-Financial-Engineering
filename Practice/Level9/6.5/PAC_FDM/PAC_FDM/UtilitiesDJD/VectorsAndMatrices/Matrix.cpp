// Matrix.cpp
//
// Matrix class. It uses an MatrixStructure for the actual storage.
// This class acts like a kind of adapter class since it defines a common interface
// for different matrix structures like normal matrices and sparse matrices.
// The matrix structure to use is given as template argument.
//
// 1 februari 1999	RD	Started
// 2002-4-9 DD small changes
// 2005-12-17 DD sameShape() function; ALSO size_t --> I
//
// (C) Datasim Component Technology 1999-2006

#ifndef Matrix_cpp
#define Matrix_cpp

#include "UtilitiesDJD/VectorsAndMatrices/Matrix.hpp"


// Constructors & destructor
template <class V, class I, class S>
Matrix<V, I, S>::Matrix()
{ // Default constructor

	m_structure=S();

	m_rowstart=1;
	m_columnstart=1;

	nr = nc = 1;
}

template <class V, class I, class S>
Matrix<V, I, S>::Matrix(I rows, I columns)
{ // Constructor with size. Start index=1.

	m_structure=S(rows, columns);

	m_rowstart=1;
	m_columnstart=1;

	nr = rows; nc = columns;
}

template <class V, class I, class S>
Matrix<V, I, S>::Matrix(I rows, I columns, I rowStart, I columnStart)
{ // Constructor with size & start index

	m_structure=S(rows, columns);

	m_rowstart=rowStart;
	m_columnstart=columnStart;

	nr = rows; nc = columns;
}

template <class V, class I, class S>
Matrix<V, I, S>::Matrix(const Matrix<V, I, S>& source)
{ // Copy constructor

	m_structure=source.m_structure;

	m_rowstart=source.m_rowstart;
	m_columnstart=source.m_columnstart;

	nr = source.nr; nc = source.nc;
}

template <class V, class I, class S>
Matrix<V, I, S>::~Matrix()
{ // Destructor
}

// Selectors
template <class V, class I, class S>
I Matrix<V, I, S>::MinRowIndex() const
{ // Return the minimum row index

	return m_rowstart;
}

template <class V, class I, class S>
I Matrix<V, I, S>::MaxRowIndex() const
{ // Return the maximum row index

	return m_rowstart + Rows() - 1;
}

template <class V, class I, class S>
I Matrix<V, I, S>::MinColumnIndex() const
{ // Return the minimum column index

	return m_columnstart;
}

template <class V, class I, class S>
I Matrix<V, I, S>::MaxColumnIndex() const
{ // Return the maximum column index

	return m_columnstart + Columns() - 1;
}

template <class V, class I, class S>
I Matrix<V, I, S>::Rows() const
{ // The number of rows

	return nr;
}

template <class V, class I, class S>
I Matrix<V, I, S>::Columns() const
{ // The number of columns

	return nc;
}

template <class V, class I, class S>
void Matrix<V, I, S>::Row(I row, const Array<V, I>& val)
{ // Replace row

	I i, j;
	
	cout << "mod row";
	print(val);
	int y; cin >> y;
	// Replace the row elements
	for (i=val.MinIndex(), j = MinColumnIndex(); i<=val.MaxIndex(); i++, j++) m_structure[row][j]=val[i];
}

template <class V, class I, class S>
void Matrix<V, I, S>::Column(I column, const Array<V, I>& val)
{ // Replace column

	I i, j;

	// Replace the column elements
	for (i=val.MinIndex(), j=MinRowIndex(); i<=val.MaxIndex(); i++, j++) m_structure[j][column]=val[i];
}




// Operators
template <class V, class I, class S>
inline const V& Matrix<V, I, S>::operator () (I row, I column) const
{ // Get the element at position

	
	return m_structure[row - m_rowstart + 1][column - m_columnstart + 1];
}

template <class V, class I, class S>
V& Matrix<V, I, S>::operator () (I row, I column)
{ // Get the element at position

	return m_structure[row - m_rowstart + 1][column - m_columnstart + 1];
}




template <class V, class I, class S>
inline Matrix<V, I, S>& Matrix<V, I, S>::operator = (const Matrix<V, I, S>& source)
{ // Assignment operator

	// Exit if same object
	if (this==&source) return *this;

	m_structure=source.m_structure;

	m_rowstart=source.m_rowstart;
	m_columnstart=source.m_columnstart;

	nr = source.nr; nc = source.nc;


	return *this;
}



#endif	// Matrix_cpp
