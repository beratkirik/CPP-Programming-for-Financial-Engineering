//
//  OptionPricing.cpp
//  Group B
//
//  Created by Changheng Chen on 2/26/17.
//  Copyright © 2017 Changheng Chen. All rights reserved.
//

#include "OptionPricing.hpp"
#include <cmath>

// Call and put option price for perpetual American option

double CallPrice(type_K K, type_S S, type_sig sig, type_r r, type_b b)
{
    // Just stick with the exact equations, do not worry about y1 == 1.0
    
    double y1 = 0.5 - b/(sig*sig) + sqrt((b/(sig*sig) - 0.5)*(b/(sig*sig) - 0.5) + 2*r/(sig*sig));
    
    return K/(y1-1.0) * pow( ((y1-1.0)/y1 * S/K), y1 );
}

double PutPrice(type_K K, type_S S, type_sig sig, type_r r, type_b b)
{
    // Just stick with the exact equations, do not worry about y2 == 1.0
    
    double y2 = 0.5 - b/(sig*sig) - sqrt((b/(sig*sig) - 0.5)*(b/(sig*sig) - 0.5) + 2*r/(sig*sig));
    
    return K/(1.0-y2) * pow( ((y2-1.0)/y2 * S/K), y2 );
}
