// TestVectorSpace.cpp
//
// Simple testing of VectorSpace class
//
// (C) Datasim Education BV 2005-2009
//

#include "UtilitiesDJD/CompileTimeVectorsAndMatrices/VectorSpace.cpp"
#include "UtilitiesDJD/CompileTimeVectorsAndMatrices/VectorSpaceMechanisms.cpp"
#include <iostream>
using namespace std;


int main()
{
	const int N = 3;
	VectorSpace<double, N> myArray;

	// All elements in vector have the same value, 2.2
	double value = 2.2;
	VectorSpace<double, N> myArrayB(2.2);

	for (int j = myArray.MinIndex(); j <= myArray.MaxIndex(); j++)
	{

		myArray[j] =  double (j);

	}

	print(myArray);
	print(myArrayB);

	// This code will not compile, no conversions between
	// the two different classes
	/*const int N1 = 3;
	const int N2 = 4;
	VectorSpace<double, N1> ArrOne;
	VectorSpace<double, N2> ArrTwo;
	ArrOne = ArrTwo;
	ArrTwo = ArrOne;*/
	

	VectorSpace<double, N> myArray1 = - myArray; 
	VectorSpace<double, N> myArray2 = myArray; // No other size works!!
	VectorSpace<double, N> myArray3 = myArray2 - myArray; 

	print(myArray1);
	print(myArray2);
	print(myArray3);

	// Calling a template member function (operator)
	double factor = 0.5;
	VectorSpace<double, N> myArray4 = factor * myArray;
	print(myArray4);
	double ip = myArray.innerProduct(myArray2);
	cout << "Inner product: " << ip << endl;

	VectorSpace<double, N> myArray5(myArray);
	print(myArray5);

	// Addition 
	double offset = 1.0;
	myArray5 = myArray + offset; // try +
	print(myArray5);

	myArray5 = myArray - myArray; // try -
	print(myArray5);

	double cp = myArray.componentProduct();
	cout << "Product: " << cp << endl;
	const int N2 = 3; 

	VectorSpace<double, N2> myArray2A;
	for (int j = myArray2A.MinIndex(); j <= myArray2A.MaxIndex(); j++) 
	{ 
		myArray2A[j] = double (j); 
	} 


	// Calling a template member function (operator) 
	double factor2 = 0.5; 
	VectorSpace<double, N2> myArray4A = factor2 * myArray2A; 

	return 0;
}
