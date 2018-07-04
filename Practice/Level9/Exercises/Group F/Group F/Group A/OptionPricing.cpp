//
//  OptionPricing.cpp
//  Group A
//
//  Created by Changheng Chen on 2/20/17.
//  Copyright © 2017 Changheng Chen. All rights reserved.
//

#include "OptionPricing.hpp"
#include <cmath>

//================================ Gausian functions ================================

// In general, we would use similar functions in Boost::Math Toolkit

// (0.1) PDF
double n(double x)
{
    double A = 1.0/sqrt(2.0 * 3.1415);
    return A * exp(-x*x*0.5);
}

// (0.2) The approximation to the cumulative normal distribution
double N(double x)
{
    double a1 = 0.4361836;
    double a2 = -0.1201676;
    double a3 = 0.9372980;
    
    double k = 1.0/(1.0 + (0.33267 * x));
    
    if (x >= 0.0)
    {
        return 1.0 - n(x) * (a1*k + (a2*k*k) + (a3*k*k*k));
    }
    else
    {
        return 1.0 - N(-x);
    }
}


//=============================== Exact C and P Option Prices ===============================

// (1.1) Call option price C
double CallPrice(type_T T, type_K K, type_sig sig, type_r r, type_b b, type_S S)
{
    double d1 = (log(S/K) + (b + (sig*sig)*0.5) * T)/(sig * sqrt(T));
    double d2 = d1 - sig * sqrt(T);
    
    return (S * exp((b-r)*T) * N(d1)) - (K * exp(-r*T) * N(d2));
}

double CallPrice(const OptionData& data)
{
    return CallPrice(data.T, data.K, data.sig, data.r, data.b, data.S);
}


// (1.2) Put option price P
double PutPrice(type_T T, type_K K, type_sig sig, type_r r, type_b b, type_S S)
{
    double d1 = (log(S/K) + (b + (sig*sig)*0.5) * T)/(sig * sqrt(T));
    double d2 = d1 - sig * sqrt(T);
    
    return (K * exp(-r*T) * N(-d2)) - (S * exp((b-r)*T) * N(-d1));
}

double PutPrice(const OptionData& data)
{
    return PutPrice(data.T, data.K, data.sig, data.r, data.b, data.S);
}


//========================== Option Sensitivities, aka the Greeks ============================

// (2.1a) Gamma (exact formula)
double CallPutGamma(type_T T, type_K K, type_sig sig, type_r r, type_b b, type_S S)
{
    double d1 = (log(S/K) + (b + (sig*sig)*0.5) * T) / (sig * sqrt(T));
    
    return (n(d1) * exp((b-r)*T)) / (S* sig * sqrt(T));
}

double CallPutGamma(const OptionData& data)
{
    return CallPutGamma(data.T, data.K, data.sig, data.r, data.b, data.S);
}

// (2.1b) Gamma (divided difference approximation)
double CallPutGamma(type_T T, type_K K, type_sig sig, type_r r, type_b b, type_S S, type_S h)
{
    type_S S1, S2;
    S1 = S - h;
    S2 = S + h;
    
    return (CallPrice(T, K, sig, r, b, S2) - 2 * CallPrice(T, K, sig, r, b, S)
          + CallPrice(T, K, sig, r, b, S1)) / (h*h);
}

double CallPutGamma(const OptionData& data, type_S h)
{
    return CallPutGamma(data.T, data.K, data.sig, data.r, data.b, data.S, h);
}


// (2.2a) Delta for call (exact formula)
double CallDelta(type_T T, type_K K, type_sig sig, type_r r, type_b b, type_S S)
{
    double d1 = (log(S/K) + (b + (sig*sig)*0.5) * T) / (sig * sqrt(T));
    
    return exp((b-r)*T) * N(d1);
}

double CallDelta(const OptionData& data)
{
    return CallDelta(data.T, data.K, data.sig, data.r, data.b, data.S);
}

// (2.2b) Delta for call (divided difference approximation)
double CallDelta(type_T T, type_K K, type_sig sig, type_r r, type_b b, type_S S, type_S h)
{
    type_S S1, S2;
    S1 = S - h;
    S2 = S + h;
    
    return (CallPrice(T, K, sig, r, b, S2) - CallPrice(T, K, sig, r, b, S1)) / (2*h);
}

double CallDelta(const OptionData& data, type_S h)
{
    return CallDelta(data.T, data.K, data.sig, data.r, data.b, data.S, h);
}


// (2.3a) Delta for put (exact formula)
double PutDelta(type_T T, type_K K, type_sig sig, type_r r, type_b b, type_S S)
{
    double d1 = (log(S/K) + (b + (sig*sig)*0.5) * T) / (sig * sqrt(T));
    
    return -exp((b-r)*T) * N(-d1);
}

double PutDelta(const OptionData& data)
{
    return PutDelta(data.T, data.K, data.sig, data.r, data.b, data.S);
}

// (2.3b) Delta for put (divided difference approximation)
double PutDelta(type_T T, type_K K, type_sig sig, type_r r, type_b b, type_S S, type_S h)
{
    type_S S1, S2;
    S1 = S - h;
    S2 = S + h;
    
    return (PutPrice(T, K, sig, r, b, S2) - PutPrice(T, K, sig, r, b, S1)) / (2*h);
}

double PutDelta(const OptionData& data, type_S h)
{
    return PutDelta(data.T, data.K, data.sig, data.r, data.b, data.S, h);
}
