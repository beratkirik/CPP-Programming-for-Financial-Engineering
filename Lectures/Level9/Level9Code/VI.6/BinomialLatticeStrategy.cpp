// BinomialLatticeStrategy.cpp
//
// Strategy pattern for creating binomial lattice. Note
// that there is a built-in Template Method pattern built
// in here.
// 
// For convenience all data is public and all code is inline.
// Furthermore, classes have minimal functionality. We can make 
// production code from this at a later stage.
//
// Last Modification Dates:
//
//	2006-4-7 DD cpp file now
//
// (C) Datasim Education BV 2005-2006
//

#ifndef BinomialLatticeStrategy_cpp
#define BinomialLatticeStrategy_cpp

#include "BinomialLatticeStrategy.hpp"

#include <cmath>
#include <iostream>
using namespace std;

BinomialLatticeStrategy::BinomialLatticeStrategy(double vol, double interest, double delta)
{
			s = vol;
			r = interest;
			k = delta;
			bType = Multiplicative;
}


		// Useful function
void BinomialLatticeStrategy::updateLattice
			(Lattice<double, int, 2>& source, double rootValue) const
{	// Find the depth of the lattice; this a Template Method Pattern

			int si = source.MinIndex();
			source[si][source[si].MinIndex()] = rootValue;

			// Loop from the min index to the end index
			for (int n = source.MinIndex() + 1; n <= source.MaxIndex(); n++)
			{
				for (int i = source[n].MinIndex(); i < source[n].MaxIndex(); i++)
				{
					source[n][i] = d * source[n-1][i];
					source[n][i+1] = u * source[n-1][i];
				}

			}

}
  

CRRStrategy::CRRStrategy(double vol, double interest, double delta) 
		: BinomialLatticeStrategy(vol, interest, delta)
{
		/* double e = ::exp((r)*k);
		double sr = ::sqrt(exp(vol*vol*k) - 1.0);
		u = e * (1.0 + sr);
		d = e * (1.0 - sr);*/

		double R1 = (r - 0.5 * s * s) * k;
		double R2 = s * ::sqrt(k);

		u = ::exp(R1 + R2);
		d = ::exp(R1 - R2);

		cout << "UD " << u << ", " << d;


		double discounting = ::exp(- r*k);
	
		p = 0.5;
}

PadeCRRStrategy::PadeCRRStrategy(double vol, double interest, double delta) 
		: BinomialLatticeStrategy(vol, interest, delta)
{
		/* double e = ::exp((r)*k);
		double sr = ::sqrt(exp(vol*vol*k) - 1.0);
		u = e * (1.0 + sr);
		d = e * (1.0 - sr);*/

		double R1 = (r - 0.5 * s * s) * k;
		double R2 = s * ::sqrt(k);

	//	u = ::exp(R1 + R2);
	//	d = ::exp(R1 - R2);

		// Cayley transform
		double z1 = (R1 + R2);
		double z2 = (R1 - R2);

		u = (2.0 + z1) / (2.0 - z1);
		d = (2.0 + z2) / (2.0 - z2);
	

		cout << "UD " << u << ", " << d;


		double discounting = ::exp(- r*k);
	
		p = 0.5;
}



JRStrategy::JRStrategy(double vol, double interest, double delta) 
		: BinomialLatticeStrategy(vol, interest, delta)
{
		double k2 = ::sqrt(k);
		u = ::exp(s * k2);

		d = 1.0/u;

		p = 0.5 + ((r - 0.5 * s * s) * k2 * 0.5) / s;

}

PadeJRStrategy::PadeJRStrategy(double vol, double interest, double delta) 
		: BinomialLatticeStrategy(vol, interest, delta)
{

		double k2 = ::sqrt(k);

		// Cayley transform
		double z = s * ::sqrt(k);

		/* u = ::exp(s * k2);
		d = 1.0/u; */

	//	u = (2.0 + z) / (2.0 - z);

	//	d = (2.0 - z) / (2.0 +z);

		double num = 12.0 - (6.0*z) + (z*z);
		double denom = 12.0 + (6.0*z) + (z*z);

		d = num/denom;
		u = denom/num;
		
		p = 0.5 + ((r - 0.5 * s * s) * k2 * 0.5) / s;

}

EQPStrategy::EQPStrategy(double vol, double interest, double delta) 
		: BinomialLatticeStrategy(vol, interest, delta)
{

	bType = Additive;

	// Needed for additive method: page 19 Clewlow/Strickland formula 2.17 
	// "v" is "nu" here, for "v" see  page 19 formula 2.14
	double nu = r - 0.5 * s * s;

	double a = nu * k;
	double b = 0.5 * ::sqrt( (4.0 * s * s * k) - (3.0 * nu * nu * k * k) );

	// EQP parameters: page 19 formula 2.17
	u = 0.5 * a + b;														
	d = 1.5 * a - b;

	p = 0.5;
	

}



TRGStrategy::TRGStrategy(double vol, double interest, double delta) 
		: BinomialLatticeStrategy(vol, interest, delta)
{
	
	bType = Additive;

	// Needed for additive method: page 19 formula 2.19 
	// "v" is "nu" here, for "v" see  page 17 formula 2.14
	double nu = r - 0.5 * s * s;

	double nudt = nu * k;

	// TRG parameters: page 19 formula 2.19
	u = ::sqrt( s * s * k + nudt * nudt );
	d = - u;

	p = 0.5 * (1.0 + (nudt/u) );

}


ModCRRStrategy::ModCRRStrategy(double vol, double interest, double delta, double S, double K, int N) 
		: BinomialLatticeStrategy(vol, interest, delta)
{
		
		// s == volatility, k = step size in time
		double KN = ::log(K/S) / double (N);
		double VN = s * ::sqrt(k);

		u = ::exp(KN + VN);
		d = ::exp(KN - VN);

		p = (::exp(r * k) - d) / (u - d);

}

#endif
