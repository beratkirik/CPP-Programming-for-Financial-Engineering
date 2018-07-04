//
//  EuropeanOption.cpp
//  Group A
//
//  Created by Changheng Chen on 2/20/17.
//  Copyright © 2017 Changheng Chen. All rights reserved.
//

#ifndef EuropeanOption_cpp
#define EuropeanOption_cpp

#include "EuropeanOption.hpp"

//=====================================================================================
// (0) Initializer and copier for private data members
void EuropeanOption::init()
{ // Initialize with arbitrary values
    
    data.T   = 30.0;  // T = 30.0;
    data.K   = 100.0; // K = 100.0;
    data.sig = 0.30;  // sig = 0.30;
    data.r   = 0.08;  // r = 0.08;
    
    S = 100.0;
}

void EuropeanOption::copy(const EuropeanOption& o2)
{
    data.T   = o2.data.T;   // T = o2.T;
    data.K   = o2.data.K;   // K = o2.K;
    data.sig = o2.data.sig; // sig = o2.sig;
    data.r   = o2.data.r;   // r = o2.r;
    
    S = o2.S;
}

//=====================================================================================
// (1) Constructors, destructor and assignment operator

EuropeanOption::EuropeanOption()
{ // Default call option
    
    init();
}

EuropeanOption::EuropeanOption(const EuropeanOption& o2)
{ // Copy constructor
    
    copy(o2);
}

EuropeanOption::~EuropeanOption()
{ // Destructor
    
}

EuropeanOption& EuropeanOption::operator = (const EuropeanOption& option2)
{
    if (this == &option2)
        return *this;
    
    copy(option2);
    
    return *this;
}


//=====================================================================================
// (2) Getter and Setter functions

type_T EuropeanOption::GetT() const
{
    // return T;
    return data.T;
}

type_K EuropeanOption::GetK() const
{
    // return K;
    return data.K;
}

type_sig EuropeanOption::Getsig() const
{
    // return sig;
    return data.sig;
}

type_r EuropeanOption::Getr() const
{
    // return r;
    return data.r;
}

type_S EuropeanOption::GetS() const
{
    return S;
}

OptionData EuropeanOption::GetData() const
{
    return data;
}

void EuropeanOption::SetData(type_T newT, type_K newK, type_sig newsig, type_r newr, type_b newb)
{
    SetOption(newT);
    SetOption(newK);
    SetOption(newsig);
    SetOption(newr);
    SetOption(newb);
}

void EuropeanOption::SetOption(type_T newT, type_K newK, type_sig newsig, type_r newr, type_b newb, type_S newS)
{
    SetData(newT, newK, newsig, newr, newb);
    SetOption(newS);
}


//=====================================================================================
// (3) Option sensitivities, aka the Greeks

double EuropeanOption::CallPutGammaEuro() const
{ // Gamma (exact formula)
    
    return CallPutGamma(data, S);
}

double EuropeanOption::CallPutGammaEuro(type_S h) const
{ // Gamma (divided difference approximation)

    return CallPutGamma(data, S, h);
}


double EuropeanOption::CallDeltaEuro() const
{ // Delta for call (exact formula)
    
    return CallDelta(data, S);
}

double EuropeanOption::CallDeltaEuro(type_S h) const
{ // Delta for call (divided difference approximation)

    return CallDelta(data, S, h);
}


double EuropeanOption::PutDeltaEuro() const
{ // Delta for put (exact formula)
 
    return PutDelta(data, S);
}

double EuropeanOption::PutDeltaEuro(type_S h) const
{ // Delta for put (divided difference approximation)
    
    return PutDelta(data, S, h);
}


vector<double> EuropeanOption::CallDeltaEuro(const vector<type_S>& S_array)
{ // Delta for call as a function of varying S (exact formula)
    
    vector<double> deltas;
    for (int i = 0; i < S_array.size(); ++i)
    {
        SetOption(S_array[i]); // Update S of option
        deltas.push_back(CallDeltaEuro());
    }
    
    return deltas;
}

vector<double> EuropeanOption::CallDeltaEuro(const vector<type_S>& S_array, type_S h)
{ // Delta for call as a function of varying S (divided difference approximation)
    
    vector<double> deltas;
    for (int i = 0; i < S_array.size(); ++i)
    {
        SetOption(S_array[i]); // Update S of option
        deltas.push_back(CallDeltaEuro(h));
    }
    
    return deltas;
}


vector<double> EuropeanOption::PutDeltaEuro(const vector<type_S>& S_array)
{ // Delta for call as a function of varying S (exact formula)

    vector<double> deltas;
    for (int i = 0; i < S_array.size(); ++i)
    {
        SetOption(S_array[i]); // Update S parameter of option
        deltas.push_back(PutDeltaEuro());
    }
    
    return deltas;
}

vector<double> EuropeanOption::PutDeltaEuro(const vector<type_S>& S_array, type_S h)
{ // Delta for call as a function of varying S (divided difference approximation)

    vector<double> deltas;
    for (int i = 0; i < S_array.size(); ++i)
    {
        SetOption(S_array[i]); // Update S parameter of option
        deltas.push_back(PutDeltaEuro(h));
    }
    
    return deltas;
}


//=====================================================================================
// (4) Put/call pricing

double EuropeanOption::CallPriceEuro()
{
    return CallPrice(data, S);
    //return CallPrice(data.T, data.K, data.sig, data.r, data.r, S);
}

double EuropeanOption::PutPriceEuro()
{
    return PutPrice(data, S);
    //return PutPrice(data.T, data.K, data.sig, data.r, data.b, S);
}

bool EuropeanOption::PutCallParity()
{
    // Define a threshold value to compare put prices computed from two different equations
    double tolerance = 0.000001;
    double putprice1, putprice2;
    
    putprice1 = CallPriceEuro() - S + data.K * exp(-data.r*data.T);
    putprice2 = PutPriceEuro();
    
    return (fabs(putprice1-putprice2)<tolerance);
}

#endif /* EuropeanOption_cpp */

