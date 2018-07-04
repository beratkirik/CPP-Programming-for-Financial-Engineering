//
//  main.cpp
//  Exercise 4
//
//  Created by Changheng Chen on 2/10/17.
//  Copyright © 2017 Changheng Chen. All rights reserved.
//

#include <boost/random.hpp> // Convenience header file
#include <boost/Random/detail/const_mod.hpp> // LCG class
#include <ctime>            // std::time
#include <map>
#include <iostream>

using namespace std;

int main()
{
    // Throwing dice.
    
    // Choose Mersenne Twister as the pseudorandom number generator (PRNG)
    boost::random::mt19937 myRng;
    
    // Set the seed
    myRng.seed(static_cast<boost::uint32_t> (std::time(0)));
    
    // Uniform in range [1,6]
    boost::random::uniform_int_distribution<int> six(1,6);
    
    map<int, long> statistics; // Structure to hold outcome + frequencies
    int outcome;               // Current outcome
    
    
    /* a) Generate a large number of trials and place their frequencies in map.
       b) Produce the following kind of output: */
    
    // Choose the number for trials
    cout << "How many trials? "; int N; cin >> N;
    
    // Initialize count numbers
    for (int i = 0; i < 6; ++i)
        statistics[i+1] = 0;
    
    // Throw the dice
    for (int i = 0; i < N; ++i)
    {
        outcome = six(myRng);  // Generate a number in the range [1,6]
        statistics[outcome]++;
    }
    
    // Choose precision
    cout.precision(6); // Number of values behind comma
    
    // Produce the anwser
    cout << endl;
    for (int i = 0; i < 6; ++i)
        cout << "Trial " << i+1 << " has " << 100.0 * double(statistics[i+1]) / double(N) << "% outcomes" << endl;
    
    return 0;
}
