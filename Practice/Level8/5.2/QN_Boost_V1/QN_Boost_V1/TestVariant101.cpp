//
//  TestVariant101.cpp
//  QN_Boost_V1
//
//  Show the essentials of the Variant Library. There is type-safe
//  visitation of variants (outside current scope).
//
//  Created by Changheng Chen on 2/7/17.
//  Copyright © 2017 Changheng Chen. All rights reserved.
//

#include <boost/variant.hpp>
#include "Point.hpp"

#include <iostream>
#include <string>
using namespace std;

int main()
{
    // Using declaration, for readability purposes
    using boost::variant;
    
    // Eauivalent of C union
    typedef variant<int, float, double> NumericDataType;
    
    NumericDataType myType = 3.142;
    cout << myType << endl;
    myType = 1.98f;
    cout << myType << endl;
    myType = static_cast<double>(3.14);
    cout << myType << endl;
    
    // Gives compiler error
    // myType = string("dddd");
    
    // Some ways to construct a variant
    variant<long, string, Point> myVariant; // default-constructed long
    variant<long, string, Point> myVariant2(myVariant);
    
    Point pt(1.0, 2.0);
    variant<long, string, Point> myVariant3(pt);
    
    long val = 100;
    variant<long, string, Point> myVariant4(val);
    
    variant<long, string, Point> myVariant5 = myVariant4;
    
    variant<long, string, Point> myVariant6 = val;
    
    // Give some values
    myVariant = 24;
    myVariant = string("It's amazing");
    myVariant = Point(3.0, 4.0);
    
    // Try to get the value out of the variant
    Point ptA;
    string stA;
    try
    {
      //ptA = boost::get<Point>(myVariant);
        stA = boost::get<string>(myVariant); // won't work, wrong type
    }
    catch (boost::bad_get& err) // The following suffices as well
    //catch (std::exception& err)
    {
        cout << "Error: " << err.what() << endl;
    }
    
    cout << "Value got from Variant: " << ptA << endl; 
    
    return 0;
}
