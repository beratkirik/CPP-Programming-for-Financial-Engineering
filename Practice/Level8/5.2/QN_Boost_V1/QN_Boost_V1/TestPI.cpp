//
//  TestPI.cpp
//  QN_Boost_V1
//
//  Calculation of PI using random numbers; it's analogous
//  to throwing darts.
//
//  Created by Changheng Chen on 2/8/17.
//  Copyright © 2017 Changheng Chen. All rights reserved.
//

#include <boost/random.hpp> // Convenience heard file
#include <iostream>
#include <ctime>            // std::time
using namespace std;

#include <boost/limits.hpp>

int main()
{
    // A. Define the lagged Fibonacci and Normal objects
    boost::lagged_fibonacci607 rng;
    rng.seed(static_cast<boost::uint32_t> (std::time(0)));
    boost::uniform_real<> uni(0.0, 1.0);
    //boost::normal_distribution<> uni(0.0, 1.0); // Not a good distribution here!
    
    // B. Produce Uniform (0, 1)
    boost::variate_generator< boost::lagged_fibonacci607&, boost::uniform_real<> > uniRng(rng, uni);
    //boost::variate_generator< boost::lagged_fibonacci607&, boost::normal_distribution<> > uniRng(rng, uni);
    
    // C. Choose the desired accurary
    cout << "How many darts to throw? "; long N; cin >> N;
    
    // D. Throw the dart; does it fall in the circle or outside
    // Start throwing darts and count where they land
    long hits = 0;
    double x, y, distance;
    for (long n = 1; n <= N; ++n)
    {
        x = uniRng(); y = uniRng();
        distance = sqrt(x*x + y*y);
        
        if (distance <= 1)
        {
            hits++;
        }
    }
    
    // E. Produce the anwser
    cout << "Number of hits, PI is: " << hits << ", " << 4.0 * double(hits) / double(N) << endl;
    
    return 0;
}
