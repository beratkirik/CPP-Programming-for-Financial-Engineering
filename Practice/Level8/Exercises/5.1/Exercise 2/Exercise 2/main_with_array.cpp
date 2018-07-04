//
//  main.cpp
//  Exercise 2
//
//  Created by Changheng Chen on 2/10/17.
//  Copyright © 2017 Changheng Chen. All rights reserved.
//

#include <boost/tuple/tuple.hpp>    // Tuple class
#include <boost/tuple/tuple_io.hpp> // I/O for tuples
#include <string>
#include <iostream>
#include "Array.hpp"

using namespace chako::Containers;
using namespace std;


void print(const boost::tuple<string, int, double>& source)
{ // Print function to print Person
    
    //cout << source << endl;
    cout << "Name: " << source.get<0>() << "; Age: " <<
    source.get<1>() << "; Height (cm): " << source.get<2>() << endl;
}

int main()
{
    // Using declaration, for readability purposes
    using boost::tuple;
    
    // Typedef for a Person tuple that contains a name, age and height
    typedef tuple<string, int, double> Person;
    
    // Create an array of N Person tuples
    int N = 4;
    Array<Person> persons(N);
    
    // Create a few person tuple instances
    persons[0] = boost::make_tuple(string("Alex"), 24, 176.0);
    persons[1] = boost::make_tuple(string("Bill"), 26, 178.0);
    persons[2] = boost::make_tuple(string("Carl"), 28, 180.0);
    persons[3] = boost::make_tuple(string("Dave"), 30, 182.0);
    
    // Print persons
    for (int i = 0; i < N; ++i)
        print(persons[i]);
    
    // Increment the age of the 1st element in persons
    cout << "Before age change: " << persons[0] << endl; // print(persons[0]);
    persons[0].get<1>() += 1;
    cout << "After age change:  " << persons[0] << endl;
    
    return 0;
}
