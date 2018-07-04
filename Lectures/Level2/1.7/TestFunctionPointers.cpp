// TestFunctionPointers.cpp
//
// Sample code to show the use of function pointer syntax to promote
// reusability and flexibility.
//
// DJD

#include <math.h>
#include <iostream>
using namespace std;

double LeonardoPisa(double x)
{ // x = F(x), this is a contraction

	// Solves x^3 + 2x^2 + 10x = 20 by rewriting in the form x = f(x)

	return 20.0 / (x*x + 2.0*x + 10);
}

double SquareRoot(double x)
{ // Square root of 2

	return 0.5 * (x + 2.0/x);
}


double FPSolver(double (*f) (double x), double x0, double TOL)
{ // General 1 solver for a contraction mapping f in form x = f(x)

	double xnp1;
	double diff = 10.0 * TOL;

	while (diff >= TOL)
	{ // You should have a break if algorithm does not converge

		xnp1 = (*f)(x0);
		diff = fabs(xnp1 - x0);
		x0 = xnp1;
	}

	return x0;
}

int main()
{

	cout << "Cosine fixed point solver: " <<  FPSolver(cos, 0.12, 1.0e-2) << endl;	// 'cos' is system delivered function
	
	// Square roots
	double tol = 1.0e-10; double x0 = 100.0;
	cout << "Square root: " <<  cout.precision(16) << FPSolver(SquareRoot, x0, tol) << endl;	
	
	tol = 1.0e-3;
	x0 = 31.2;
	cout << "Root of cubic equation: " <<  cout.precision(4) << FPSolver(LeonardoPisa, x0, tol) << endl;	
	
	// Extra level of indirection
	double (*myFunc)(double x);
	myFunc = SquareRoot;
	cout << "Square root, again: " <<  cout.precision(16) << FPSolver(myFunc, x0, tol) << endl;	

	myFunc = ::sin; // C library function
	cout << "Sine fixed point solver: " <<  FPSolver(myFunc, 0.12, 1.0e-2) << endl;	

	return 0;
}
