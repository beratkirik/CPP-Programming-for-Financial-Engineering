// TestHello.cpp
//
// Showing how to call a function from another file in the main function.
//
// DJD

#include "Hello.hpp"	// User-defined include file

int main()				// Return type of main() expects an int
{
	hello_C();			/* In C */

	hello_CPP();		// In C++

	return 0;
}
