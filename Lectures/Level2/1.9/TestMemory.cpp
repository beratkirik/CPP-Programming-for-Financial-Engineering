// TestAggregates.cpp
//
// Defining aggregate structures. We model data that pertains to
// plain options. The struct can be used in pricing algorithms as a 
// simple data store.
//
// DJD
//

#include <stdlib.h>
#include "OptionData.hpp"

int main()
{

	// Create a single object on the heap
	int n = 1;
	OptionData* myData = (OptionData*)malloc(n * sizeof(OptionData)); // cast void* to OptionData*
	
	(*myData).K = 100.0;
	(*myData).T = 1.0;
	(*myData).r = 0.12;
	(*myData).sig = 0.1;
	(*myData).D = 0.03;
	(*myData).beta = 0.1;
	(*myData).type = +1;

	//print(*myData);

	// Create multiple objects on the heap
	n = 4;
	//OptionData* myDataArray = (OptionData*)malloc(n * sizeof(OptionData));
	OptionData* myDataArray = new OptionData[n];

	// Initialise the array
	for (int j = 0; j < n; ++j)
	{
		myDataArray[j] = *myData;

		// Modify expiry
		myDataArray[j].T = double (j) + 0.5;
	}

	// Print the array
	for (int j = 0; j < n; ++j)
	{
	//	print(myDataArray[j]);
	}

	// Deallocate memory
	free(myData);
//	free(myDataArray);
	delete [] myDataArray;

	//double d = 1/2;
	//cout << d;

	return 0;
}
