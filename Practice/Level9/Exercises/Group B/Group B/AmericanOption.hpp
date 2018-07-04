//
//  AmericanOption.hpp
//  Group B
//
//  Created by Changheng Chen on 2/26/17.
//  Copyright © 2017 Changheng Chen. All rights reserved.
//

#ifndef AmericanOption_hpp
#define AmericanOption_hpp

#include "OptionPricing.hpp"
#include <vector>
using namespace std;

class AmericanOption
{
private:
    OptionData data; // Incapulated data
    
public:
    // (0) Initialization of private data members
    void init();                         // Initialization with arbitrary values
    void copy(const AmericanOption& o2); // Initialization from copying
    
    
    // (1) Constructors, destructor, and assignment operator
    AmericanOption();                                          // Default constructor
    AmericanOption(const AmericanOption& option);              // Copy constructor
    virtual ~AmericanOption();                                 // Destructor
    AmericanOption& operator = (const AmericanOption& option); // Assignment operator
    
    
    // (2) Getter and setter functions
    type_K GetK() const;          // Get K from data
    type_S GetS() const;          // Get S
    type_sig Getsig() const;      // Get sig from data
    type_r Getr() const;          // Get r from data
    type_b Getb() const;          // Get b from data
    OptionData GetData() const;   // Get data

    void SetOption(type_K newK, type_S newS, type_sig newsig, type_r newr, type_b newb);
    

    // (3) Perpetual call and put option price
    double PerpetualCall();       // Call price
    double PerpetualPut();        // Put price
    
    
    //========================================================================
    // Declare and define template member functions in this header file
    //========================================================================
    
    template<typename T> void SetOption(T var)
    { // Set a memeber data based on type
        
        if (std::is_same<T,type_K>::value)
        {
            data.K = var;
        }
        else if (std::is_same<T,type_S>::value)
        {
            data.S = var;
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
    
    template <typename T> vector<double> PerpetualCall(const vector<T>& arr)
    { // Perpetual call price as a function of 'var' array
        
        vector<double> prices;
        for (int i = 0; i < arr.size(); i++)
        {
            SetOption(arr[i]);
            prices.push_back(PerpetualCall());
        }
        
        return prices;
    }
    
    template <typename T> vector<double> PerpetualPut(const vector<T>& arr)
    { // Perpetual call price as a function of 'var' array
        
        vector<double> prices;
        for (int i = 0; i < arr.size(); i++)
        {
            SetOption(arr[i]);
            prices.push_back(PerpetualPut());
        }
        
        return prices;
    }
    
};

#endif /* AmericanOption_hpp */
