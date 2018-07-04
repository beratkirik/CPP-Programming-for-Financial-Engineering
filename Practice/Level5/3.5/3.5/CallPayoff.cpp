//
//  CallPayoff.cpp
//  3.5
//
//  CallPayoff class.
//
//  Created by Changheng Chen on 12/30/16.
//  Copyright © 2016 Changheng Chen. All rights reserved.
//

#include "CallPayoff.hpp"

//================== Constructors and destructor =================
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

CallPayoff::~CallPayoff()
{ // Destructor
}

//=================================================================
// Selectors
double CallPayoff::Strike() const
{
    return K;
}

// Modifiers
void CallPayoff::Strike(double NewStrike)
{
    K = NewStrike;
}

CallPayoff& CallPayoff::operator = (const CallPayoff& source)
{ // Assignment operator
    
    // Exit if same object
    if (this == &source) return *this;
    
    // Call base class assignment
    Payoff::operator = (source);
    
    // Copy state
    K = source.K;
    
    return *this;
}

//=================================================================
// Implement the pure vitual payoff function from base class
double CallPayoff::payoff(double S) const
{ // For a given spot price
    
    if (S > K)
        return (S - K);
    
    return 0.0;
    
    // remark: possible to say max(S-K,0); I am a bit longwinded!
}
