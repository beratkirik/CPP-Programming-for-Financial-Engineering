//
//  TestLoops.cpp
//
//  Created by Changheng Chen on 11/3/16.
//  Copyright © 2016 Changheng Chen. All rights reserved.
//
//  Comparing the different ways to loop and make decisions in code.
//  We take the example of solving a scalar nonlinear equation x = f(x) by
//  the fixed point method (contraction mapping):
//           x(n+1) = f(x(n)), x(0) given.
//  We iterate until either fabs(x(n+1) - x(n)) < TOL or n >= MAXITER.
//  The fixed point method converges if fabs(df/dx) < 1.
//  Variants are Brouwer and Banach fixed point theorems.
//
//  In this version we examine x = exp(-x). Later you can generalize the code
//  by defining f(x) using function pointers.
//

#include <math.h>
#include <iostream>
using namespace std;


// The function
double f(double x)
{
    return exp(-x);
}


// Method I: Solution using goto
double ftp_I(double x_0, double tol, long maxiter)
{
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
    
    cout << "Method I has converged in " << counter << " iteratons\n";
 
    return xcurrent;
}

// Method II: Solution using a hard-code for loop and a break
double ftp_II(double x_0, double tol, long maxiter)
{
    double xcurrent;
    long counter;
    
    for (counter = 0; counter <= maxiter; ++counter)
    {
        xcurrent = f(x_0);
        
        if (fabs(xcurrent - x_0) < tol)
        { // Convergence has occurred, so we are finished
            break; // stop execution of loop
        }
            
        x_0 = xcurrent;
    }
    
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

// Method III: Solution using a while 'forever' for loop and a break
double ftp_III(double x_0, double tol, long maxiter)
{
    double xcurrent;
    long counter = 0;
    
    while (true)
    {
        xcurrent = f(x_0);
        
        if (counter >= maxiter)
        {
            cout << "Method III has NOT converged in " << counter << " iterations\n";
            break;
        }
        
        if (fabs(xcurrent - x_0) < tol)
        { // Convergence has occurred
            cout << "Method III has converged in " << counter << " iterations\n";
            break;  // stop execution of loop
        }
        
        counter++;
        x_0 = xcurrent;
    }
    
    return xcurrent;
}


// Main function to test the Methods
int main()
{
    // Input parameters
    double xInit = 0.5;
    long maxIter = 10000;
    double tol = 1.0e-5;
    
    // The implementation of the solvers
    cout << "Fixed point (method I) is: " << ftp_I(xInit, tol, maxIter) << endl;
    cout << "Fixed point (method II) is: " << ftp_II(xInit, tol, maxIter) << endl;
    cout << "Fixed point (method III) is: " << ftp_III(xInit, tol, maxIter) << endl;
    
    // Testing scope of a variable
    {
        int j = 10; cout << "j: " << j << endl;
    }
    
    // j does not exist anymore, because out of the former scope now.
    // cout << "j: " << j << endl;
    return 0;
}
