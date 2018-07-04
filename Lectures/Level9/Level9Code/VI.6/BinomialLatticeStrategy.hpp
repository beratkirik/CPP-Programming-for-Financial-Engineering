// BinomialLatticeStrategy.hpp
//
// Strategy pattern for creating binomial lattice. Note
// that there is a built-in Template Method pattern built
// in here.
// 
// For convenience all data is public and all code is inline.
// Furthermore, classes have minimal functionality. We can make 
// production code from this at a later stage.
//
// (C) Datasim Education BV 2005-2006
//

#ifndef BinomialLatticeStrategy_hpp
#define BinomialLatticeStrategy_hpp

#include "lattice.cpp"
#include <math.h>

enum BinomialType {Additive, Multiplicative};

class BinomialLatticeStrategy
{ // Based on Clewlow and Strickland 1998
protected:
		double u;
		double d;
		double p;

		double s;
		double r;
		double k;
	
		BinomialType bType;

		BinomialLatticeStrategy(double vol, double interest, double delta);

public:
		// Useful function
		virtual void updateLattice
			(Lattice<double, int, 2>& source, double rootValue) const;

		// Public inline functions for normal clients
		double downValue() const { return d;}
		double upValue() const { return u;}
		double probValue() const { return p;}
		BinomialType binomialType() const { return bType;}

};

  

class CRRStrategy: public BinomialLatticeStrategy
{
public:
	CRRStrategy(double vol, double interest, double delta);

};

class PadeCRRStrategy: public BinomialLatticeStrategy
{
public:
	PadeCRRStrategy(double vol, double interest, double delta);

};

class JRStrategy: public BinomialLatticeStrategy
{
public:
	JRStrategy(double vol, double interest, double delta);
	
};

class PadeJRStrategy: public BinomialLatticeStrategy
{
public:
	PadeJRStrategy(double vol, double interest, double delta);
	
};
class EQPStrategy: public BinomialLatticeStrategy
{
public:
	EQPStrategy(double vol, double interest, double delta);
	
};


class TRGStrategy: public BinomialLatticeStrategy
{
public:
	TRGStrategy(double vol, double interest, double delta);
};


class ModCRRStrategy: public BinomialLatticeStrategy
{
public:
	ModCRRStrategy(double vol, double interest, double delta, double S, double K, int N);

};


#endif
