// director.cpp
//
// Main program to run and test the Binomial method
// for a stock option. This code 'drives' the process
// as it were.
//
// 2005-1-31 DD First official code 
//
// The mediator class in the Binomial method
// 
// 
// (C) Datasim Education BV 2005-2011
//

#include "option.hpp"
#include "binomialmethod.hpp"
#include "BinomialLatticeStrategy.hpp"
#include "EuropeanOptionFactory.hpp"
#include "latticemechanisms.cpp"
#include <cmath>

#include <iostream>
using namespace std;

EuropeanOptionFactory* getFactory()
{
	return new ConsoleEuropeanOptionFactory;
}

BinomialLatticeStrategy* getStrategy(double sig, double r, double k, 
										double S, double K, int N)
{
	cout << "\n1. CRR, 2. JR, 3. TRG, 4. EQP, 5. Modified CRR:\n6. Cayley JR Transform: 7 Cayley CRR: ";
	int choice;
	cin >> choice;

	if (choice == 1)
		return new CRRStrategy(sig,r,k);

	if (choice == 2)
		return new JRStrategy(sig,r,k);

	if (choice == 3)
		return new TRGStrategy(sig,r,k);

	if (choice == 4)
		return new EQPStrategy(sig,r,k);

	if (choice == 5)
		return new ModCRRStrategy(sig,r,k, S, K, N);

	if (choice == 6)
		return new PadeJRStrategy(sig,r,k);

	if (choice == 7)
		return new PadeCRRStrategy(sig,r,k);

}


// This could be made into a member function of Option
Vector<double, int> calcPayoffVector(Vector<double, int> xarr, const Option& opt)
{
	// We need the form of the lattice at the 'base' of the pyramid. This
	// will be needed when we use backward induction 
	
	Vector<double, int> result (xarr);

	// Now use functionMechanisms 
	/* Vector<double, int> 
			createDiscreteFunction(double (*f)(double x), const Vector<double, int>& xarr);	*/

	for (int j = xarr.MinIndex(); j <= xarr.MaxIndex(); j++)
	{
			result[j] = opt.payoff(xarr[j]);
	}

	return result;
}

int main()
{
	// Phase I: Create and initialise the option
	EuropeanOptionFactory* fac = getFactory();

	int N = 200;
	cout << "Numbers of steps: ";
	cin >> N;

	double S = 200;
	cout << "Give underlying value: ";
	cin >> S;

	Option* opt = fac -> create();
	delete fac;

	double k = opt->T / double (N);
	cout << "Step size " << k << endl;

	// Create basic lattice
	double discounting = ::exp(- opt->r*k);
	cout << "Discounting " << discounting << endl;

	// Phase II: Create the binomial metjod
	BinomialLatticeStrategy* lf = getStrategy(opt->sig, opt->r, k, S, opt->K, N);
	BinomialMethod bn(discounting, *lf, N);

	// Phase III: Forward Induction
	bn.modifyLattice(S);
//	print(bn.getLattice());

	
	// Phase IV: Backward Induction
	Vector<double, int> RHS = bn.BasePyramidVector();
	if (lf -> binomialType() == Additive)
	{
		RHS[RHS.MinIndex()] = S * ::exp(N * lf -> downValue());
		for (int j = RHS.MinIndex() + 1; j <= RHS.MaxIndex(); j++)
		{
			RHS[j] = RHS[j-1] * exp(lf->upValue() - lf->downValue());
		}
	}

	Vector<double, int> Pay = calcPayoffVector(RHS, *opt);

	double pr = bn.getPrice(Pay);
	cout << "PriceN: " << pr << endl;

	fac = getFactory();

	delete lf; delete opt;

	return 0;
}
