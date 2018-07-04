//
//  main.cpp
//  Group A
//
//  Created by Changheng Chen on 2/20/17.
//  Copyright © 2017 Changheng Chen. All rights reserved.
//

#include "EuropeanOption.hpp"
#include "ArrayFuncs.hpp"
#include "../UtilitiesDJD/VectorsAndMatrices/Vector.cpp"
#include "../UtilitiesDJD/VectorsAndMatrices/ArrayMechanisms.cpp"
#include "../UtilitiesDJD/ExcelDriver/ExcelMechanisms.hpp"
#include "../UtilitiesDJD/ExceptionClasses/DatasimException.hpp"
#include <iostream>

int main()
{
    // BS stock option model (b = r):          Batch1    Batch2    Batch3    Batch4
    type_T T     = (type_T) 1.00;   //    T:   0.25      1.00      1.00      30.0
    type_K K     = (type_K) 10.0;   //    K:   65.0     100.0      10.0     100.0
    type_sig sig = (type_sig) 0.50; //  sig:   0.30      0.20      0.50      0.30
    type_r r     = (type_r) 0.12;   //    r:   0.08      0.00      0.12      0.08
    type_b b     = (type_b) 0.12;   //    b:   0.08      0.00      0.12      0.08
    type_S S     = (type_S) 5.00;   //    S:   60.0     100.0      5.00     100.0
    
    // Create and set an option with the specified values
    EuropeanOption option;
    option.SetOption(T, K, sig, r, b, S);

    // Create S_array and compute option price arrays
    long N = 40;      // Number of intervals
    type_S S_start    = (type_S) 10.0;
    type_S S_end      = (type_S) 50.0;
    type_S S_interval = (type_S) ((S_end-S_start)/N);
    
    vector<type_S> S_array1      = MeshArray(S_start, S_end, S_interval);
    vector<double> S_CallPrices1 = option.CallPriceEuro(S_array1);
    vector<double> S_PutPrices1  = option.PutPriceEuro(S_array1);
    
    // For compatibility with the provided code, convert vector<> to Vector<>
    Vector<double, long> S_array2(N+1, 0), S_CallPrices2(N+1, 0), S_PutPrices2(N+1, 0);
    for (long j = S_array2.MinIndex(); j <= S_array2.MaxIndex(); ++j)
    {
        S_array2[j] = S_array1[j];
        S_CallPrices2[j] = S_CallPrices1[j];
        S_PutPrices2[j] = S_PutPrices1[j];
    }
    
    cout << "Print S, call prices, and put prices into Excel:\n";
 
    try
    {
        printPairExcel(S_array2, S_CallPrices2, S_PutPrices2, string("Option Price"), string("Asset Price (S)"), string("Call/Put Price"));
    }
    catch(DatasimException& e)
    {
        e.print();
    }

    return 0;
}
