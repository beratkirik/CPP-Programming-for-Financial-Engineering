// Matrix.hpp
//
// Matrix class. It uses an MatrixStructure for the actual storage.
// This class acts like a kind of adapter class since it defines a common interface
// for different matrix structures like normal matrices and sparse matrices.
// The matrix structure to use is given as template argument.
//
// (C) Datasim Component Technology 1999-2006

#ifndef Matrix_hpp
#define Matrix_hpp

#include "UtilitiesDJD/VectorsAndMatrices/FullMatrix.cpp"
#include "UtilitiesDJD/VectorsAndMatrices/Array.hpp"

// Default structure is FullArray with default allocator. Default integral type is int.
template <class V, class I=int, class S=FullMatrix<V> >
class Matrix
{
private:
	S m_structure;				// The array structure
	I m_rowstart;				// The row start index
	I m_columnstart;			// The column start index

	// Redundant data 
	I nr, nc;

public:
	// Constructors & destructor
	Matrix();																			// Default constructor
	Matrix(I rows, I columns);												// Constructor with size. Start index=0.
	Matrix(I rows, I columns, I rowStart, I columnStart);		// Constructor with size & start index
	Matrix(const Matrix<V, I, S>& source);						// Copy constructor
	virtual ~Matrix();																	// Destructor

	// Selectors
	I MinRowIndex() const;				// Return the minimum row index
	I MaxRowIndex() const;				// Return the maximum row index
	I MinColumnIndex() const;			// Return the minimum column index
	I MaxColumnIndex() const;			// Return the maximum column index

	I Rows() const;					// The number of rows
	I Columns() const;				// The number of columns


	void Row(I row, const Array<V, I>& val);	// Replace row
	void Column(I column, const Array<V, I>& val);	// Replace column


	// Operators
	const V& operator () (I row, I column) const;	// Get the element at position
	V& operator () (I row, I column);				// Get the element at position

	Matrix<V, I, S>& operator = (const Matrix<V, I, S>& source);
};

#endif	// Matrix_hpp

