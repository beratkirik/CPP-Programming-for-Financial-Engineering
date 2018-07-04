// CIRData.hpp
//
// Defining parameters of CIR zcb and corresponding
// pricing functions.
// 
// 2011-7-28 DD using Longstaff notation
// 2011-9-14 DD print vectors and matrices of values
//
// (C) Datasim Education BV 2009-2011
//

#ifndef CIR_HPP
#define CIR_HPP

#include <vector>
#include <cmath>
#include <iostream>
using namespace std;


namespace AffineModel
{
	// dr = (a - br)dt + sig r^1/2 dW
	double b;	// aka kappa;
	double a;	// aka alpha

	//double lambda; market price of risk
	double sig;

double priceCIR (double r, double t)
{ // CIR of a zero-coupon bond

	double gamma = sqrt(b*b + 2.0*sig*sig);

	double expm1 = exp(gamma*t) - 1.0;
	double gammapb = gamma + b;

	double B = (2.0 * expm1) / (gammapb*expm1 + 2.0*gamma);

	double factor = 2.0 * gamma * exp(0.5*gammapb*t) / (gammapb*expm1 + 2.0*gamma);

	double A = pow(factor, 2.0*a/(sig*sig));

	return A * exp(- B*r);
}


vector<double> priceCIR(const vector<double>& xarr, double t, double (*affineModel)(double x, double t) )
{ // This function uses a function pointer, so flexible

	vector<double> result(xarr.size());

	for (std::size_t n = 0; n < result.size(); ++n)
	{
		result[n] = affineModel(xarr[n], t);
	}

	return result;
}



	
vector<vector<double> > priceCIR(const vector<double>& xarr, const vector<double>& tarr, double (*affineModel)(double x, double t))
{

	//	vector<vector<double> > result(xarr.size(), tarr.size());
	
		std::vector<vector<double> > result(xarr.size());
		for (std::size_t j = 0; j < xarr.size(); ++j)
		{
			result[j] = std::vector<double>(tarr.size());
		}
		
		for (std::size_t n = 0; n < tarr.size(); ++n)
		{
			for (std::size_t i = 0; i < xarr.size(); ++i)
			{
				result[i][n] = affineModel(xarr[i], tarr[n]);
			
			}
		}

		return result;
} 


} // end of namespace 'AffineModel'



#endif