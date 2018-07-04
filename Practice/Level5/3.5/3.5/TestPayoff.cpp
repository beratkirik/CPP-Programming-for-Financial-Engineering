//
//  TestPayoff.cpp
//  3.5
//
//  Created by Changheng Chen on 12/30/16.
//  Copyright © 2016 Changheng Chen. All rights reserved.
//

#include <iostream>

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
