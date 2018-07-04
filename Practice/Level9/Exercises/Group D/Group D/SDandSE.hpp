//
//  SDandSE.hpp
//  Group D
//
//  Created by Changheng Chen on 2/27/17.
//  Copyright © 2017 Changheng Chen. All rights reserved.
//

#ifndef SDandSE_hpp
#define SDandSE_hpp

#include <cmath>
#include <vector>

double optionSD(const vector<double>& prices, double r, double T)
{
    double CTj = 0.0;
    double CTjsq = 0.0;
    long NSim = prices.size();
    
    for (long i = 0; i < NSim; i++)
    {
        CTj += prices[i];
        CTjsq += prices[i] * prices[i];
    }
    
    return sqrt((CTjsq - (CTj*CTj)/NSim) / (NSim-1)) * exp(-r * T);
}

double optionSE(const vector<double>& prices, double r, double T)
{
    return optionSD(prices, r, T)/sqrt(prices.size());
}

#endif /* SDandSE_hpp */
