// TestMultiCurve.cpp
//
// Displaying multple curves on one Excel sheet.
//
// Modification dates:
//
// 2007-3-3 DD Kick-offs
// 2007-7-23 DD Some schemes (e.g. IE added)
// 2007-7-27 DD derivative-free scheme
// 2009-6-14 DD clean up
// 2012-1-17 DD for QN
//
// (C) Datasim Education BV 2005-2012
//


#include "UtilitiesDJD/VectorsAndMatrices/Vector.cpp"
#include "UtilitiesDJD/ExcelDriver/ExcelMechanisms.hpp"
#include "UtilitiesDJD/Geometry/Range.cpp"
#include "UtilitiesDJD/ExceptionClasses/DatasimException.hpp"

#include <cmath>
#include <list>
#include <string>

int main()
{
	// DON'T FORGET TO MODIFY EXCELIMPORTS.CPP for correct version of Excel.

	long N = 40;

	// Create abscissa x array
	Vector<double, long> x(N,0.0);
	double T = 10.0;
	double h = T/double(N);
	x[x.MinIndex()] = 0.0;
	x[x.MaxIndex()] = T;
	for (long j = x.MinIndex()+1; j <= x.MaxIndex()-1; ++j)
	{
		x[j] = x[j-1] + h;
	}

	Vector<double, long> vec1(N,0.0);
	for (long j = vec1.MinIndex(); j <= vec1.MaxIndex(); ++j)
	{
		vec1[j] = pow(-1.0, j);
	}

	Vector<double, long> vec2 = vec1 + 2.0;
	Vector<double, long> vec3 = vec1 - 3.0;
	Vector<double, long> vec4 = vec1 + vec3;

	// Now Excel output in one sheet for comparison purpposes
	std::list<std::string> labels;							// Names of each vector
	std::list<Vector<double, long > > functionResult;	// The list of Y values

	labels.push_back("Array One");
	labels.push_back("Array Two");
	labels.push_back("Array Three");
	labels.push_back("Array Four");

	functionResult.push_back(vec1);
	functionResult.push_back(vec2);
	functionResult.push_back(vec3);
	functionResult.push_back(vec4); 
	
	std::cout << "Data has been created\n";

	try 
	{
		printInExcel(x,labels, functionResult, 
						string("All In One"), string("Time"), string("Value"));
	}
	catch(DatasimException& e)
	{
		e.print();
	}

	return 0;
}
