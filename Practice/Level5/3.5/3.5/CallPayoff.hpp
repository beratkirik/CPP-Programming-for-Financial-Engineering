//
//  CallPayoff.hpp
//  3.5
//
//  Class for payoff for call options (1 factor)
//
//  Created by Changheng Chen on 12/30/16.
//  Copyright © 2016 Changheng Chen. All rights reserved.
//

#ifndef CallPayoff_hpp
#define CallPayoff_hpp

#include "Payoff.hpp"

class CallPayoff: public Payoff
{
private:
    double K;  // Strike price
    
public:
    
    // Constructors and destructor
    CallPayoff();                                      // Default constructor
    CallPayoff(double strike);
    CallPayoff(const CallPayoff& source);              // Copy constructor
    virtual ~CallPayoff();                             // Destructor
    
    // Selectors
    double Strike() const;                             // Return strike price

    // Modifiers
    void Strike(double NewStrike);                     // Set strike price

    CallPayoff& operator = (const CallPayoff& source); // Assignment operator
    
    // Implement the pure virtual payoff function from base class
    double payoff(double S) const;                     // For a given spot price
};

#endif /* CallPayoff_hpp */
