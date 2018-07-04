// STLAlgorithsm.cpp
//
// A subset of the 70-80 algorithms in STL. The objective is to show 
// how to use them.
//
// Use this code as a base for extra examples from Josuttis' book.
//
// (C) Datasim Education BV 2010-2011
//

#include <numeric>				// Numeric algorithms
#include <functional>			// For function objects
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>

using namespace std;

template <class T> void print(const vector<T>& l, const string& comment)
{  // A generic print function for vectors
	
	cout << comment << ": ";

	// We must use a const iterator here, otherwise we get a compiler error.
	vector<T>::const_iterator i;
// vector<T>::iterator i;
	for (i = l.begin(); i != l.end(); ++i)
	{
			cout << *i << ",";
	}

	cout << endl;
}


// C functions thhat can be used with STL algorithms
template <typename T>
			void MultiplyByTwo(T& t)
{ // Modifier function

		t *= 2;
}

template <typename T>
	T Square(const T& t)
{ // Selector function

		return t*t; 
}

int main()
{

	// A. NUMERIC ALGORITHMS
	int size = 4;
	vector<int> vec(size);
	for (int i = 0; i < vec.size(); ++i)
	{
		vec[i] = i + 1;
	}
	vec[1] = 5;

	print(vec, string("original vector vec: "));

	// Accumulate: Computing the result of one sequence.
	int initVal = 1;										// Must be initialised to a value
	int acc1 = accumulate(vec.begin(), vec.end(), initVal);	// Add initVal to all elements
	cout << "Sum 1: " << acc1 << endl;

	// A. Multiply (using predefined function object) each element by initVal and sum them
	int acc2 = accumulate(vec.begin(), vec.end(), initVal, multiplies<int>());
	cout << "Sum 2: " << acc2 << endl;

	// Sums of products + initVal
	int ip1 = inner_product(vec.begin(), vec.end(), vec.begin(), initVal);
	cout << "Inner product1: " << ip1 << endl;
	
	// Using two predefined function object using inner and outer operations
	// Sum of products; ?? product of sums
	vector<int> vec2(vec);
	double ip2 = inner_product(vec.begin(), vec.end(), vec2.begin(), 1,
									multiplies<int>(),	// inner
									plus<int>());		// outer
	cout << "Inner product2: " << ip2 << endl;

	// B. NONMODIFYING ALGORIHMS

	// Count the number of elements equal to a given value.
	double val = 99;
	cout << "Number of elements equal to " << val << " = " << count(vec.begin(), vec.end(), val) << endl;

	// Serching for elements; find the first element in a container equal to a given value;
	int searchValue = 99;
	vector<int>::iterator posS = find(vec.begin(), vec.end(),  searchValue);

	// Test if value has been found
	if (posS != vec.end())
	{
		cout << "***Value: " << *posS << endl;
	}
	else
	{
		cout << "***Value not found\n";
	}

	// C MODIFYING ALGORIHMS
	// Modifier, user-defined function
	for_each(vec.begin(), vec.end(), MultiplyByTwo<int>);
	print(vec, string("Modifier, for_each(): "));

	// Modifier, user-defined function
	transform(vec.begin(), vec.end(), vec.begin(), Square<int>);
	print(vec, string("Modifier, transform(): "));

	// Replacing elements
	int M = 10;
	vector<char> vecChar(M, 'd');

	char oldChar = 'd';
	char newChar = 'D';
	replace(vecChar.begin(), vecChar.end(), oldChar, newChar);
	print(vecChar, string("After replace (all):"));

	// D. MUTATING ALGORITHMS
	
	// Reversing the order of elements
	reverse(vec.begin(), vec.end());
	print(vec, string("Modifier, vector reversed: "));

	// Rotating elements in a sequence
	vector<int> myVec(8);
	for (int i = 0; i < myVec.size(); ++i)
	{
		myVec[i] = i + 1;
	}

	cout << "Number of shifts (< 0 to right, > 0 to left): :"; int shift; cin >> shift;


	// Call 1 function?

	if (shift > 0)
	{
		rotate(myVec.begin(), myVec.begin() + shift, myVec.end());
		print(myVec, string("Modifier, vector rotated: "));
	}
	else
	{
		rotate(myVec.begin(), myVec.end() + shift, myVec.end());
		print(myVec, string("Modifier, vector rotated: "));
	}
	
	return 0;
}