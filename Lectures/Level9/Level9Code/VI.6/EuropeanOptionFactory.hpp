// EuropeanOptionFactory.hpp
//
// Classes for creating Eurpean Options. This is
// a Factory Method pattern.
//
// (C) Datasim Education BV 2005

#ifndef EuropeanOptionFactory_hpp
#define EuropeanOptionFactory_hpp

#include "option.hpp"

class EuropeanOptionFactory
{
public:
		virtual Option* create() const = 0;
};

class ConsoleEuropeanOptionFactory: public EuropeanOptionFactory
{
public:
	
		Option* create() const
		{
			cout << "\n*** Parameters for option object ***\n";

			Option* opt = new Option;

			cout << "Strike: ";
			cin >> opt->K;

			cout << "Volatility: ";
			cin >> opt->sig;

			cout << "Interest rate: ";
			cin >> opt->r;

			cout << "Expiry date: ";
			cin >> opt->T;

			cout << "1. Call, 2. Put: ";
			cin >> opt->type;

			return opt;
		}
};

#endif



