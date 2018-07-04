// TestPI.cpp
//
// Calculation of PI using random numbers; it's analogous
// to throwing darts.
//
// (C) Datasim Education BV 2010-2011
//

#include <boost/random.hpp> // Convenience header file
#include <iostream>
#include <ctime>			// std::time
using namespace std;

#include <boost/limits.hpp>

int main()
{
	// A. Define the lagged Fibonacci and Normal objects
	boost::lagged_fibonacci607 rng;
	rng.seed(static_cast<boost::uint32_t> (std::time(0)));
	boost::uniform_real<> uni(0.0,1.0);

	// B. Produce Uniform (0, 1)
	boost::variate_generator<boost::lagged_fibonacci607&, boost::uniform_real<> > 
							uniRng(rng, uni);

	// C. Choose the desired accuracy
	cout << "How many darts to throw? "; long N; cin >> N;

	// D. Thow the dart; does it fall in the circle or outside
	// Start throwing darts and count where they land
	long hits = 0;
	double x, y, distance;
	for (long n = 1; n <= N; ++n)
	{
		x = uniRng(); y = uniRng();
		distance = sqrt(x*x + y*y);

		if ( distance <=1)
		{
			hits++;
		}
	}

	//E.  Produce the answer
	cout << "Numbers of hits, PI is: " << hits << ", " << 4.0 * double(hits) / double (N) << endl;
		
	return 0;

}int outcome; 