	// TestPayoff.cpp
//
// Testing the one-factor payoff classes
//
// (C) Datasim Education BV 1998 - 2005
//

#include "CallPayoff.hpp"


int main()
{
	
	Payoff* myPayoff = new CallPayoff(10);

	cout << myPayoff->payoff(20) << endl;

	delete myPayoff;

	myPayoff = new CallPayoff(20);
	cout << myPayoff->payoff(20) << endl;

	delete myPayoff;

	return 0;
}
