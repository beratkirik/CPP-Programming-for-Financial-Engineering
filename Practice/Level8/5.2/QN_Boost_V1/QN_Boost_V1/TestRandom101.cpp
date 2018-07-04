//
//  TestRandom101.cpp
//  QN_Boost_V1
//
//  Created by Changheng Chen on 2/8/17.
//  Copyright © 2017 Changheng Chen. All rights reserved.
//

/* A linear congruential generator (LCG) is an algorithm that yields a sequence of pseudo-randomized numbers calculated with a discontinuous piecewise linear equation. */

#include <boost/random.hpp> // Convenience header file
#include <boost/Random/detail/const_mod.hpp> // LCG class
#include <ctime>            // std::time
#include <iostream>

using namespace std;

template <class PRNG, class Dist>
inline boost::variate_generator<PRNG&, Dist> make_gen(PRNG& rng, Dist d)
{
    return boost::variate_generator<PRNG&, Dist>(rng, d);
}

int main()
{
    // Choose a distribution to generate random numbers
    boost::triangle_distribution<> tri(0.0, 0.5, 1.0);
    //boost::normal_distribution<> nor(0.0, 1.0); // Change the following lines accordingly
    
    
    // Get random number generator
    
    //boost::mt19937 rng;
    //rng.seed(static_cast<unsigned int> (std::time(0)));
    //boost::variate_generator< boost::mt19937&, boost::triangle_distribution<> > triRng(rng, tri);
    
    boost::lagged_fibonacci607 rng;
    rng.seed(static_cast<unsigned int> (std::time(0)));
    boost::variate_generator< boost::lagged_fibonacci607&, boost::triangle_distribution<> > triRng(rng, tri);
    
    for (int n = 0; n <= 100; ++n)
    {
        cout << triRng() << ",";
        
    }
    
    return 0;
}
