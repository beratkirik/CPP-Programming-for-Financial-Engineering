// Payoff.cpp
//
// Base class for Payoffs.
//
// 5 june 1998	MB	Started
// 2005-5-16 DD Modified from Shape hierarchy
//
// (C) Datasim Education BV 1998 - 2005

#include "Payoff.hpp"

// Constructors and destructor
Payoff::Payoff()
{ // Default constructor
}

Payoff::Payoff(const Payoff& source)
{ // Copy constructor
}

Payoff:: ~Payoff()
{ // Destructor
}

// Operator overloading
Payoff& Payoff::operator = (const Payoff& source)
{ // Assignment operator

	if (this == &source)
		return *this;

	return *this;
}
