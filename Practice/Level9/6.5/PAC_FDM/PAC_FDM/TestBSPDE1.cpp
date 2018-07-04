//
//  TestBSPDE1.cpp
//  PAC_FDM
//
//  Testing 1 factor BS model.
//
//  Created by Changheng Chen on 2/14/17.
//  Copyright © 2017 Changheng Chen. All rights reserved.
//

#include "FdmDirector.hpp"
#include "ExcelDriver.hpp"

#include <iostream>
#include <string>
using namespace std;

namespace BS // Black Sholes
{
    double sig = 0.3;
    double K = 65.0;
    double T = 0.25;
    double r = 0.08;
    double D = 0.0; // aka q

    double mySigma(double x, double t)
    {
        double sigmaS = sig*sig;
        
        return 0.5 * sigmaS * x * x;
    }
    
    double myMu(double x, double t)
    {
        return (r-D) * x;
    }
    
    double myB(double x, double t)
    {
        return -r;
    }
    
    double myF(double x, double t)
    {
        return 0.0;
    }
    
    double myBCL(double t)
    { // Put
        return K * exp(-r * t);
    }
    
    double myBCR(double t)
    { // Put
        return 0.0; // P
    }
    
    double myIC(double x)
    { // Payoff
        return max(K - x, 0.0);
    }
}

int main()
{
    using namespace ParabolicIBVP;
    
    // Assignment of functions
    sigma = BS::mySigma;
    mu = BS::myMu;
    b = BS::myB;
    f = BS::myF;
    BCL = BS::myBCL;
    BCR = BS::myBCR;
    IC = BS::myIC;
    
    int J = 5*BS::K; int N = 10000-1;  // k = O(h^2) !!!!!!
    
    double Smax = 5*BS::K;             // Magix
    
    cout << "Start FDM\n";
    
    FDMDirector fdir(Smax, BS::T, J, N);
    
    fdir.doit();
    
    cout << "Finished\n";
    
    // Have you got Excel?
    printOneExcel(fdir.xarr, fdir.current(), string("Value"));
    
    return 0;
}
