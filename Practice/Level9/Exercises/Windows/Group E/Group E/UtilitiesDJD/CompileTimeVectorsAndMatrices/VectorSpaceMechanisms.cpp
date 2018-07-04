// VectorSpaceMechanisms.cpp
//
// 
// 2007-1-12 DD main functionality
// 2007-1-19 DD hpp and cpp
// 2007-6-1 DD Testing and beta code review
// 2007-6-8 DD new void functions for converting bwteem 
// 2007-10-15 DD TripleSum (saxpy)
//
// (C) Datasim Education BV 2007-2008
//

#ifndef VectorSpaceMechanisms_CPP
#define VectorSpaceMechanisms_CPP

#include "UtilitiesDJD/CompileTimeVectorsAndMatrices/VectorSpaceMechanisms.hpp"
#include "UtilitiesDJD/VectorsAndMatrices/MatrixMechanisms.cpp"

template <typename V, int N> 
		void print(const VectorSpace<V,N>& vec)
{

	cout << "\n(";
	for (int j = vec.MinIndex(); j <= vec.MaxIndex(); j++)
	{
	 	cout << vec[j] << ",";
	}

	cout << ")\n";
}

template <typename V, int N>
void print(const list<VectorSpace<V,N> >& l)
{ // Print the list

	cout << endl << "Size of list is: " << l.size() << endl;

	// Create list iterator
	list<VectorSpace<V,N> >::const_iterator i;
	
	cout << endl;

	// Print every character in the list
	for (i = l.begin(); i != l.end(); ++i)
	{
			print(*i);
	}

	cout << endl;
}


template <typename V, int NR, int NC> void print(const MatrixVectorSpace<V,NR, NC>& matrix)
{

	// Convert to a numeric matrix
	NumericMatrix<V, long> result = convertToDynamicMatrix(matrix);
	print(result);

}

template <typename V, int NR, int NC> void print2(const MatrixVectorSpace<V,NR, NC>& matrix)
{

	for (long j = matrix.MinColumnIndex(); j <= matrix.MaxColumnIndex(); j++)
	{
		cout << "\n(";
		for (long i = matrix.MinRowIndex(); i <= matrix.MaxRowIndex(); i++)
		{
			cout << matrix(i,j) << ",";
		}
		cout << ")\n";
	}
	cout << "]\n";
	
}

template <typename V, int N>
	Vector<V, long> convertToDynamicVector(const VectorSpace<V, N>& myArray)
{

	Vector<V,long> result (N, 1);

	for (long i = result.MinIndex(); i <= result.MaxIndex(); ++i)
	{
		result[i] = myArray[i];
	}

	return result;

}

template <typename V, int N>
	void convertToDynamicVectorII (VectorSpace<V, N>& input, Vector<V, long>& output)
{
	for (long i = output.MinIndex(); i <= output.MaxIndex(); ++i)
	{
		output[i] = myArray[i];
	}

}


template <typename V, int N>
	VectorSpace<V, N> convertToFixedVector(const Vector<V, long>& myArray)
{

	VectorSpace<V,N> result;

	for (int i = result.MinIndex(); i <= result.MaxIndex(); i++)
	{
		result[i] = myArray[i];
	}

	return result;

}

template <typename V, int N>
	void convertToFixedVectorII(Vector<V, long>& input, VectorSpace<V, N>& output)
{
	for (int i = output.MinIndex(); i <= output.MaxIndex(); ++i)
	{
		output[i] = input[i];
	}
}


template <typename V>
	Vector<V, long> Average(const list<Vector<V, long>* >& group)
{ // Indexed-elents average of a bunch of vectors


	// Build map by iterating from start of vector to end
	// Init part
	list<Vector<V, long>* >::const_iterator i = group.begin();
	long startIndex = (**i).MinIndex();
	long size = (**i).Size();
	double dsize = 1.0 / group.size();

	// Create the output vector
	Vector<V,long> result (size, startIndex);

	for (long j = result.MinIndex(); j <= result.MaxIndex(); j++)
	{
		result[j] = 0.0;
		
		for (i = group.begin(); i != group.end(); i++)
		{ // Scan the vectors at the current index j

		

			result[j] = result[j] + (**i)[j];
		}

		result[j] *= dsize;

	}
	
	return result;
	

}



// Matrices
template <typename V, int NR, int NC>
	MatrixVectorSpace<V, NR, NC> convertToFixedMatrix(const NumericMatrix<V, long>& matrix)
{

	MatrixVectorSpace<V,NR, NC> result;


	for (long j = result.MinColumnIndex(); j <= result.MaxColumnIndex(); j++)
	{
		for (long i = result.MinRowIndex(); i <= result.MaxRowIndex(); i++)
		{
				result(i,j) = matrix(i,j);
		}
	}

	return result;

}

// 
template <typename V, int NR, int NC>
	NumericMatrix<V, long> convertToDynamicMatrix(const MatrixVectorSpace<V, NR, NC>& matrix)
{
	long NR1 = long(NR);
	long NC1 = long(NC);

	NumericMatrix<V, long> result(NR1, NC1, 1,1);

	for (long j = result.MinColumnIndex(); j <= result.MaxColumnIndex(); j++)
	{
		for (long i = result.MinRowIndex(); i <= result.MaxRowIndex(); i++)
		{
				result(i,j) = matrix(i,j);
		}
	}

	return result;

}

template <typename V,int NR,int NC, int NR2>
	MatrixVectorSpace<V, NR, NR2> multiply (const MatrixVectorSpace<V, NC, NR2>& A, 
													const MatrixVectorSpace<V, NC, NR2>& B)
	{

		MatrixVectorSpace<V, NR, NR2> result;

		double tmp = V(0.0);

		// This uses the functions in MatricVectorSpace
		for (int i = result.MinRowIndex(); i <= result.MaxRowIndex(); i++)
		{
			for (int j = result.MinColumnIndex(); j <= B.MaxColumnIndex(); j++)
			{
				tmp = V(0.0);
				for (int k = A.MinRowIndex(); k <= A.MaxRowIndex(); k++)
				{
					tmp += A(i, k) * B(k,j);
					
				}

				result(i, j) = tmp;
			}
		}

		return result;
	}

// D = A + bB + cC; A,B,C are vectors, b,c scalars
template <typename V, int N>
	void TripleSum(VectorSpace<V,N>& D, 
		const VectorSpace<V,N>& A, const VectorSpace<V,N>& B, const VectorSpace<V,N>& C,
		V b, V c)
{

		// Precondition: all vectors have same size

	for (int j = D.MinIndex(); j <= D.MaxIndex(); ++j)
	{
		D[j] = A[j] + (b*B[j]) + (c*C[j]);
	}

}
#endif