// TestDataTypes.cpp
//
// Initial encounters with basic data types. Note that we use C++ iostream
// library for I/O operations.
//
// You get an idea of data types and their limits.
//
// DJD

#include <limits.h> // Least and greatest representation of integer types
#include <float.h>	// Least and greatest representation of floating point types
#include <iostream>
using namespace std;

int main()				
{

	// Create some variables and their values
	int i = 42;
	long index = 0L;
	
	double d1 = 2564.45677;
	double d2 = 3.1415*d1;

	cout << "Values: " << i << ", " << index << ", " << d2 << ", " << d2*i << endl; 

	// Some limits of basic data types
	cout << "int characteristics: " << sizeof(int) << ", " << INT_MIN << ", " << INT_MAX << endl;
	cout << "long characteristics: " << sizeof(long) << ", " << LONG_MIN << ", " << LONG_MAX << endl;

	cout << "double characteristics: " << sizeof(double) << ", " << DBL_MIN << ", " << DBL_MAX << endl;
	cout << "Long double characteristics: " << sizeof(double) << ", " << LDBL_MIN << ", " << LDBL_MAX << endl;
	cout << "float characteristics: " << sizeof(float) << ", " << FLT_MIN << ", " << FLT_MAX << endl;

	// What happens here? Put a big number in too small a space..
	float f = FLT_MAX;
	cout << f;


	return 0;
}
