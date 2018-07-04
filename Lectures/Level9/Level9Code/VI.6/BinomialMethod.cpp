// BinomialMethod.cpp
//
// An encapsulation of the Binomial Method. This is
// a kind of Mediator between the underlying data
// stucture (a lattice tree) and the different kinds
// of algorithms for initialising the tree.
//
// We have kept code inline for convenience only.
//
// Last Modification dates:
//
//	DD 2005-2-19 New cpp file
//	DD 2005-11-3 Debugging
//	DD 2006-4-7 New for get lattice
//
// (C) Datasim Education BV 2004-2006
//

#ifndef BinomialMethod_CPP
#define BinomialMethod_CPP

#include "BinomialMethod.hpp"


BinomialMethod::BinomialMethod (double discounting, BinomialLatticeStrategy& strategy, int N) 
{
	
		disc = discounting;
		str = &strategy;
		buildLattice(N);

}

void BinomialMethod::buildLattice(int N)
{
	
		lattice = Lattice<double, int, 2> (N, 0.0);
}

void BinomialMethod::modifyLattice(double U)
{

		double down = str -> downValue();
		double up = str -> upValue();

		int si = lattice.MinIndex();
		lattice[si][lattice[si].MinIndex()] = U;

			// Loop from the min index to the end index
			for (int n = lattice.MinIndex() + 1; n <= lattice.MaxIndex(); n++)
			{
				for (int i = lattice[n].MinIndex(); i < lattice[n].MaxIndex(); i++)
				{
					lattice[n][i] = down * lattice[n-1][i];
					lattice[n][i+1] = up * lattice[n-1][i];
				}
			}
	
		// Postcondition: we now have the complete lattice for the underlying asset
}

	

double BinomialMethod::getPrice(const Vector<double, int>& RHS)
{
			
		double pr = str -> probValue();
		//cout << "Prob value: " << pr << endl;

		int ei = lattice.MaxIndex();
		lattice[ei] = RHS;

		// Loop from the max index to the start (min) index
		for (int n = lattice.MaxIndex() - 1; n >= lattice.MinIndex(); n--)
		{

		/*	for (int i = lattice[n].MinIndex(); i <= lattice[n].MaxIndex(); i++)
			{
			
					if (lattice[n][i] > H) // H == barrier
					{
						lattice[n][i] = disc * (pr * lattice[n+1][i+1] + (1.0-pr) * lattice[n+1][i]);

						// For call
						lattice[n][i] = max(lattice[n][i] - K, 0.0);
					}
					else
					{
						lattice[n][i] = 0.0;
					}

			}*/

			for (int i = lattice[n].MinIndex(); i <= lattice[n].MaxIndex(); i++)
			{
			
					lattice[n][i] = disc * (pr * lattice[n+1][i+1] + (1.0-pr) * lattice[n+1][i]);
		
			}

			
				
		}

		int si = lattice.MinIndex();
		return lattice[si][lattice[si].MinIndex()];

}

Vector<double, int> BinomialMethod::BasePyramidVector() const
{
		return lattice.BasePyramidVector();
}

// Underlying lattice
const Lattice<double, int, 2>& BinomialMethod::getLattice() const
{

	return lattice;
}


#endif


