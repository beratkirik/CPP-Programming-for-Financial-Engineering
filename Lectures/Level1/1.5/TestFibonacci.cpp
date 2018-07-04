// TestFibonacci.cpp
// 
// Showing the use of recursive functions by implementing 
// Fibonacci sequences.
//
// DJD
//


#include <algorithm>
#include <iostream>
using namespace std;

long Fibonacci(long n)
{ // Recursive function

        if(n == 0)
		{
			return 0;
		}

		if(n == 1)
		{
			return 1;
		}

		return Fibonacci(n-1) + Fibonacci(n-2);
}


int main()
{ // 0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, 233, 377, 610, 987, 1597, 2584, 4181, 6765 . . .


    int N = 40; // How many Fibonacci numbers to compute

	for (int n = 0; n < N; ++n)
	{ 
		cout << Fibonacci(n) << ",";
	}

    return 0;

	// N = 30000??
}
