// TestMatrixMultiplication.cpp
//
// Testing matrix multiplication
//
// (C) Datasim Education BV 2006-2012

#include "UtilitiesDJD/VectorsAndMatrices/NumericMatrix.cpp"
#include "UtilitiesDJD/VectorsAndMatrices/MatrixMechanisms.cpp"
#include <complex> // Use STL built-in complex numbers class

int main()
{

	NumericMatrix<double, long> m1(2,3);
	NumericMatrix<double, long> m2(3,2);

	NumericMatrix<double, long> m3 = m1 * m2;
	print(m3);

	NumericMatrix<std::complex<double>, long> m1C(2,3);
	NumericMatrix<std::complex<double>, long> m2C(3,2);

	NumericMatrix<std::complex<double>, long> m3C = m1C * m2C;

	print(m3C);

	return 0;
}