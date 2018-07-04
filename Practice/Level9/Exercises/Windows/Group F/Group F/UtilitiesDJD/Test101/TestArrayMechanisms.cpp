// TestArrayMechanisms.cpp
//
// Examples to show how sequence containers (vector) work.
//
// (C) Datasim Education BV 2003-2011
//

#include <string>
#include <iostream>
#include "UtilitiesDJD/VectorsAndMatrices/ArrayMechanisms.cpp" // Conversion stuff here
using namespace std;
int main()
{


	// The first 'sanity check' example
	size_t n = 10;
	double val = 1.0;
	Vector<double, int> myVector(10, 1, val);	// Create n copies of val

	print(myVector);

	n = 10;
	Vector<double, int> myVector2(4);	// Length 4, start index == 1
	myVector2[1] = 1.0; 
	myVector2[2] = -10.0; 
	myVector2[3] = 9.0; 
	myVector2[4] = 2.0; 

	myVector[3] = 433.0;

	print(myVector2);

	return 0;
}
