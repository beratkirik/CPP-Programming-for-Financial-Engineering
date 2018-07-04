// MatrixVectorSpace.hpp
//
// Numeric Matrix class.
// This is a COMPILE-TIME Matrix class for numerical data. 
//
// (C) Datasim Component Technology 1999-2007

#ifndef MatrixVectorSpace_hpp
#define MatrixVectorSpace_hpp

#include "UtilitiesDJD/CompileTimeVectorsAndMatrices/VectorSpace.cpp"


template <typename V,int NR,int NC>
			class MatrixVectorSpace 
{
//private:
public:

		V mat[NR][NC];
public:
	// Constructors & destructor
	MatrixVectorSpace();
	MatrixVectorSpace(const V& value);
	MatrixVectorSpace(const MatrixVectorSpace<V, NR, NC>& source);

	virtual ~MatrixVectorSpace();


	// Selectors
	inline int MinRowIndex() const;
	inline int MaxRowIndex() const;
	inline int MinColumnIndex() const;
	inline int MaxColumnIndex() const;
	inline int Rows() const;
	inline int Columns() const;
		
	// Operators; indexing starts at 1
	inline const V& operator () (int row, int column) const;
	inline V& operator () (int row, int column);
	
	MatrixVectorSpace<V, NR, NC> operator + (const MatrixVectorSpace<V, NR, NC>& source);
	MatrixVectorSpace<V, NR, NC> operator - (const MatrixVectorSpace<V, NR, NC>& source);

	// Template member function
	template <int NC2>
		MatrixVectorSpace<V, NR, NC2> operator * (const MatrixVectorSpace<V, NC, NC2>& source)
	{
		MatrixVectorSpace<V, NR, NC2> result;

		for (int i = 0; i < NR; ++i)
		{
			for (int j = 0; j < NC2; ++j)
			{
				result.mat[i][j] = V(0.0);
				for (int k = 0; k < NC; ++k)
				{
					result.mat[i][j] += (*this).mat[i][k] * source.mat[k][j];
				}
			}
		}

		return result;
	}

	VectorSpace<V, NR> operator *(const VectorSpace<V,NC>& vector);
 
	MatrixVectorSpace<V, NR, NC>& operator = (const MatrixVectorSpace<V, NR, NC>& source);

	// Other linear algebra routines
	MatrixVectorSpace<V, NR, NC> Transpose() const;	// Rows and Columns interchange

};



#endif