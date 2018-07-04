//
//  TestAggregates.cpp
//  1.9
//
//  Created by Changheng Chen on 11/13/16.
//  Copyright © 2016 Changheng Chen. All rights reserved.
//
//  Defining aggregate structures. We model data that pertains to
//  plain options. This struct can be used in pricing algorithms as a
//  simple data store.
//

#include <stdlib.h>
#include "OptionData.hpp"

int main()
{
    // Create a single object on the heap
    int n = 1;
    // struct OptionData* myData = (OptionData*)malloc(n * sizeof(OptionData)); // cast void* to OptionData* // same as the following
    OptionData* myData = (OptionData*)malloc(n * sizeof(OptionData));
    
    (*myData).K = 100.0;
    (*myData).T = 1.0;
    (*myData).r = 0.12;
    (*myData).sig = 0.1;
    (*myData).D = 0.03;
    (*myData).beta = 0.1;
    (*myData).type = +1;
    
//  print(*myData);
    
    // Create multiple objects on the heap
    n = 4;
//  OptionData* myDataArray = (OptionData*)malloc(n * sizeof(OptionData));
    OptionData* myDataArray = new OptionData[n];  // do a test
    
    // Initialize the array
    for (int j=0; j < n; ++j)
    {
        myDataArray[j] = *myData;
        
        // Modify expiry
        myDataArray[j].T = double (j) + 0.5;
    }
    
    // Print the array
    for (int j = 0; j < n; ++j)
    {
//      print(myDataArray[j]);
    }
    
    // Deallocate memory
    free(myData);
//  free(myDataArray);
    delete [] myDataArray;
    
    double d = 1/2;
    cout << d << endl;
    
    return 0; 
}
