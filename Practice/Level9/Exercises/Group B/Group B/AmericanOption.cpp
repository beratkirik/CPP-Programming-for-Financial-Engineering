//
//  AmericanOption.cpp
//  Group B
//
//  Created by Changheng Chen on 2/26/17.
//  Copyright © 2017 Changheng Chen. All rights reserved.
//

#include "AmericanOption.hpp"
#include "OptionPricing.hpp"


//=====================================================================================
// (0) Initializer and copier for private data members
void AmericanOption::init()
{ // Initialize with arbitrary values
    
    data.K   = 100.0;
    data.S   = 110.0;
    data.sig = 0.10;
    data.r   = 0.10;
    data.b   = 0.02;
}

void AmericanOption::copy(const AmericanOption& o2)
{
    data.K   = o2.data.K;
    data.S   = o2.data.S;
    data.sig = o2.data.sig;
    data.r   = o2.data.r;
    data.b   = o2.data.b;
}


//=====================================================================================
// (1) Constructors, destructor and assignment operator

AmericanOption::AmericanOption()
{ // Default call option
    
    init();
}

AmericanOption::AmericanOption(const AmericanOption& o2)
{ // Copy constructor
    
    copy(o2);
}

AmericanOption::~AmericanOption()
{ // Destructor
    
}

AmericanOption& AmericanOption::operator = (const AmericanOption& option2)
{
    if (this == &option2)
        return *this;
    
    copy(option2);
    
    return *this;
}


//=====================================================================================
// (2) Getter and Setter functions
type_K AmericanOption::GetK() const
{
    return data.K;
}

type_S AmericanOption::GetS() const
{
    return data.S;
}

type_sig AmericanOption::Getsig() const
{
    return data.sig;
}

type_r AmericanOption::Getr() const
{
    return data.r;
}

type_b AmericanOption::Getb() const
{
    return data.b;
}

OptionData AmericanOption::GetData() const
{
    return data;
}

void AmericanOption::SetOption(type_K newK, type_S newS, type_sig newsig, type_r newr, type_b newb)
{
    SetOption(newK);
    SetOption(newS);
    SetOption(newsig);
    SetOption(newr);
    SetOption(newb);
}


//=====================================================================================
// (3) Perpetual call and put option price

double AmericanOption::PerpetualCall()
{
    return CallPrice(data.K, data.S, data.sig, data.r, data.b);
}

double AmericanOption::PerpetualPut()
{
    return PutPrice(data.K, data.S, data.sig, data.r, data.b);
}
