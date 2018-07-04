// ArrayMechanisms.cpp
//
// 2003-8-1 Initial code DD
// 2003-80-6 DD major code review and changes
// 2004-4-3 DD testing etc.
// 2004-4-9 DD Code review and final fiat (for time being)
// 2005-6-19 DD print function for Tensor
// 2005-1-8 DD big fix in l2Norm (wrong name)
// 2007-6-25 DD major new update, code 
// 2012-1-17 DD student 
//
// (C) Datasim Education BV 2003-2012
//

#ifndef ArrayMechanisms_cpp
#define ArrayMechanisms_cpp

#include "UtilitiesDJD/VectorsAndMatrices/ArrayMechanisms.hpp"

#include <iostream>
using namespace std;


////////////////////// Print Functions /////////////////////////////////////////
template <typename V, typename I> void print(const Array<V,I>& v)
{

	cout << "\n\nMinIndex: " << v.MinIndex() << " , MaxIndex: " << v.MaxIndex() << endl;

	cout << "\nARR:[";
	for (I j = v.MinIndex(); j <= v.MaxIndex(); ++j)
	{
		cout << v[j] << ", ";
	
	}

	cout << "]";
}

template <typename V, typename I> void print(const Vector<V,I>& v)
{

	cout << "\n\nMinIndex: " << v.MinIndex() << " , MaxIndex: " << v.MaxIndex() << endl;

	cout << "\nARR:[";
	for (I j = v.MinIndex(); j <= v.MaxIndex(); ++j)
	{
		cout << v[j] << ", ";
	
	}

	cout << "]";
}


#endif