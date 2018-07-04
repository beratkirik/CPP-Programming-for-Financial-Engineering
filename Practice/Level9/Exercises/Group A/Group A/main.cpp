//
//  main.cpp
//  Group A
//
//  Created by Changheng Chen on 2/20/17.
//  Copyright © 2017 Changheng Chen. All rights reserved.
//

#include "EuropeanOption.hpp"
#include "ArrayFuncs.hpp"

int main()
{
    //======================================= A.1 a) =======================================
    // BS stock option model (b = r):          Batch1    Batch2    Batch3    Batch4
    type_T T     = (type_T) 1.5;     //    T:   0.25      1.00      1.00      30.0
    type_K K     = (type_K) 120.0;     //    K:   65.0     100.0      10.0     100.0
    type_sig sig = (type_sig) 0.4;   //  sig:   0.30      0.20      0.50      0.30
    type_r r     = (type_r) 0.04;     //    r:   0.08      0.00      0.12      0.08
    type_b b     = (type_b) 0.04;     //    b:   0.08      0.00      0.12      0.08
    type_S S     = (type_S) 100.0;     //    S:   60.0     100.0      5.00     100.0
    
    // Create and set an option with the specified values
    EuropeanOption option;
    option.SetOption(T, K, sig, r, b, S);
    
    cout << "Call price: " << option.CallPriceEuro() << endl;
    cout << "Put price: " << option.PutPriceEuro() << endl;
    
    
    
    //======================================= A.1 b) =======================================
    // Put-call parity
    cout << "\nPut price from parity relationship: " << option.PutPriceFromParity() << endl;
    cout << "Is put-call parity satisfied? " << (option.ParityChecker() ? "Yes." : "No.") << endl;
    
    
    
    //======================================= A.1 c) =======================================
    // Change CallPrice and PutPrice in EuropeanOption.hpp to test struct as input
    cout << "\nCall price: " << option.CallPriceEuro() << endl;
    cout << "Put price: " << option.PutPriceEuro() << endl;
    
    
    
    //======================================= A.1 d) =======================================
    // Specify a range of S
    type_S S_start    = (type_S) 10.0;
    type_S S_end      = (type_S) 50.0;
    type_S S_interval = (type_S) 1.0;
    
    // Compute call/put price as a function of S, and print it
    vector<type_S> S_array = MeshArray(S_start, S_end, S_interval);
    vector<double> S_CallPrices = option.CallPriceEuro(S_array);
    vector<double> S_PutPrices = option.PutPriceEuro(S_array);
    
    cout << "\nVariable(S), Call Price, Put Price" << endl;
    PrintArray(S_array, S_CallPrices, S_PutPrices);

    
    
    //======================================= A.1 e) =======================================
    // (1) Repeat A.1 d) by replacing S with T
    // Reset option
    option.SetOption(T, K, sig, r, b, S);

    type_T T_start    = (type_T) 0.50;
    type_T T_end      = (type_T) 5.00;
    type_T T_interval = (type_T) 0.50;
    
    // Compute call/put price as a function of T, and print it
    vector<type_T> T_array = MeshArray(T_start, T_end, T_interval);
    vector<double> T_CallPrices = option.CallPriceEuro(T_array);
    vector<double> T_PutPrices = option.PutPriceEuro(T_array);
    
    cout << "\nVariable(T), Call Price, Put Price" << endl;
    PrintArray(T_array, T_CallPrices, T_PutPrices);

    
    // (2) Repeat A.1 d) by replacing S with sig
    // Reset option
    option.SetOption(T, K, sig, r, b, S);
    
    type_sig sig_start    = (type_sig) 0.10;
    type_sig sig_end      = (type_sig) 0.50;
    type_sig sig_interval = (type_sig) 0.05;
    
    // Compute call price as a function of sig, and print it
    vector<type_sig> sig_array = MeshArray(sig_start, sig_end, sig_interval);
    vector <double> sig_CallPrices = option.CallPriceEuro(sig_array);
    vector<double> sig_PutPrices = option.PutPriceEuro(sig_array);
    
    cout << "\nVariable(sig), Call Price, Put Price" << endl;
    PrintArray(sig_array, sig_CallPrices, sig_PutPrices);
    
    
    
    //======================================= A.2 a) =======================================
    // Futures option (b = 0)
    T     = (type_T) 0.5;
    K     = (type_K) 100.0;
    sig   = (type_sig) 0.36;
    r     = (type_r) 0.1;
    b     = (type_b) 0.0;
    S     = (type_S) 105.0;
    
    // Set option with the specified values
    option.SetOption(T, K, sig, r, b, S);
    cout << "\nGamma: " << option.CallPutGammaEuro() << endl;
    cout << "Delta for call: " << option.CallDeltaEuro() << endl;
    cout << "Delta for put: " << option.PutDeltaEuro() << endl;
    
    
    
    //======================================= A.2 b) =======================================
    // Specify a range of S
    S_start    = (type_S) 10.0;
    S_end      = (type_S) 50.0;
    S_interval = (type_S) 1.00;
  
    // Compute delta for call as a function of S, and print it
    S_array = MeshArray(S_start, S_end, S_interval);
    vector<double> Deltas = option.CallDeltaEuro(S_array);
    
    cout << "\nVariable(S), Delta for Call" << endl;  // Print a header
    PrintArray(S_array, Deltas);
    
    
    
    //======================================= A.2 c) =======================================
    // (1) Repeat calculations in A.2 a)
    
    /*"Round-off errors: The root cause is finite precision of floating-point arithmetic. 
      In that case there is a theoretical lower bound on h ~ 0.03 (AFAIR) below which
      the approximation becomes worse. This optimum value is to minimize the sum of 
      discretisation and round-off errors." */
    
    // Reset option
    option.SetOption(T, K, sig, r, b, S);
    type_S h = (type_S) 0.05;
    
    cout << "\nGamma and Delta from the exact formula: " << endl;
    cout << "Gamma: " << option.CallPutGammaEuro() << endl;
    cout << "Delta for call: " << option.CallDeltaEuro() << endl;
    cout << "Delta for put: " << option.PutDeltaEuro() << endl;
    
    cout << "\nGamma and Delta from divided difference approximation: " << endl;
    cout << "Gamma: " << option.CallPutGammaEuro(h) << endl;
    cout << "Delta for call: " << option.CallDeltaEuro(h) << endl;
    cout << "Delta for put: " << option.PutDeltaEuro(h) << endl;
    
    // (2) Repeat calculations in A.2 b)
    Deltas = option.CallDeltaEuro(S_array, h);
    
    cout << "\nVariable(S), Delta for Call" << endl;
    PrintArray(S_array, Deltas);
    cout << endl;
    
    return 0;
}
