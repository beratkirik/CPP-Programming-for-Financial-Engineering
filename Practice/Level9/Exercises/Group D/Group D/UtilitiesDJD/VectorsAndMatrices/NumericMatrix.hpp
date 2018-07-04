// NumericMatrix.hpp
//
// Numeric matrix class.
// This is a matrix class for numerical data. Derived from Matrix and 
// it adds mathematical functions.
//
// (C) Datasim Component Technology 1999-2009

#ifndef NumericMatrix_hpp
#define NumericMatrix_hpp

#include "UtilitiesDJD/VectorsAndMatrices/Matrix.cpp"
#include "UtilitiesDJD/VectorsAndMatrices/Vector.cpp"


// Default structure is FullArray with default allocator. Default integral type is int.
template <class V, class I=int, class S=FullMatrix<V> >
class NumericMatrix: public Matrix<V, I, S>
{
private:

public:
	// Constructors & destructor
	NumericMatrix();													// Default constructor
	NumericMatrix(I rows, I columns);							// Constructor with size. Start index=1.
	NumericMatrix(I rows, I columns, I rowStart, I columnStart);		// Constructor with size & start index
	NumericMatrix(const Matrix<V, I, S>& source);			// Constructor with matrix
	NumericMatrix(const NumericMatrix<V, I, S>& source);	// Copy constructor
	virtual ~NumericMatrix();							// Destructor

	// Selectors
	Vector<V, I> Row(I row) const;					// Return row. Overloads Matrix::Row() to return Vector instead of Array
	Vector<V, I> Column(I column) const;			// Return column. Overloads Matrix::Row() to return Vector instead of Array

	
	// Modifiers
	void Row(I row, const Array<V, I>& val);		// Replace row
//	void Column(I column, const Array<V, I>& val);	// Replace column

	// Operators
	NumericMatrix<V, I, S>& operator = (const NumericMatrix<V, I, S>& source);

	NumericMatrix<V, I, S> operator - () const;			// Unary minus

	
	NumericMatrix<V, I, S> operator + (const NumericMatrix<V, I, S>& m) const;		// Add the elements
	NumericMatrix<V, I, S> operator - (const NumericMatrix<V, I, S>& m) const;		// Subtract the elements
	NumericMatrix<V, I, S> operator * (const NumericMatrix<V, I, S>& m) const;		// Multiply the matrices
	Vector<V, I> operator * (const Vector<V, I>& v) const;

	NumericMatrix<V, I, S> Transpose() const;										// Switch rows and columns


};

#endif