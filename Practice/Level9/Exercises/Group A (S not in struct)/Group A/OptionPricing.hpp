//
//  OptionPricing.hpp
//  Group A
//
//  Global functions for calculating the Call and Put prices based on the
//  exact solutions fo one-factor plain options, as well as the Greeks.
//
//  Created by Changheng Chen on 2/20/17.
//  Copyright © 2017 Changheng Chen. All rights reserved.
//

#ifndef OptionPricing_hpp
#define OptionPricing_hpp

#include "OptionData.hpp"

// (0) Gaussian functions
double n(double x);
double N(double x);


// (1) Overloaded pricing functions
double CallPrice(type_T T, type_K K, type_sig sig, type_r r, type_b b, type_S S);
double CallPrice(const OptionData& data, type_S S);

double PutPrice(type_T T, type_K K, type_sig sig, type_r r, type_b b, type_S S);
double PutPrice(const OptionData& data, type_S S);

// (2) Overloaded Greeks functions
// Gamma (exact formula)
double CallPutGamma(type_T T, type_K K, type_sig sig, type_r r, type_b b, type_S S);
double CallPutGamma(const OptionData& data, type_S S);

// Gamma (divided difference approximation)
double CallPutGamma(type_T T, type_K K, type_sig sig, type_r r, type_b b, type_S S, type_S h);
double CallPutGamma(const OptionData& data, type_S S, type_S h);


// Delta for call (exact formula)
double CallDelta(type_T T, type_K K, type_sig sig, type_r r, type_b b, type_S S);
double CallDelta(const OptionData& data, type_S S);

// Delta for call (divided difference approximation)
double CallDelta(type_T T, type_K K, type_sig sig, type_r r, type_b b, type_S S, type_S h);
double CallDelta(const OptionData& data, type_S S, type_S h);


// Delta for put (exact formula)
double PutDelta(type_T T, type_K K, type_sig sig, type_r r, type_b b, type_S S);
double PutDelta(const OptionData& data, type_S S);

// Delta for put (divided difference approximation)
double PutDelta(type_T T, type_K K, type_sig sig, type_r r, type_b b, type_S S, type_S h);
double PutDelta(const OptionData& data, type_S S, type_S h);

#endif /* OptionPricing_hpp */
