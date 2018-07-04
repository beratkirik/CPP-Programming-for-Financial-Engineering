// TestBSPDE1.cpp
//
// Testing 1 factor BS model.
//
// (C) Datasim Education BV 2005-2011
//

#include "Group A/ArrayFuncs.hpp"
#include "Group A/EuropeanOption.hpp"
#include <iostream>

#include "FdmDirector.hpp"
#include <iostream>
#include <string>
#include <algorithm>
#include <math.h> 
using namespace std;

#include "UtilitiesDJD/ExcelDriver/ExcelMechanisms.hpp"

namespace BS // Black Scholes
{
    int type;     // 1 for Put, otherwise for Call
    double scale; // Factor for Call Price: Smax = scale*BS::K
    
	double sig = 0.3;
	double K = 65;
	double T = 0.25;
	double r = 0.08;
    double b = r;
	double D = 0.0; // aka q

	double mySigma (double x, double t)
	{

		double sigmaS = sig*sig;

		return 0.5 * sigmaS * x * x;
	}

	double myMu (double x, double t)
	{
		
		return (r - D) * x;
	
	}

	double myB (double x, double t)
	{
		return  -r;
	}

	double myF (double x, double t)
	{
		return 0.0;
	}

	double myBCL (double t)		
	{
        return type==1 ? K*exp(-r*t) : 0;  // Put:Call
	}

	double myBCR (double t)
	{
        return type==1 ? 0 : scale*K;  // Put:Call
	}

	double myIC (double x)
	{ // Payoff 
	
        return type==1 ? max(K-x, 0.0) : max(x-K, 0.0); // Put:Call
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

    BS::type = 0;   // 1 for Put; otherwise for Call
    BS::scale = 5;  // Smax = scale*BS::K

    int J = 5 * BS::K; int N = 100000-1; // k = O(h^2)!!!!!!!
    double Smax = BS::scale * BS::K;     // Magix, scale relates to call price calculation

	cout << "start FDM\n";
	FDMDirector fdir(Smax, BS::T, J, N);

	fdir.doit();
	
	cout << "Finished\n";
    
    
    //================================== Embed Exact Solution ==================================
    EuropeanOption option;
    option.SetOption((type_T)BS::T, (type_K)BS::K, (type_sig)BS::sig, (type_r)BS::r, (type_b)(BS::b), (type_S)0);
    
    
    // Create S_array and compute option price arrays
    type_S S_start    = (type_S) 0.0;
    type_S S_end      = (type_S) Smax;
    type_S S_interval = (type_S) ((S_end-S_start)/J);
    
    vector<type_S> S_array1      = MeshArray(S_start, S_end, S_interval);
    vector<double> S_CallPrices1 = option.CallPriceEuro(S_array1);
    vector<double> S_PutPrices1  = option.PutPriceEuro(S_array1);
    
    // For compatibility with the provided code, convert vector<> to Vector<>
    Vector<double, long> S_array2(J+1, 0), S_CallPrices2(J+1, 0), S_PutPrices2(J+1, 0);
    for (long j = S_array2.MinIndex(); j <= S_array2.MaxIndex(); ++j)
    {
        S_array2[j] = S_array1[j];
        S_CallPrices2[j] = S_CallPrices1[j];
        S_PutPrices2[j] = S_PutPrices1[j];
    }
    //==========================================================================================

    
    // Have you Excel installed (ExcelImports.cpp)
    //printOneExcel(fdir.xarr, fdir.current(), string("Value"));
    if (BS::type == 1)
     {
         printPairExcel(fdir.xarr, fdir.current(), S_PutPrices2, string("Option Price"), string("Asset Price (S)"), string("Put Price"));
     }
     else
     {
         printPairExcel(fdir.xarr, fdir.current(), S_CallPrices2, string("Option Price"), string("Asset Price (S)"), string("Call Price"));
     }
    
    return 0;
}
