// StringConversions.hpp
//
// Handy string functions
//
// (C) Datasim Education BV 2006
//

#ifndef StringConversions_HPP
#define StringConversions_HPP

#include "UtilitiesDJD/VectorsAndMatrices/Vector.cpp"
#include <string>
#include <list>
using namespace std;
#include <stddef.h>

// Simple and useful string converters
string getString(long j);

string getString(int j);

string getString(size_t j);

string getString(double d);


// Convert an array to a list of strings
list<string> convertToString(const Vector<double, long>& arr);

#endif