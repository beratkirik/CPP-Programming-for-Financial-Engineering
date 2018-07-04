// PerpetualAmerican.hpp
//
// Perpetual American option, Haug 2007 page 109-110.
//
// DJD
//

#include <cmath>
#include <iostream>
using namespace std;

// !! The variable b is cost of carry (b = r -q for a dividend-paying stock)

double PerpetualCall (double K, double S, double sig, double r, double b)
{ // Dividend q = r - b

	double sig2 = sig*sig;
	double fac = b/sig2 - 0.5; fac *= fac;
	double y1 = 0.5 - b/sig2 + sqrt(fac + 2.0*r/sig2);
	

	if (1.0 == y1)
		return S;

	double fac2 = ((y1 - 1.0)*S) / (y1 * K);
	double c = K * pow(fac2, y1) / (y1 - 1.0);

	return c;
}

double PerpetualPut (double K, double S, double sig, double r, double b)
{

	double sig2 = sig*sig;
	double fac = b/sig2 - 0.5; fac *= fac;
	double y2 = 0.5 - b/sig2 - sqrt(fac + 2.0*r/sig2);
	
	if (0.0 == y2)
		return S;

	double fac2 = ((y2 - 1.0)*S) / (y2 * K);
	double p = K * pow(fac2, y2) / (1.0 - y2);

	return p;
}


int main()
{
	double K, S, sig , r, b;

	cout << "K: "; cin >> K;
	cout << "S: "; cin >> S;
	cout << "sig: "; cin >> sig;
	cout << "r: "; cin >> r;
	cout << "b: "; cin >> b;

	cout << "\nPrice, put, " << ", S:  " << PerpetualPut (K, S, sig, r, b) << endl;
	cout << "Price, call, " << ", S: " << PerpetualCall (K, S, sig, r, b) << endl;
	/*
	// Examples fom Haug 2007
	K = 100.0; r = 0.1; b = 0.02;

	S = 90.0;
	cout << "\nPrice, put, " << ", S:  " << PerpetualPut (K, S, sig, r, b) << endl;
	cout << "Price, call, " << ", S: " << PerpetualCall (K, S, sig, r, b) << endl;

	S = 120.0;
	cout << "\nPrice, put, " << ", S:  " << PerpetualPut (K, S, sig, r, b) << endl;
	cout << "Price, call, " << ", S: " << PerpetualCall (K, S, sig, r, b) << endl;

	S = 130.0;
	cout << "\nPrice, put, " << ", S:  " << PerpetualPut (K, S, sig, r, b) << endl;
	cout << "Price, call, " << ", S: " << PerpetualCall (K, S, sig, r, b) << endl;
	*/
	return 0;
}
