// TestEuropeanOption.cpp
//
// Test program for the exact solutions of European options. 
// Check answers with Haug 2007 book on option pricing.
//
// (C) Datasim Component Technology BV 2003-20011
//

#include "EuropeanOption.hpp"
#include <iostream>

/* Cost of carry factor b must be included in formulae depending on the
   derivative type. These are used in the generalised Black-Scholes formula. 
   If r is the risk-free interest and q is the continuous dividend yield then 
   the cost-of-carry b per derivative type is:

	a) Black-Scholes (1973) stock option model: b = r
	b) b = r - q Merton (1973) stock option model with continuous dividend yield
	c) b = 0 Black (1976) futures option model
	d) b = r - rf Garman and Kohlhagen (1983) currency option model, where rf is the 
	   'foreign' interest rate
*/


int main()
{ // All options are European


	// Call option on a stock (b = r by default)
	EuropeanOption callOption;
	cout << "S: "; double S; cin >> S;
	cout << "Option on a stock: " << callOption.Price(S) << endl;

	// Option on a stock index
/*	EuropeanOption indexOption;
	indexOption.optType = "C";
	indexOption.K = 50.0;
	indexOption.T = 0.41667;
	indexOption.r = 0.1;
	indexOption.sig = 0.00;

	double q = 0.0;		// Dividend yield
	indexOption.b = indexOption.r - q;

	cout << indexOption.optType << " option on an index: " << indexOption.Price(50.0) << endl;

	// Options on a future
	EuropeanOption futureOption;
	futureOption.optType = "P";
	futureOption.K = 19.0;
	futureOption.T = 0.75;
	futureOption.r = 0.10;
	futureOption.sig = 0.28;

	futureOption.b = 0.0;

	cout << "Put option on a future: " << futureOption.Price(20.0) << endl;

	// Now change over to a call on the option
	futureOption.toggle();
	cout << "Call option on a future: " << futureOption.Price(20.0) << endl;


	// Call option on currency
	EuropeanOption currencyOption;
	currencyOption.optType = "C";
	currencyOption.K = 1.60;
	currencyOption.T = 0.5;
	currencyOption.r = 0.06;
	currencyOption.sig = 0.12;

	double rf = 0.08;		// risk-free rate of foreign currency
	currencyOption.b = currencyOption.r - rf;

	cout << endl << "** Other pricing examples **" << endl << endl;

	cout << "Call option on a currency: " << currencyOption.Price(1.56) << endl;

	////////   NOW CALCULATIONS OF SENSITIVITIES //////////////////////////////////

	// Call and put options on a future: Delta and Elasticity
	EuropeanOption futureOption2;
	futureOption2.optType = "P";
	futureOption2.K = 100.0;
	futureOption2.T = 0.5;
	futureOption2.r = 0.10;
	futureOption2.sig = 0.36;

	futureOption2.b = 0.0;

	cout << "Delta on a put future: " << futureOption2.Delta(105.0) << endl;

	// Now change over to a call on the option
	futureOption2.toggle();
	cout << "Delta on a call future: " << futureOption2.Delta(105.0) << endl;

	
	// Some more data for testing; Calcuate price and delta a
	EuropeanOption stockOption;
	stockOption.optType = "C";
	stockOption.K = 60.0;
	stockOption.T = 0.75;
	stockOption.r = 0.10;
	stockOption.sig = 0.30;

	stockOption.b = stockOption.r;


	stockOption.toggle();

	// Calculating theta of a European stock index
	EuropeanOption indexOption2;
	indexOption2.optType = "P";
	indexOption2.K = 405.0;
	indexOption2.T = 0.0833;	// One month expiration
	indexOption2.r = 0.07;
	indexOption2.sig = 0.20;

	double divYield = 0.05;		// Dividend yield, 5% per annum
	indexOption2.b = indexOption2.r - divYield;


	// Stock Option: Rho
	EuropeanOption stockOption2;
	stockOption2.optType = "C";
	stockOption2.K = 75.0;
	stockOption2.T = 1.0;
	stockOption2.r = 0.09;
	stockOption2.sig = 0.19;

	stockOption2.b = stockOption2.r;


	// Calculating Cost of Carry of a European stock index
	EuropeanOption indexOption3;
	indexOption3.optType = "P";
	indexOption3.K = 490.0;
	indexOption3.T = 0.222225;
	indexOption3.r = 0.08;
	indexOption3.sig = 0.15;

	double divYield3 = 0.05;		// Dividend yield, 5% per annum
	indexOption3.b = indexOption3.r - divYield3 ;

	*/
	return 0;
}
