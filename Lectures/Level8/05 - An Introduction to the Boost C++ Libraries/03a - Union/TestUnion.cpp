// TestUnion.cpp
//
// Simple case to show how C union works. Later we 
// discuss Boost varian which is a type-safe version of
// union.
//
// (C) Datasim Education BV 2010-2011
//

#include <iostream>
#include <string>
using namespace std;

union NumericDataType
{ // union with three members

    int         i;
	float       f;  
    double      d;  
};

int main()
{
    NumericDataType Values;
	
	Values.i = 10; 
	cout << "Integer: " << Values.i << endl; // Prints 10

    Values.f =1.098f;
	cout << "Float: " << Values.f << endl; // Prints 1.098

    Values.d = 3.1415;
	cout << "Correct double: " << Values.d << endl;

	// The variables i and f will not have correct values
	// because the 'd' field is active.
	cout << "Incorrect float: " << Values.f << endl;
	cout << "Incorrect integer: " << Values.i << endl;

	NumericDataType Values2 = { 2 };
	NumericDataType Values3 = { 2.71 };

	return 0;
}

