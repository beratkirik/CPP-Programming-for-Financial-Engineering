//
//  CIR.h
//  CIR
//
//  Defining parameters of CIR zcb and corresponding
//  pricing functions.
//
//  Created by Changheng Chen on 2/12/17.
//  Copyright © 2017 Changheng Chen. All rights reserved.
//

#ifndef CIR_hpp
#define CIR_hpp

#include <vector>
#include <cmath>
using namespace std;

namespace AffineModel
{
    // dr = (a - br)dt + sig r^1/2 dW
    double b;   // aka kappa
    double a;   // aka alpha
    
    // double lambda; market price of risk
    double sig;
    
    
    double priceCIR(double r, double t)
    { // CIR of a zero-coupon bond
        
        double gamma = sqrt(b*b + 2.0*sig*sig);
        
        double expm1 = exp(gamma*t) - 1.0;
        double gammapb = gamma + b;
        
        double B = (2.0 * expm1)/ (gammapb*expm1 + 2.0*gamma);
        
        double factor = 2.0 * gamma * exp(0.5*gammapb*t) / (gammapb*expm1 + 2.0*gamma);
        
        double A = pow(factor, 2.0*a/(sig*sig));
        
        return A * exp(-B*r);
    }
    
    vector<double> priceCIR(const vector<double>& xarr, double t, double (*affineModel)(double x, double t))
    { // This function uses a function pointer, so flexible
        
        vector<double> result(xarr.size());
        
        for (long n = 0; n < result.size(); ++n)
        {
            result[n] = affineModel(xarr[n], t);
        }
            
        return result;
    }
    
    
    vector< vector<double> > priceCIR(const vector<double>& xarr, const vector<double>& tarr, double (*affineModel)(double x, double t))
    {
        // vector< vector<double> > result(xarr.size(), tarr.size());
        
        vector< vector<double> > result(xarr.size());
        for (std::size_t j = 0; j < xarr.size(); ++j)
        {
            result[j] = vector<double>(tarr.size());
        }
        
        
        for (std::size_t n = 0; n < tarr.size(); ++n)
        {
            for (std::size_t i = 0; i < xarr.size(); ++i)
            {
                result[i][n] = affineModel(xarr[i], tarr[i]);
            }
        }
        
        return result;
    }

} // end of namespace 'AffineMoel'


#endif /* CIR_hpp */
