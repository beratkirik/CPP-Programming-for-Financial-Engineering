//
//  OptionPricing.hpp
//  Group B
//
//  Global functions for option pricing of perpetual American options
//
//  Created by Changheng Chen on 2/26/17.
//  Copyright © 2017 Changheng Chen. All rights reserved.
//

#ifndef OptionPricing_hpp
#define OptionPricing_hpp

#include "OptionData.hpp"

double CallPrice(type_K K, type_S S, type_sig sig, type_r r, type_b b);
double PutPrice(type_K K, type_S S, type_sig sig, type_r r, type_b b);

#endif /* OptionPricing_hpp */
