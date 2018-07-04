// NormalFunction.cpp
//
// Some exact formulae.
//
// (C) Datasim Education BV 2011
//

#include <cmath>
#include <iostream>
using namespace std;
#include <boost/math/distributions/normal.hpp>
#include <boost/math/distributions.hpp> // For non-member functions of distributions
using namespace boost::math;

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

	double x = 2.0;
	cout << "pdf: " << n(x) << ", cdf: " << N(x) << endl;
	
	return 0;
}
