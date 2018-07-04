// CallPayoff.cpp
//
// CallPayoff class.
//
// 5 june 1998	MB	Started
// 2005-5-16 DD Modified from Shape hierarchy
//
// (C) Datasim Education BV 1998 - 2005

#include "CallPayoff.hpp"


// Constructors and destructor
CallPayoff::CallPayoff(): Payoff()
{ // Default constructor

	K = 100.0; // Prototype value
}

CallPayoff::CallPayoff(double strike): Payoff()
{ // Normal constructor with coordinates
 
	K = strike;
}


CallPayoff::CallPayoff(const CallPayoff& source): Payoff(source)
{ // Copy constructor

	K = source.K;
}

CallPayoff:: ~CallPayoff()
{ // Destructor

} 

// Selectors
double CallPayoff::Strike() const
{// Return K

	return K;
}


// Modifiers
void CallPayoff::Strike(double NewStrike)
{// Set K

	K = NewStrike;
}

CallPayoff& CallPayoff::operator = (const CallPayoff &source)
{ // Assignment operator

	// Exit if same object
	if (this==&source) return *this;

	// Call base class assignment
	Payoff::operator = (source);

	// Copy state
	K = source.K;  

	return *this;
}

// Implment the pure virtual payoff function from base class
double CallPayoff::payoff(double S) const
{ // For a given spot price

	if (S > K)
		return (S - K);
		
	return 0.0;
	
	// remark; possible to say max (S - K, 0); I am a bit longwinded!
}

