// OptionData.hpp
//
// Encapsulate option data.
//
// (C) Datasim Education BV 2008

#ifndef OptionData_HPP
#define OptionData_HPP

#include <iostream>
using namespace std;

// Encapsulate all data in one place
struct OptionData
{ // Option data + behaviour

	double K;
	double T;
	double r;
	double sig;

	// Extra data 
	double D;		// dividend
	double beta;	// elasticity factor (CEV model)
	
	int type;		// 1 == call, -1 == put

	// Not C, strictly speaking. This is a destructor that gats called automatically
	// when an object's memory is freed.
	~OptionData() // destructor
	{
		cout << "Bye Option Data..\n";
	}
};

void print (OptionData data)
{
	cout << "Option data ..." << endl;
	cout << "Strike: " << data.K << endl;
	cout << "Expiry: " << data.T << endl;
	cout << "Interest: " << data.r << endl;
	cout << "Volatility: " << data.sig << endl;
	cout << "Dividend: " << data.D << endl;
	cout << "Elasticity factor (beta): " << data.beta << endl;
	cout << "Call +1 or Put -1: " << data.type << endl;
	cout << endl;
}


#endif