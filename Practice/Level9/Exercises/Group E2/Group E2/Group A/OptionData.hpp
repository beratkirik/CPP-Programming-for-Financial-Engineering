//
//  OptionData.hpp
//  Group A
//
//  Create a struct to encapsulate option variables.
//
//  Created by Changheng Chen on 2/20/17.
//  Copyright © 2017 Changheng Chen. All rights reserved.
//

#ifndef OptionData_hpp
#define OptionData_hpp

#include "DefineTypes.hpp"

struct OptionData
{
    type_T T;      // Expiry date
    type_K K;      // Strike price
    type_sig sig;  // Volatility
    type_r r;      // Interest rate
    type_b b;      // Carry of cost
    type_S S;      // Underlying price
};

#endif /* OptionData_hpp */
