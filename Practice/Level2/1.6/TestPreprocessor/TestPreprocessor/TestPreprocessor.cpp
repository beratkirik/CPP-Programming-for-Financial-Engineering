//
//  TestPreprocessor.cpp
//
//  Created by Changheng Chen on 11/12/16.
//  Copyright © 2016 Changheng Chen. All rights reserved.
//
// Comparing the different ways to loop and make decisions in code. We
// take the example of solving a scalar nonlinear equation x = f(x) by fixed point
// method (contraction mapping):
//
//       x(n+1) = f(x(n)), x(0) given.
//
// We iterate until either fabs(x(n+1) - x(n)) < TOL or n >= MAXITER. The fixed point method
// converges if fabs(df/dx) < 1. Variants are Brouwer and Banach fixed point theorems.
//
// In this version we examine x = exp(-x). Later you can generalise the code by defining f(x) using
// function pointers.
//
// In this case we use the preprocessor to define the variables TOL and MAXITER for illustrative purposes.
// In general we would not advise this approach.
//

#include <math.h>
#include <iostream>
using namespace std;

// Preprocessor directives; effectively global variables
#define TOL 1.0e-5
#define MAXITER 10000

double f(double x)
{
    return exp(-x);
}

double ftp_I(double x_0)
{ // Solution using goto
    double xcurrent;
    long counter = 0;
    
L1:
    xcurrent = f(x_0);
    
    if (counter >= MAXITER)
    {
        cout << "Max iterations exceeded, method not converging\n";
        return xcurrent;
    }
    
    if (fabs(xcurrent - x_0) >= TOL)
    {
        x_0 = xcurrent;
        counter++;
        goto L1;
    }
    
    cout << "Method I has converged in " << counter << " iterations\n";
    
    return xcurrent;
}

int main()
{
    // Input parameters
    double xInit = 0.5;
    
    // long maxIter = 10000;
    // double tol = 1.0e-5;
    
    // The implementations of the solvers
    cout << "Fixed point (method I) is: " << ftp_I(xInit) << endl;
    
    return 0;
}
