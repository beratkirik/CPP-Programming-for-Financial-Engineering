// TestLoops.cpp
//
// Comparing the different ways to loop and make decisions in code. We 
// take the example of solving a scalar nonlinear equation x = f(x) by the fixed point
// method (contraction mapping):
//
//		x(n+1) = f(x(n)), x(0) given.
//
//	We iterate until either fabs(x(n+1) - x(n)) < TOL or n >= MAXITER. The fixed point method
//  converges if fabs(df/dx) < 1. Variants are Brouwer and Banach fixed point theorems.
//
// In this version we examine x = exp(-x). Later you can generalise the code by defining f(x) using 
// function pointers. 
//
// DJD
//

#include <math.h>
#include <iostream>
using namespace std;

double f(double x)
{
	return exp(-x);
}

double ftp_I(double x_0, double tol, long maxiter)
{ // Solution using goto

	double xcurrent;
	long counter = 0;

L1:
	xcurrent = f(x_0);

	if (counter >= maxiter)
	{
		cout << "Max iterations exceeded, method not converging\n";
		return xcurrent;
	}

	if (fabs(xcurrent - x_0) >= tol)
	{
		x_0 = xcurrent;
		counter++;
		goto L1;
	}
	
	cout << "Method I has converged in " << counter << " iterations\n";

	return xcurrent;
}

double ftp_II(double x_0, double tol, long maxiter)
{ // Solution using a hard-code for loop and a break

	double xcurrent;
	long counter;

	for (counter = 0; counter < maxiter; ++counter)
	{

		xcurrent = f(x_0);

		if (fabs(xcurrent - x_0) < tol)
		{ // Convergence has occurred, so we are finished

			break; // stop execution of loop
		}
	
		x_0 = xcurrent;
	}

	// Broke out!

	if (counter < maxiter)
	{
		cout << "Method II has converged in " << counter << " iterations\n";
	}
	else
	{
		cout << "Method II has NOT converged in " << counter << " iterations\n";
	}

	return xcurrent;
}

double ftp_III(double x_0, double tol, long maxiter)
{ // Solution using a while 'forever' for loop and a break

	double xcurrent;
	long counter = 0;
	
	while (true)
	{

		xcurrent = f(x_0); counter++;

		if (counter >= maxiter)
		{
			cout << "Method III has NOT converged in " << counter << " iterations\n";
			break;
		}

		if (fabs(xcurrent - x_0) < tol)
		{ // Convergence has occurred

			cout << "Method III has converged in " << counter << " iterations\n";
			break; // stop execution of loop
		}
	
		x_0 = xcurrent;
	}

	return xcurrent;
}




int main()
{
	// Input parameters
	double xInit = 0.5;
	long maxIter = 10000;
	double tol = 1.0e-5; // 0.000001

	// The implementations of the solvers
	cout << "Fixed point (method I) is: " << ftp_I(xInit, tol, maxIter) << endl;
	cout << "Fixed point (method II) is: " << ftp_II(xInit, tol, maxIter) << endl;
	cout << "Fixed point (method III) is: " << ftp_III(xInit, tol, maxIter) << endl;


	// Testing scope of a variable
	{
		int j = 10; 
		cout << "j: " << j << endl;
	}

	// j does not exist anymore
	cout << "j: " << j << endl;

	return 0;
}

	