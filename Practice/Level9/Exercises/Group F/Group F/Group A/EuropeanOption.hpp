//
//  EuropeanOption.hpp
//  Group A
//
//  European option pricing class that can price, use parity,
//  and generate Greeks, with mesh functionality.
//
//  Created by Changheng Chen on 2/20/17.
//  Copyright © 2017 Changheng Chen. All rights reserved.
//

#ifndef EuropeanOption_hpp
#define EuropeanOption_hpp

#include "OptionPricing.hpp"
#include <vector>
using namespace std;

class EuropeanOption
{
private:
    OptionData data; // Encapulated data
    
    /*// Uncomment the following instead for A.1 a)
    type_T T;        // Expiry date
    type_K K;        // Strike price
    type_sig sig;    // Volatility
    type_r r;        // Interest rate
    type_b b;        // Carry of cost
    type_S S;        // Asset price
    */
    
public:
    // (0) Initialization of private data members
    void init();                         // Initialization with arbitrary values
    void copy(const EuropeanOption& o2); // Initialization from copying
    
    
    // (1) Constructors, destructor, and assignment operator
    EuropeanOption();                                          // Default constructor
    EuropeanOption(const EuropeanOption& option);              // Copy constructor
    virtual ~EuropeanOption();                                 // Destructor
    EuropeanOption& operator = (const EuropeanOption& option); // Assignment operator
    
    
    // (2) Getter and setter functions
    type_T GetT() const;          // Get T from data
    type_K GetK() const;          // Get K from data
    type_sig Getsig() const;      // Get sig from data
    type_r Getr() const;          // Get r from data
    type_b Getb() const;          // Get b from data
    type_S GetS() const;          // Get S
    OptionData GetData() const;   // Get data
    
    void SetData(type_T newT, type_K newK, type_sig newsig, type_r newr, type_b newb); // Set data/option
    void SetOption(type_T newT, type_K newK, type_sig newsig, type_r newr, type_b newb, type_S newS);
    
    
    // (3) Option sensitivities, aka the Greeks
    double CallPutGammaEuro() const;         // Gamma (exact formula)
    double CallPutGammaEuro(type_S h) const; // Gamma (divided difference approximation)
    
    double CallDeltaEuro() const;            // Delta for call (exact formula)
    double CallDeltaEuro(type_S h) const;    // Delta for call (divided difference approximation)
    
    double PutDeltaEuro() const;             // Delta for put (exact formula)
    double PutDeltaEuro(type_S h) const;     // Delta for put (divided difference approximation)
    
    // Input a range of S, and output a vector delta for call/put
    vector<double> CallDeltaEuro(const vector<type_S>& S_array);           // Exact formula
    vector<double> CallDeltaEuro(const vector<type_S>& S_array, type_S h); // Difference approximation
    
    vector<double> PutDeltaEuro(const vector<type_S>& S_array);            // Exact formula
    vector<double> PutDeltaEuro(const vector<type_S>& S_array, type_S h);  // Difference approximation
 
    
    //=========================================================================================
    // Declare and define call/put price function templates in this header file
    //=========================================================================================

    // (4) Exact C and P price function overloading
    double CallPriceEuro();      // Call price
    double PutPriceEuro();       // Put price
    bool ParityChecker();        // Put-call parity checker
    double PutPriceFromParity(); // Put price calcuated using parity relationship
    
    template <typename T> vector<double> CallPriceEuro(const vector<T>& m_array)
    { // Input variable is a range of T, K, sig, r, or S; output is an array of call prices
        
        vector<double> prices;
        for (int i = 0; i < m_array.size(); ++i)
        {
            SetOption(m_array[i]); // Overwrite option parameter with input
            prices.push_back(CallPriceEuro());
        }

        return prices;
    }
    
    template <typename T> vector<double> PutPriceEuro(const vector<T>& m_array)
    { // Input variable is a range of T, K, sig, r, or S; output is an array of put prices
        
        vector<double> prices;
        for (int i = 0; i < m_array.size(); ++i)
        {
            SetOption(m_array[i]); // Overwrite option parameter with input
            prices.push_back(PutPriceEuro());
        }
        
        return prices; 
    }
    
    
    //=========================================================================================
    // Append to (2) Set an option parameter based on input data type
    //=========================================================================================

    template<typename T> void SetOption(T var)
    { // Set a memeber data based on type
        
        if (std::is_same<T,type_S>::value)
        {
            data.S = var;
        }
        else if (std::is_same<T,type_T>::value)
        {
            data.T = var;
        }
        else if (std::is_same<T,type_K>::value)
        {
            data.K = var;
        }
        else if (std::is_same<T,type_sig>::value)
        {
            data.sig = var;
        }
        else if (std::is_same<T,type_r>::value)
        {
            data.r = var;
        }
        else if (std::is_same<T,type_b>::value)
        {
            data.b = var;
        }
    }

};

#endif /* EuropeanOption_hpp */
