// MatrixVectorSpace.cpp
//
// Numeric  Matrix class.
// This is a COMPILE-TIME Matrix class for numerical data. 
//
// 2006-5-16 DD Kick-off
// 2006-12-27 DD adapt for new MC stuff
// 2007-1-10 DD hpp and cpp set up
// 2007-6-1 DD Testing and beta code review
// 2007-8-10 DD new Transpose() const; and M1 * M2
// 2008-8-4 DD test, debug
//
// (C) Datasim Component Technology 1999-2009

#ifndef MatrixVectorSpace_cpp
#define MatrixVectorSpace_cpp

#include "UtilitiesDJD/CompileTimeVectorsAndMatrices/MatrixVectorSpace.hpp"


// Constructors & destructor
template <typename V,int NR,int NC>
	MatrixVectorSpace<V,NR,NC>::MatrixVectorSpace()
{ // Default constructor

		V tmp(0.0);	// Assumption

		for (int i = 0; i < NR; i++)
		{
			for (int j = 0; j < NC; j++)
			{
				mat[i][j] = tmp;
			}
		}

}

template <typename V,int NR,int NC>
	MatrixVectorSpace<V,NR,NC>::MatrixVectorSpace(const V& value)
{ // Default constructor

		
	for (int i = 0; i < NR; i++)
	{
		for (int j = 0; j < NC; j++)
		{
			mat[i][j] = value;
		}
	}	

}

template <typename V,int NR,int NC>
	MatrixVectorSpace<V,NR,NC>::MatrixVectorSpace(const MatrixVectorSpace<V, NR, NC>& source)
{ // Constructor with  Matrix

	for (int i = 0; i < NR; i++)
	{
		for (int j = 0; j < NC; j++)
		{
			mat[i][j] = source.mat[i][j];
		}
	}
		
}


template <typename V,int NR,int NC>
	MatrixVectorSpace<V,NR,NC>::~MatrixVectorSpace()
{ // Destructor


}

template <typename V,int NR,int NC>
	int MatrixVectorSpace<V,NR,NC>::MinRowIndex() const
{ // Return the minimum row index

		return 1;
}

template <typename V,int NR,int NC>
	int MatrixVectorSpace<V,NR,NC>::MaxRowIndex() const
{ // Return the maximum row index

		return NR;
}

template <typename V,int NR,int NC>
	int MatrixVectorSpace<V,NR,NC>::MinColumnIndex() const
{ // Return the minimum column index

		return 1;
}

template <typename V,int NR,int NC>
	int MatrixVectorSpace<V,NR,NC>::MaxColumnIndex() const
{ // Return the maximum column index

		return NC;
}

template <typename V,int NR,int NC>
	int MatrixVectorSpace<V,NR,NC>::Rows() const
{ // The number of rows

		return NR;
}

template <typename V,int NR,int NC>
	int MatrixVectorSpace<V,NR,NC>::Columns() const
{ // The number of columns
	
		return NC;
}


	
// Operators
template <typename V,int NR,int NC> 
	const V& MatrixVectorSpace<V,NR,NC>::operator () (int row, int column) const
{ // Get the element at position


		return mat[row-1][column-1];
		
}
	
template <typename V,int NR,int NC>
	V& MatrixVectorSpace<V,NR,NC>::operator () (int row, int column)
{ // Get the element at position

		return mat[row-1][column-1];

}

template <typename V,int NR,int NC>
	MatrixVectorSpace<V, NR, NC> MatrixVectorSpace<V,NR,NC>::operator + (const MatrixVectorSpace<V, NR, NC>& source)
{

		MatrixVectorSpace<V, NR, NC> result;

		for (int i = 0; i < NR; i++)
		{
			for (int j = 0; j < NC; j++)
			{
				result.mat[i][j] = (*this).mat[i][j] + source.mat[i][j];
			}
		}

		return result;
}



template <typename V,int NR,int NC>
	MatrixVectorSpace<V, NR, NC> MatrixVectorSpace<V,NR,NC>::operator - (const MatrixVectorSpace<V, NR, NC>& source)
	{

		MatrixVectorSpace<V, NR, NC> result;

		for (int i = 0; i < NR; i++)
		{
			for (int j = 0; j < NC; j++)
			{
				result.mat[i][j] = (*this).mat[i][j] - source.mat[i][j];
			}
		}

		return result;
}
/*
	template <int NC2>
template <typename V,int NR,int NC>
	MatrixVectorSpace<V, NR, NC2> MatrixVectorSpace<V,NR,NC>::operator * (const MatrixVectorSpace<V, NC, NC2>& source)
{

		MatrixVectorSpace<V, NR, NC2> result;

		for (int i = 0; i < NR; ++i)
		{
			for (int j = 0; j < NC2; ++j)
			{
				result.mat[i][j] = (*this).mat[i][0] + source.mat[0][j];
				for (int k = 1; k < NC; ++k)
				{
					result.mat[i][j] += (*this).mat[i][k] + source.mat[k][j];
				}
			}
		}

		return result;
}
*/
template <typename V,int NR,int NC>
	VectorSpace<V, NR> MatrixVectorSpace<V,NR,NC>::operator *(const VectorSpace<V,NC>& vector)
{ // Multiply matrix by vector

		VectorSpace<V, NR> result;

		for (int j = 1; j <= NR; j++)
		{
			result[j] = V(0.0);

			for (int k = 0; k < NC; k++)
			{
				result[j] += (*this).mat[j-1][k] * vector[k+1];
			}
		}

		return result;
}

// Other linear algebra routines
template <typename V,int NR,int NC>
	MatrixVectorSpace<V, NR, NC> MatrixVectorSpace<V,NR,NC>::Transpose() const
{ // Rows and Columns interchange

		const int NR2 = NC;
		const int NC2 = NR;

		MatrixVectorSpace<V, NR2, NC2> result;

		for (int j = 0; j < NR2; ++j)
		{
			for (int k = 0; k < NC2; ++k)
			{
				result.mat[j][k] = (*this).mat[k][j];
			}
		}

		return result;
}

template <typename V,int NR,int NC>
	MatrixVectorSpace<V, NR, NC>& MatrixVectorSpace<V,NR,NC>::operator = (const MatrixVectorSpace<V, NR, NC>& source)
{

		if (this == &source)
			return *this;

		for (int i = 0; i < NR; i++)
		{
			for (int j = 0; j < NC; j++)
			{
				mat[i][j] = source.mat[i][j];
			}
		}

		return *this;
}



#endif