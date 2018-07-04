// Hello.cpp
//
// Simple example of function bodies.
//


// Preprocessor for include files
#include <stdio.h>			// C style I/O
#include <iostream>			// C++ style I/O using operator overloading
using namespace std;		// The C++ logical collection of functions

void hello_C()
{
	printf("Hello Quantnet, C style\n");
}

void hello_CPP()
{
	// Using (binary) operator overloading
	cout << "Hello Quantnet, C++ style \n";
}
