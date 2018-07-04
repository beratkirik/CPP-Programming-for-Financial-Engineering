//
//  main.cpp
//  Group B
//
//  Created by Changheng Chen on 2/26/17.
//  Copyright © 2017 Changheng Chen. All rights reserved.
//

#include "ArrayFuncs.hpp"
#include "AmericanOption.hpp"

int main()
{
    //================ a) Program the formula of perpetual American option ================
    // Option pricing global functions in OptionPricing.hpp and OptionPricing.cpp
    
    
    //============================ b) Test the following data =============================
    // Give values to the option properties
    type_K     K = (type_K) 100;
    type_S     S = (type_S) 110;
    type_sig sig = (type_sig) 0.1;
    type_r     r = (type_r) 0.1;
    type_b     b = (type_b) 0.02;
    
    // Create and set the option with specified values
    AmericanOption option;
    option.SetOption(K, S, sig, r, b);
    
    cout << "Price, call, " << option.PerpetualCall() << endl;
    cout << "Price, put, " << option. PerpetualPut() << endl << endl;
    
    
    //====================== c) Call and put prices as function of S ======================
    // Specify the range of S and create a mesh array
    type_S start    = (type_S) 10.0;
    type_S end      = (type_S) 50.0;
    type_S interval = (type_S) 1.0;  // (start-end)/40
    vector<type_S> S_array = MeshArray(start, end, interval);
    
    // Calculate call and put prices as a function of S, and print to the console
    vector<double> CallPrices = option.PerpetualCall(S_array);
    vector<double> PutPrices = option.PerpetualPut(S_array);
    
    cout << "Variable(S), Call Price, Put Price" << endl; // Print a header
    PrintArray(S_array, CallPrices, PutPrices);
    
    return 0;
}
