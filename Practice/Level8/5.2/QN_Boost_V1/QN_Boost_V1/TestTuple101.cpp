//
//  TestTuple101.cpp
//  Tuple
//
//  Created by Changheng Chen on 2/7/17.
//  Copyright © 2017 Changheng Chen. All rights reserved.
//

#include <boost/tuple/tuple.hpp>    // Tuple class
#include <boost/tuple/tuple_io.hpp> // I/O for tuples

#include <string>
#include <iostream>
using namespace std;

int main()
{
    // Using declaration, for readability purposes
    using boost::tuple;
    
    // Creating tuples using Tuple constructor with appropriate arguments
    tuple<string, int> myTuple = boost::make_tuple(string("position x"), 0);
    
    // Print the tuple
    cout << myTuple << endl; 
    
    return 0;
}
