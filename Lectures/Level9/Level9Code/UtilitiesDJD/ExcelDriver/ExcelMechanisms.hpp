// ExcelMechanisms.hpp
//
// Useful functions for use with Excel.
//
// (C) Datasim Education BV 2005-2012 
//

#ifndef ExcelMechanisms_HPP
#define ExcelMechanisms_HPP

#include "UtilitiesDJD/VectorsAndMatrices/Vector.cpp"
#include "UtilitiesDJD/VectorsAndMatrices/NumericMatrix.cpp"
#include "UtilitiesDJD/BitsAndPieces/StringConversions.hpp"
#include <string>
#include <list>
using namespace std;


// Print one line graph
void printOneExcel(const Vector<double, long>& x,						
					const Vector<double, long>& functionResult,
					const std::string& title = string("Title"), 
					const std::string& horizontal = string("X"), 
					const std::string& vertical = string("Y"),
					const std::string& legend = string("Y"));

// Print two line graphs for comparison
void printPairExcel(const Vector<double, long>& x,						
					const Vector<double, long>& Arr1, const Vector<double, long>& Arr2,
					const std::string& title = string("Title"), 
					const std::string& horizontal = string("X"), 
					const std::string& vertical = string("Y"),
					const std::string& legend = string("*"));

// Print multiple lines on one graph
void printInExcel(const Vector<double, long>& x,						// X array
					const list<std::string>& labels,					// Names of each vector
					const list<Vector<double, long> >& functionResult,	// The list of Y values
					const std::string& title = string("Title"),
					const std::string& horizontal = string("X"), 
					const std::string& vertical = string("Y"));

// Print a matrix as cell
void printMatrixInExcel(const NumericMatrix<double, long>& matrix,
				 const Vector<double, long>& xarr, const Vector<double, long>& yarr, 
				 const std::string& SheetName = string("Matrix"));


#endif