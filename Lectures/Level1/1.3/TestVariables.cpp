// TestVariables.cpp
//
// Using variables, operators and expressions. We focus on double precision:
//
//	1. Declaring and initialising variables
//	2. Using operators
//	3. Postfix/prefix operators
//	4. Expressions and precedence
//
// DJD
//


#include <iostream>
using namespace std;

int main()
{
	double d1 = 3.1415; double d2 = -2.0; double d3 = 2.71;
	double d4; 

//	cout << d4 << endl; // Will give a run-time error

	d4 = d1 + d2/d3; cout << d4 << endl;
	d4 = (d1 + d2)/d3; cout << d4 << endl;

	// Combined assignment operators
	d4 += d1; // d4 = d4 + d1
	d3 *= d2;

	// Prefix/postfix
	int i = 3;
	int j = ++i; cout << j << ", " << i << endl; // 4,4

	i = 3;
	int k = i++; cout << k << ", " << i << endl; // 3,4

	// Comma operator
	int y = 5;
	int c;

	c = y +=4, y + 5; 

	cout << "Value of c: " << c << endl; // 9


	y = 5; // Reset
	int c2 = (y +=4, y + 5); 
	cout << "Value of c2: " << c2 << endl; // 14

	// Replacing , by ;
	y = 5; // Reset
	int d = y += 4; y + 5;

	cout << "Value of d: " << d << endl; // ??

	return 0;
}
