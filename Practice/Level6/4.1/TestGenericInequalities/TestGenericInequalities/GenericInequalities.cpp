//
//  GenericInequalities.cpp
//  TestGenericInequalities
//
//  Code file containing bodies of functions
//
//  Created by Changheng Chen on 1/21/17.
//  Copyright © 2017 Changheng Chen. All rights reserved.
//

//#ifndef GenericInequalities_CPP
//#define GenericInequalities_CPP

//#include "GenericInequalities.hpp"


//////////// Useful functions ////////////

// Max and Min of two numbers
template <class Numeric>
Numeric Max(const Numeric& x, const Numeric& y)
{
    if (x > y)
        return x;
    return y;
}

template <class Numeric>
Numeric Min(const Numeric& x, const Numeric& y)
{
    if (x < y)
        return x;
    return y;
}

// Max and Min of three numbers
template <class Numeric>
Numeric Max(const Numeric& x, const Numeric& y, const Numeric& z)
{
    return Max<Numeric>(Max<Numeric>(x, y), z);
}

template <class Numeric>
Numeric Min(const Numeric& x, const Numeric& y, const Numeric& z)
{
    return Min<Numeric>(Min<Numeric>(x, y), z);
}

//#endif
