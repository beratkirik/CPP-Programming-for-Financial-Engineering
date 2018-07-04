// NumericMatrix.cpp
//
// Numeric matrix class.
// This is a matrix class for numerical data. Derived from Matrix and 
// it adds mathematical functions.
//
// 2 february 1999	RD	Started
// 2002-4-9 DD removed functions that belong elsewhere
// 2005-12-4 DD bug fix m1 + and - m2
// 2005-12-17 DD size_t -> I
// 2006-8-10 DD fix a bug mat*mat
// 2009-4-10 DD Transpose function; fix in mat*mat
//
// (C) Datasim Component Technology 1999-2006

#ifndef NumericMatrix_cpp
#define NumericMatrix_cpp

#include "UtilitiesDJD/VectorsAndMatrices/NumericMatrix.hpp"


// Constructors & destructor
template <class V, class I, class S>
NumericMatrix<V, I, S>::NumericMatrix(): Matrix<V, I, S>()
{ // Default constructor
}

template <class V, class I, class S>
NumericMatrix<V, I, S>::NumericMatrix(I rows, I columns): Matrix<V, I, S>(rows, columns)
{ // Constructor with size. Start index=0.
}

template <class V, class I, class S>
NumericMatrix<V, I, S>::NumericMatrix(I rows, I columns, I rowStart, I columnStart): Matrix<V, I, S>(rows, columns, rowStart, columnStart)
{ // Constructor with size & start index
}

template <class V, class I, class S>
NumericMatrix<V, I, S>::NumericMatrix(const Matrix<V, I, S>& source): Matrix<V, I, S>(source)
{ // Constructor with matrix
}

template <class V, class I, class S>
NumericMatrix<V, I, S>::NumericMatrix(const NumericMatrix<V, I, S>& source): Matrix<V, I, S>(source)
{ // Copy constructor
}

template <class V, class I, class S>
NumericMatrix<V, I, S>::~NumericMatrix()
{ // Destructor
}

// Selectors
template <class V, class I, class S>
Vector<V, I> NumericMatrix<V, I, S>::Row(I row) const
{ // Return row. Overloads Matrix::Row() to return Vector instead of Array

	//return Vector<V, I>(Matrix<V, I, S>::Row(row));
	// We make a copy in this version
	Vector<V,I> result(Columns(), MinColumnIndex());
	for (I j = result.MinIndex(); j <= result.MaxIndex(); ++j)
	{
		result[j] = (*this)(row, j);
	}

	return result;
}

template <class V, class I, class S>
Vector<V, I> NumericMatrix<V, I, S>::Column(I column) const
{ // Return Column. Overloads Matrix::Row() to return Vector instead of Array

	return Vector<V, I>(Matrix<V, I, S>::Column(column));
}


// Modifiers
template <class V, class I, class S>
void NumericMatrix<V, I, S>::Row(I row, const Array<V, I>& val)
{ // Replace row. Overloaded because Row() selector is overloaded thus hiding Matrix::Row() modifier.

//	Matrix<V, I, S>::Row(row, val);

	for (I c=MinColumnIndex(); c<=MaxColumnIndex(); c++) 
	{

		(*this)(row,c) = val[c];
	}

}
/*
template <class V, class I, class S>
void NumericMatrix<V, I, S>::Column(I column, const Array<V, I>& val)
{ // Replace column. Overloaded because Column() selector is overloaded thus hiding Matrix::Column() modifier.

	Matrix<V, I, S>::Column(column, val);
}

*/
// Operators
template <class V, class I, class S>
NumericMatrix<V, I, S>& NumericMatrix<V, I, S>::operator = (const NumericMatrix<V, I, S>& source)
{ // Assignment operator

	// Exit if same object
	if (this==&source) return *this;

	// Call base class assignment
	Matrix<V, I, S>::operator = (source);

	return *this;
}

template <class V, class I, class S>
NumericMatrix<V, I, S> NumericMatrix<V, I, S>::operator - () const
{ // Unary minus

	// Create new matrix with same size and same starting index
	NumericMatrix<V, I, S> result(Rows(), Columns(), MinRowIndex(), MinColumnIndex());

	// Copy all elements negative
	for (I r=MinRowIndex(); r<=MaxRowIndex(); r++)
	{
		for (I c=MinColumnIndex(); c<=MaxColumnIndex(); c++) 
		{

			result(r,c) = -(*this)(r,c);
		}
	}

	// Return the result
	return result;
}




template <class V, class I, class S>
NumericMatrix<V, I, S> NumericMatrix<V, I, S>::operator + (const NumericMatrix<V, I, S>& m) const
{ // Add the elements

	
	// Create new matrix with same size and same starting index
	NumericMatrix<V, I, S> result(Rows(), Columns(), MinRowIndex(), MinColumnIndex());

	// Add all elements
	for (I r1=MinRowIndex(); r1<=MaxRowIndex(); r1++)
	{
		for (I c1=MinColumnIndex(); c1<=MaxColumnIndex(); c1++) 
			result(r1, c1) = (*this)(r1, c1) + m(r1, c1);

	}

	// Return the result
	return result;
}

template <class V, class I, class S>
NumericMatrix<V, I, S> NumericMatrix<V, I, S>::operator - (const NumericMatrix<V, I, S>& m) const
{ // Subtract the elements

	// Create new matrix with same size and same starting index
	NumericMatrix<V, I, S> result(Rows(), Columns(), MinRowIndex(), MinColumnIndex());
	print(result);

	// Add all elements
	for (I r1 = MinRowIndex(); r1<=MaxRowIndex(); r1++)
	{
		for (I c1=MinColumnIndex(); c1<=MaxColumnIndex(); c1++)
			result(r1, c1) = (*this)(r1, c1) - m(r1, c1);
	}

	// Return the result
	return result;
}

template <class V, class I, class S>
NumericMatrix<V, I, S> NumericMatrix<V, I, S>::operator * (const NumericMatrix<V, I, S>& m) const
{ // Multiply the matrix.
  // This function can be optimized by calculating the inner product ourselfs instead of 
  // using the InnerProduct function of Vector. This saves a couple of row and column copies.


	// Create new matrix with same row size of first matrix and column size of second matrix and same starting index as first matrix
	NumericMatrix<V, I, S> result(Rows(), m.Columns(), MinRowIndex(), MinColumnIndex());
	I r1, c2, rr, cr;

	// Element of resulting array is dot/inner product of corresponding row m1 and corresponding column m2
	for (I rr=result.MinRowIndex(); rr<=result.MaxRowIndex(); ++rr)
	{
		
		for (I cr = result.MinColumnIndex(); cr <= result.MaxColumnIndex(); ++cr) 
		{
			result(rr, cr) = 0.0;
			for (I k = result.MinColumnIndex(); k <= result.MaxColumnIndex(); ++k)
			{

					result(rr, cr) += (*this)(rr, k) * m(k,cr);
			}
			cout << "*" << rr << "," << cr << "," << result(rr, cr)<< endl;
		}
			
	}

	// Return the result
	return result;
}


template <class V, class I, class S> Vector<V, I> NumericMatrix<V, I, S>::operator * (const Vector<V, I>& v) const
{

	// Result has same number of rows as m and same start index as v
	Vector<V, I> result(Rows(), v.MinIndex());

	V r(0.0);	// sum of rows
	for (I i = MinRowIndex(); i <= MaxRowIndex(); i++)
	{
		r = 0.0;
		for (I j = MinColumnIndex(); j<= MaxColumnIndex(); j++)
		{
				r += (*this)(i,j) * v[j];
		}
		result[i] = r;
	}

	return result;
}

template <class V, class I, class S>  NumericMatrix<V, I, S> NumericMatrix<V, I, S>::Transpose() const
{ // Switch rows and columns

		NumericMatrix<V, I, S> result(Columns(), Rows());

		for (I i = result.MinRowIndex(); i <= result.MaxRowIndex(); ++i)
		{
			for (I j = result.MinColumnIndex(); j<= result.MaxColumnIndex(); ++j)
			{
					result(i,j) = (*this)(j,i);
			}
		}

		return result;

}



#endif	// NumericMatrix_cpp