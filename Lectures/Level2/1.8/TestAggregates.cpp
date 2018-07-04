// TestAggregates.cpp
//
// Defining aggregate structures. We model data that pertains to
// plain options. The struct can be used in pricing algorihms as a 
// simple data store. 
// It is also possible to create arrays of these structs; each struct can 
// have its own set of values.
//
// DJD
//

#include "OptionData.hpp"

int main()
{

	OptionData myData;

	myData.K = 100.0;
	myData.T = 1.0;
	myData.r = 0.12;
	myData.sig = 0.1;
	myData.D = 0.03;
	myData.beta = 0.1;
	myData.type = +1;

	print(myData);

	print2(&myData);

	return 0;
}
