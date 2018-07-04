//
//  OptionData.hpp
//  Group B
//
//  Encapsulate option parameters into a struct
//
//  Created by Changheng Chen on 2/26/17.
//  Copyright © 2017 Changheng Chen. All rights reserved.
//

#ifndef OptionData_hpp
#define OptionData_hpp

#include "DefineTypes.hpp"

struct OptionData
{
    type_K K;      // Stike price
    type_S S;      // Asset price
    type_sig sig;  // Volatility
    type_r r;      // Interest rate
    type_b b;      // Carry of cost
};

#endif /* OptionData_hpp */
