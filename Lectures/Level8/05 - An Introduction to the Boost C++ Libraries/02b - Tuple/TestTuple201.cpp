// Tuple201.cpp
//
// (C) Datasim Education BV 2011
//

#include "boost/tuple/tuple.hpp"
#include "boost/tuple/tuple_io.hpp"
#include <string>
#include <iostream>
using namespace std;

boost::tuple<double, double> Arithmetic(double f, double s)
{ // Simple 101 example

	// Create an anonymous object
	return boost::make_tuple(f+s, f*s);
}

int main()
{
     // Using declaration, for readability purposes
     using boost::tuple;

     // Creating tuples
     tuple<string, double> myTuple(string("Hello"), 3.1415);
     tuple<string, int> 
     myTuple2 = boost::make_tuple(string("position x"), 0);

	 // Retrieving values from a tuple
     tuple<long, double, string> 
                newTuple(100, 2.17, string("a new tuple"));

     long first = newTuple.get<0>();
     double second = newTuple.get<1>();
     string third = newTuple.get<2>();
	
     cout << "Elements of tuple: " << first << ", " << second  << ", " << third << endl;

	 // Using make_tuple()
	 double a = 2.0; double b = 3.0;
	 tuple<double, double> calc = Arithmetic(a, b);

	 // Print tuple
	 cout << "Arithmetic: " << calc.get<0>() << ", " << calc.get<1>() << endl;
	 cout << calc << endl;

	 // Modifying the tuple's element values using get member function
	 calc.get<0>() = 3.0;
	 calc.get<1>() = 2.0;
	 cout << "Arithmetic: " << calc.get<0>() << ", " << calc.get<1>() << endl;

	 // Modification using free function get, notice the namespace
	 boost::tuples::get<0>(calc) = 5.0;
	 boost::tuples::get<1>(calc) = 5.0;

	 // Print tuple
	 //cout << "Arithmetic: " << calc.get<0>() << ", " << calc.get<1>() << endl;
	 cout << "After modification: " << calc << endl;


	 // Tie tuple elements with normal C variables
	 string name; double value;
	 tuple<string, double> myTupleA(string("Hello"), 3.1415);
	 boost::tie(name, value) = myTupleA;
	 cout << "Tuple components: " << name << ", " << value << endl;

     return 0;
}
