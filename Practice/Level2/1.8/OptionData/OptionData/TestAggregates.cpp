//
//  Defining aggregate structures. We model data that pertains to
//  plain options. The struct can be used in pricing algorithms as a
//  simple data store.
//
//  TestAggregates.cpp
//
//  Created by Changheng Chen on 11/13/16.
//  Copyright © 2016 Changheng Chen. All rights reserved.
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
