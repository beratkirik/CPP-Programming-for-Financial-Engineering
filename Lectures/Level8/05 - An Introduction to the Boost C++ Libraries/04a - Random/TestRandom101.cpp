// TestRandom101.cpp
//
// Basic functionality to show how Random works
//
// (C) Datasim Education BV 2010-2011
//

#include <boost/random.hpp> // Convenience header file
#include <iostream>
#include <ctime>			// std::time
#include <boost/Random/detail/const_mod.hpp> // LCG class

using namespace std;

template<class PRNG, class Dist>
inline boost::variate_generator<PRNG&, Dist> make_gen(PRNG & rng, Dist d)
{
  return boost::variate_generator<PRNG&, Dist>(rng, d);
}


int main()
{
	
	// Get random number generator
	boost::mt19937 rng;
	rng.seed(static_cast<unsigned int> (std::time(0)));

	boost::triangle_distribution<> tri(0.0, 0.5, 1.0);
	
	//boost::lagged_fibonacci607 rng;
	rng.seed(static_cast<unsigned int> (std::time(0)));
	boost::variate_generator<boost::mt19937&, boost::triangle_distribution<> > 
							triRng(rng, tri);
//	boost::variate_generator<boost::lagged_fibonacci607&, boost::triangle_distribution<> > 
	//						triRng(rng, tri);

	for (int n = 0; n <=100; ++n)
	{
		cout << triRng() << ",";
	}

	return 0;

}