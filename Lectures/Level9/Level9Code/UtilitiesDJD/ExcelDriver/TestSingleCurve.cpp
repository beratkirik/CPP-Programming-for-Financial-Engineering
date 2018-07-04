// TestSingleCurve.cpp
//
// Displaying a single curve on one Excel sheet.
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
	
	std::cout << "Data has been created\n";

	try 
	{
		printOneExcel(x,vec1,	std::string("1 array"), std::string("Time"), std::string("Value"));
	}
	catch(DatasimException& e)
	{
		e.print();
	}

	try 
	{
		printOneExcel(x,vec1); // Default annotation settings
	}
	catch(DatasimException& e)
	{
		e.print();
	}

	return 0;
}
