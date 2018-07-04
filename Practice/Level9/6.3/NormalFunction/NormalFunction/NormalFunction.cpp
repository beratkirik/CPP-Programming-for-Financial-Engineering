//
//  NormalFunction.cpp
//  NormalFunction
//
//  Some exact formulae.
//
//  Created by Changheng Chen on 2/12/17.
//  Copyright © 2017 Changheng Chen. All rights reserved.
//

#include <cmath>
#include <iostream>
using namespace std;
#include <boost/math/distributions/normal.hpp>
#include <boost/math/distributions.hpp> // For non-member functions of distributions
using namespace boost::math;


double N(double x)
{
    normal_distribution<> myNormal(0.0, 1.0);
    
    return cdf(myNormal, x);
}

double n(double x)
{
    normal_distribution<> myNormal(0.0, 1.0);
    
    return pdf(myNormal, x);
}

int main()
{
    double x = 1.0;
    cout << "pdf: " << n(x) << ", cdf: " << N(x) << endl;
    
    return 0;
}
