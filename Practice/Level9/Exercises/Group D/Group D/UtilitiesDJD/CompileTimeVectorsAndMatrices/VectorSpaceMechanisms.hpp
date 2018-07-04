// VectorSpaceMechanisms.hpp
//
// 
// Useful BLAS-type functions for compile-time vector
// spaces
//
// (C) Datasim Education BV 2007
//

#ifndef VectorSpaceMechanisms_HPP
#define VectorSpaceMechanisms_HPP

#include "UtilitiesDJD/CompileTimeVectorsAndMatrices/VectorSpace.cpp"
#include "UtilitiesDJD/CompileTimeVectorsAndMatrices/MatrixVectorSpace.hpp"
#include "UtilitiesDJD/VectorsAndMatrices/Vector.cpp"
#include "UtilitiesDJD/VectorsAndMatrices/NumericMatrix.cpp"
#include <iostream>
#include <list>
using namespace std;

template <typename V, int N> 
		void print(const VectorSpace<V,N>& vec);

template <typename V, int N>
void print(const list<VectorSpace<V,N> >& l);

template <typename V, int NR, int NC> void print(const MatrixVectorSpace<V,NR, NC>& matrix);

template <typename V, int NR, int NC> void print2(const MatrixVectorSpace<V,NR, NC>& matrix);


template <typename V, int N>
	Vector<V, long> convertToDynamicVector(const VectorSpace<V, N>& myArray);

template <typename V, int N>
	void convertToDynamicVectorII (VectorSpace<V, N>& input, Vector<V, long>& myArray);

template <typename V, int N>
	VectorSpace<V, N> convertToFixedVector(const Vector<V, long>& myArray);
template <typename V, int N>
	void convertToFixedVectorII(Vector<V, long>& input, VectorSpace<V, N>& output);


template <typename V>
	Vector<V, long> Average(const list<Vector<V, long>* >& group);


// Matrices
template <typename V, int NR, int NC>
	MatrixVectorSpace<V, NR, NC> convertToFixedMatrix(const NumericMatrix<V, long>& matrix);

template <typename V, int NR, int NC>
	NumericMatrix<V, long> convertToDynamicMatrix(const MatrixVectorSpace<V, NR, NC>& matrix);

template <typename V,int NR,int NC, int NR2>
		MatrixVectorSpace<V, NR, NR2> multiply (const MatrixVectorSpace<V, NC, NR2>& A, const MatrixVectorSpace<V, NC, NR2>& B);
	

// Saxpy stuff

// D = A + bB + cC; A,B,C are vectors, b,c scalars
template <typename V, int N>
	void TripleSum(VectorSpace<V,N>& D, 
		const VectorSpace<V,N>& A, const VectorSpace<V,N>& B, const VectorSpace<V,N>& C,
		V a, V b);

#endif