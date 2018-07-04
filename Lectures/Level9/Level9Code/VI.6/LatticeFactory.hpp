// LatticeFactory.hpp
//
// Abstract Factory for creating binomial lattice. Note
// that there is a built-in Template Method pattern built
// in here.
//
// (C) Datasim Education BV 2005
//

#ifndef LatticeFactory_hpp
#define LatticeFactory_hpp

//#include "lattice.cpp"
#include <math.h>

class LatticeFactory
{
public:
		double u;
		double d;
		double p;

		double s;
		double r;
		double k;
	
		enum Type {Additive, Multiplicative};
		Type bType;

		LatticeFactory(double vol, double interest, double delta)
		{
			s = vol;
			r = interest;
			k = delta;
			bType = Multiplicative;
		}


		// Useful function
		virtual void updateLattice
			(Lattice<double, int, 2>& source, double rootValue) const
		{	// Find the depth of the lattice; this a Template Method Pattern

			int si = source.MinIndex();
			source[si][source[si].MinIndex()] = rootValue;

			// Loop from the min index to the end index
			for (int j = source.MinIndex() + 1; j <= source.MaxIndex(); j++)
			{
				for (int i = source[j].MinIndex(); i < source[j].MaxIndex(); i++)
				{
					source[j][i] = d * source[j-1][i];
					source[j][i+1] = u * source[j-1][i];
				}

			}

		}
};

  

class CRRFactory: public LatticeFactory
{
public:
	CRRFactory(double vol, double interest, double delta) 
		: LatticeFactory(vol, interest, delta)
	{
		double e = ::exp((r)*k);
		double sr = ::sqrt(exp(vol*vol*k) - 1.0);


		u = e * (1.0 + sr);
		d = e * (1.0 - sr);

		double discounting = ::exp(- r*k);
	
		p = 0.5;
	}

};

class JRFactory: public LatticeFactory
{
public:
	JRFactory(double s, double r, double k) 
		: LatticeFactory(s, r, k)
	{
		double k2 = ::sqrt(k);
		u = ::exp(s * k2);

		d = 1.0/u;

		p = 0.5 + ((r - 0.5 * s * s) * k2 * 0.5) / s;

	}
};

class EQPFactory: public LatticeFactory
{
public:
	EQPFactory(double s, double r, double k) 
		: LatticeFactory(s, r, k)
	{

	bType = Additive;

	// Needed for additive method: page 19 Clewlow/Strickland formula 2.17 
	// "v" is "nu" here, for "v" see  page 17 formula 2.14
	double nu = r - 0.5 * s * s;

	double a = nu * k;
	double b = 0.5 * ::sqrt( (4.0 * s * s * k) - (3.0 * nu * nu * k * k) );

	// EQP parameters: page 19 formula 2.17
	u = 0.5 * a + b;														
	d = 1.5 * a - b;

	p = 0.5;
	
	// pd = 0.5 = (1-p)

	}


};


class TRGFactory: public LatticeFactory
{
public:
	TRGFactory(double s, double r, double k) 
		: LatticeFactory(s, r, k)
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


};


class ModCRRFactory: public LatticeFactory
{
public:
	ModCRRFactory(double s, double r, double k, double S, double K, int N) 
		: LatticeFactory(s, r, k)
	{
		
		double KN = ::log(K/S) / double (N);
		double VN = s * sqrt(k);

		u = ::exp(KN + VN);
		d = ::exp(KN - VN);

		p = (::exp(r * k) - d) / (u - d);
	}

};


#endif
