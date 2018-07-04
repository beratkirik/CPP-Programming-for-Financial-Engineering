// TestMatrixVectorSpace.cpp
//
// Simple tests of compile-time matrices
//
// (C) Datasim Education BV 2006-2007
//

#include "UtilitiesDJD/CompileTimeVectorsAndmatrices/VectorSpaceMechanisms.cpp"
#include "UtilitiesDJD/CompileTimeVectorsAndmatrices/MatrixVectorSpace.cpp"

//#include "clock.hpp" // For timing
#include <iostream>
using namespace std;


int main()
{

//	DatasimClock timer;
//	timer.start();
	const int NR = 4;
	const int NC = 4;
	const int dim = 2;

	//int N;
	//cout << "How many iterations: "; cin >> N;

	MatrixVectorSpace<double, dim, dim> myMat0(2.0);
	MatrixVectorSpace<double, dim, dim> myMat2(1.0);
	
	
	MatrixVectorSpace<double, dim, dim> myMat3 = myMat0 + myMat2;
	MatrixVectorSpace<double, dim, dim> myMat4 = myMat0 - myMat2;
	MatrixVectorSpace<double, dim, dim> myMat4A = myMat0 * myMat2;

	print(myMat3);
	print(myMat4);
	print(myMat4A);

	cout << "Add and subtract matrices, continue: "; int t; cin >> t;

	// From Vector Mechanisms
	MatrixVectorSpace<double, dim, dim> myMat5 = 
				multiply<double, dim, dim, dim>(myMat3, myMat4);
	print(myMat5);
	cout << "Multiply matrices, continue: "; cin >> t;

	VectorSpace<double, dim> myArray;
	myArray[1] = 0.5;
	myArray[2] = 1.0;

	VectorSpace<double, dim> myMultArray = myMat5 * myArray;
	print (myMultArray);
	cout << "Multiply matrix and vector, continue: "; cin >> t;

	for (long j = myMat0.MinColumnIndex(); j <= myMat0.MaxColumnIndex(); j++)
	{
		for (long i = myMat0.MinRowIndex(); i <= myMat0.MaxRowIndex(); i++)
		{
				myMat0(i,j) = 1.0 / double (i+j-1);
		}
	}

	print(myMat0);
	cout << "Hilbert matrix, continue: "; cin >> t;


//	timer.stop();
//	timer.print();
	
	return 0;
}