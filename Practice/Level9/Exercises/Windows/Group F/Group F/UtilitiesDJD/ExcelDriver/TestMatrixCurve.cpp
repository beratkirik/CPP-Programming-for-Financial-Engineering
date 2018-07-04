// TestMatrixCurve.cpp
//
// Displaying a matrix on one Excel sheet.
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


#include "UtilitiesDJD/VectorsAndMatrices/NumericMatrix.cpp"
#include "UtilitiesDJD/ExcelDriver/ExcelMechanisms.hpp"
#include "UtilitiesDJD/ExcelDriver/ExcelDriver.hpp"
#include "UtilitiesDJD/Geometry/Range.cpp"
#include "UtilitiesDJD/ExceptionClasses/DatasimException.hpp"

#include <cmath>
#include <list>
#include <string>

double BellCurve(double x, double y)
{

	return exp(-x*x - y*y);
}

int main()
{
	// DON'T FORGET TO MODIFY EXCELIMPORTS.CPP for correct version of Excel.

	long N = 50;
	long M = 50;
	// Create abscissa x array
	Vector<double, long> x(N,0.0);
	double a1 = -3.0;
	double b1 = 3.0;
	double h1 = (b1 - a1)/double(N);
	x[x.MinIndex()] = a1;
	x[x.MaxIndex()] = b1;
	for (long j = x.MinIndex()+1; j <= x.MaxIndex()-1; ++j)
	{
		x[j] = x[j-1] + h1;
	}

	Vector<double, long> y(M,0.0);
	double a2 = -3.0;
	double b2 = 3.0;
	double h2 = (b2 - a2)/double(M);
	y[y.MinIndex()] = a2;
	y[y.MaxIndex()] = b2;
	for (long j = y.MinIndex()+1; j <= y.MaxIndex()-1; ++j)
	{
		y[j] = y[j-1] + h2;
	}

		
	std::cout << "Data has been created\n";

	NumericMatrix<double, long> mat(x.Size(), y.Size(), x.MinIndex(), y.MinIndex());

	// Create a Gaussian 'bell'
	for (long i = mat.MinRowIndex(); i <= mat.MaxRowIndex(); ++i)
	{
		for (long j = mat.MinColumnIndex(); j <= mat.MaxColumnIndex(); ++j)
		{
			mat(i,j) = BellCurve(x[i], y[j]);
		}
	}

	try 
	{
		printMatrixInExcel(mat, x, y, string("TWOFAC"));
	}
	catch(DatasimException& e)
	{
		e.print();

		ExcelDriver& excel = ExcelDriver::Instance();
		excel.MakeVisible(true);	
 
		excel.printStringInExcel(e.Message(), 1, 1, string("Err"));

		list<string> dump;
		dump.push_back(e.MessageDump()[0]);
		dump.push_back(e.MessageDump()[1]);
		dump.push_back(e.MessageDump()[2]);

		excel.printStringInExcel(dump, 1, 1, string("Err"));
	}

	return 0;
}
