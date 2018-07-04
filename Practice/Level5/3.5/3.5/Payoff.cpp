//
//  Payoff.cpp
//  3.5
//
//  Base clas for Payoffs.
//
//  Created by Changheng Chen on 12/30/16.
//  Copyright © 2016 Changheng Chen. All rights reserved.
//

#include "Payoff.hpp"

// Constructors and destructors
Payoff::Payoff()
{ // Default constructor
}

Payoff::Payoff(const Payoff& source)
{ // Copy constructor
}

Payoff::~Payoff()
{ // Destructor
}

// Operator overloading
Payoff& Payoff::operator = (const Payoff& source)
{ // Assignment operator
    
    if (this == &source)
        return *this;
    
    return *this;
}
