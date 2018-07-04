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
using namespace std;


void print(const boost::tuple<string, int, double>& source)
{ // Function to print Person
    
    cout << "Name: " << source.get<0>() << "; Age: " <<
    source.get<1>() << "; Height (cm): " << source.get<2>() << endl;
}


int main()
{
    // Using declaration, for readability purposes
    using boost::tuple;
    
    // Typedef for a Person tuple that contains a name, age and height
    typedef tuple<string, int, double> Person;

    // Create a few person tuple instances
    Person person1 = boost::make_tuple(string("Alex"), 24, 176.0);
    Person person2 = boost::make_tuple(string("Bill"), 26, 178.0);
    Person person3 = boost::make_tuple(string("Carl"), 28, 180.0);
    
    // Print persons
    print(person1);
    print(person2);
    print(person3);
    
    // Increment the age of the 1st element in persons
    cout << "Before age change: " << person1 << endl;
    person1.get<1>() += 1;
    cout << "After age change:  " << person1 << endl;
    
    return 0;
}
