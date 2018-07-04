// Option.hpp
//
//
// (C) Datasim Component Technology BV 2003-2005
//

#ifndef Option_hpp
#define Option_hpp

#include <algorithm>
using namespace std;

class Option
{
public:

	double r;		// Interest rate
	double sig;		// Volatility
	double K;		// Strike price
	double T;		// Expiry date
//	double U;		// Current underlying price (e.g. stock, forward)
//	double b;		// Cost of carry
	int type;		// 1 == Call, 2 == Put

	double payoff(double S)const
	{
		if (type == 1)
		{
			return max(S - K, 0.0);
		}
		else
		{
			return max(K - S, 0.0);
		}
	}
};

#endif