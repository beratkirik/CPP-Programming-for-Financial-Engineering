// ExcelMechanisms.cpp
//
// Useful functions for use with Excel.
//
// 2005-11-29 DD kick-off
// 2005-12-16 DD Introduce exception handling (in about functions)
// 2006-2-2 DD print a tensor's matrices at intervals
// 2006-6-14 DD Bug fix PrintInExcel
// 2008-8-6 DD printPairOneExcel()
// 2008-10-21 DD function to print f(x,y) functions
// 2009-1-11 DD associative matrix print
// 2009-1-22 DD PrintdifferenceinExcel
// 2009-6-26 DD use function object for displaying functions
// 2012-1-17 DD fur QN
//
// (C) Datasim Education BV 2005-2012

//

#ifndef ExcelMechanisms_CPP
#define ExcelMechanisms_CPP


#include "UtilitiesDJD/ExcelDriver/ExcelMechanisms.hpp"
#include "UtilitiesDJD/ExceptionClasses/DatasimException.hpp"
#include "UtilitiesDJD/ExcelDriver/ExcelDriver.hpp"
#include "UtilitiesDJD/VectorsAndMatrices/MatrixMechanisms.cpp"
#include <list>
#include <iostream>

// Hard-coded strings
const string comma(", ");
const string bracketL("[");
const string bracketR("]");

void printOneExcel(const Vector<double, long>& x,						
					const Vector<double, long>& functionResult,
					const std::string& title,
					const std::string& horizontal, 
					const std::string& vertical,
					const std::string& legend)
{ 
	// N.B. Excel has a limit of 8 characters; after that you get a run-time error

	// PREC: Type I
	if (x.Size() != functionResult.Size())
	{
		
		string tmp = string("Sizes of vectors are X, Y: ") + getString(x.Size()) + string(comma) + getString(functionResult.Size());

		throw DatasimException(string("Size mismatch of two vectors"), string("PrintOneExcel"),
			tmp);
	}


	cout << "Starting Excel\n";

	ExcelDriver& excel = ExcelDriver::Instance();

	excel.MakeVisible(true);		// Default is INVISIBLE!

	// Workaround
	list<std::string> legendList; legendList.push_back(legend);
	list<Vector<double, long> > functionResultList; functionResultList.push_back(functionResult);

	excel.CreateChart(x, legendList, functionResultList, title, horizontal, vertical);
	
}

// Print two line graphs for comparison
void printPairExcel(const Vector<double, long>& x,						
					const Vector<double, long>& Arr1, const Vector<double, long>& Arr2,
					const std::string& title, 
					const std::string& horizontal, 
					const std::string& vertical,
					const std::string& legend)
{
	if (x.Size() != Arr1.Size() || x.Size() != Arr2.Size())
	{
		
		string tmp = string("Sizes of vectors are X, Y: ") + getString(x.Size()) + string(comma) + getString(Arr1.Size())
			+ getString(Arr2.Size());

		throw DatasimException(string("Size mismatch of two vectors"), string("PrintOneExcel"),
			tmp);
	}


	cout << "Starting Excel\n";

	ExcelDriver& excel = ExcelDriver::Instance();

	excel.MakeVisible(true);		// Default is INVISIBLE!

	// Workaround
	list<std::string> legendList; 
	legendList.push_back(legend + "Arr1");
	legendList.push_back(legend + "Arr2");

	list<Vector<double, long> > functionResultList; 
	functionResultList.push_back(Arr1);
	functionResultList.push_back(Arr2);

	excel.CreateChart(x, legendList, functionResultList, title, horizontal, vertical);

}


void printInExcel(const Vector<double, long>& x,		// X array
					const list<std::string>& labels,					// Names of each vector
					const list<Vector<double, long> >& functionResult,	// The list of Y values
					const std::string& title,
					const std::string& horizontal, 
					const std::string& vertical)
{ // Print a list of Vectors in Excel. Each vector is the output of
  // a finite difference scheme for a scalar IVP

	// PREC: Type I
//	if (x.Size() != labels.size() || x.Size() != functionResult.size())
	// No cheque of x array size
	if (labels.size() != functionResult.size())
	{
		string tmp = "Sizes of vectors are X, Y, Label: " + getString(x.Size()) + comma +
			getString(functionResult.size()) + comma + getString(labels.size());

		throw DatasimException(string("Size mismatch of vectors and labels"), string("PrintInExcel"),
			tmp);
	}


	cout << "Starting Excel\n";

	ExcelDriver& excel = ExcelDriver::Instance();

	excel.MakeVisible(true);		// Default is INVISIBLE!


	excel.CreateChart(x, labels, functionResult, title, horizontal, vertical);

}

// Print a two-dimensional array (typically, one time level)
void printMatrixInExcel(const NumericMatrix<double, long>& matrix,
				 const Vector<double, long>& xarr, const Vector<double, long>& yarr, 
				 const std::string& SheetName)
{

	// PREC: Type II, III
	if (xarr.Size() != matrix.Rows() || yarr.Size() != matrix.Columns())
	{
		string tmp = "Vectors X, Y, matrix M: " + getString(xarr.Size()) + comma + getString(yarr.Size())
			+ bracketL + getString(matrix.Rows()) + comma + getString(matrix.Columns()) + bracketR;

		throw DatasimException(string("Size mismatch of vector(s) and matrix"), string("PrintMatrixInExcel"),
			tmp);
	}

	ExcelDriver& excel = ExcelDriver::Instance();
	excel.MakeVisible(true);
	// Print a matrix showing the x and y positions

	// We need to convert the double arrays to lists of strings
	cout << "Starting Excel";

	list<std::string> rowlabels = convertToString(xarr);
	list<std::string> columnlabels = convertToString(yarr);

	cout << "Staring Excel";
	
	excel.AddMatrix(SheetName, matrix, rowlabels, columnlabels);

}


#endif