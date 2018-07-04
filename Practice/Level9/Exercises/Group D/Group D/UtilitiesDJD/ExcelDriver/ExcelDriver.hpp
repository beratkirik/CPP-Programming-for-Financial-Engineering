// ExcelDriver.hpp
//
// Excel driver class. This class is for VISUALISATION only
//
// (C) Datasim Education BV 2003 - 2006
//

#ifndef ExcelDriver_HPP
#define ExcelDriver_HPP

// !!!! RIGHT VERSION OF OFFICE!!!!!!
#include "UtilitiesDJD/ExcelDriver/ExcelImports.cpp" // Contains all versions of Office

// STL list class.
#include <list>
using namespace std;

// Datasim container TEMPLATE classes, that's why include CPP!!!!
#include "UtilitiesDJD/VectorsAndMatrices/Vector.cpp"
#include "UtilitiesDJD/VectorsAndMatrices/NumericMatrix.cpp"

// Excel driver class definition. Contains functionality to add charts 
// and matrices. Hides all COM details. COM exceptions are re-thrown
// as STL strings.

class ExcelDriver
{
private:
	// Private member data.
	Excel::_ApplicationPtr xl;		// Pointer to Excel.
	long curDataColumn;				// Current column of 'Chart Data'

	// Writes label and vector to cells in horizontal direction.
	void ToSheetHorizontal( Excel::_WorksheetPtr sheet,
					long sheetRow, long sheetColumn,
					const std::string& label,const Vector<double, long> & values );

	// Writes label and vector to cells in vertical direction.
	void ToSheetVertical( Excel::_WorksheetPtr sheet,
					long sheetRow, long sheetColumn,
					const std::string& label, const Vector<double, long> & values );


	// Throw COM error as string.
	void ThrowAsString( _com_error & error );

public:
	// Constructor. Starts Excel in invisible mode.
	ExcelDriver();

	// Destructor.
	virtual ~ExcelDriver();
	

	// Access to single, shared instance of ExcelDriver (singleton).
	static ExcelDriver& Instance();

	// Create chart with a number of functions. The arguments are:
	//  x:			vector with input values
	//  labels:		labels for output values
	//  vectorList: list of vectors with output values.
	//  chartTitle:	title of chart
	//  xTitle:		label of x axis
	//  yTitle:		label of y axis
	void CreateChart(const Vector<double, long> & x, const list<string> & labels, 
		const list<Vector<double, long> > & vectorList, const std::string& chartTitle, 
		const std::string& xTitle = "X", const std::string& yTitle = "Y");



    // Create chart with a number of functions. The arguments are:
	//  x:			vector with input values
	//  y:			vector with output values.
	//  chartTitle:	title of chart
	//  xTitle:		label of x axis
	//  yTitle:		label of y axis
	void CreateChart(const Vector<double, long> & x, const Vector<double, long> & y, const std::string& chartTitle, 
				 const std::string& xTitle = "X", const std::string& yTitle = "Y");


	// Add Matrix to the spreadsheet with row and column labels.
	void AddMatrix(const std::string& sheetName, const NumericMatrix<double, long>& matrix, 
			   const list<std::string>& rowLabels, const list<std::string>& columnLabels);
	void AddMatrix(const NumericMatrix<double, long>& matrix,const std::string& SheetName = "Matrix" );

	void MakeVisible( bool b);

	// For debugging, for example
	void printStringInExcel(const string& s, long rowNumber, long colNumber, 
						const string& sheetName);
	void printStringInExcel(const list<string>& s, long rowNumber, long colNumber, 
						const string& sheetName);


};
Vector <double, long> createVector(const NumericMatrix<double,long>& mat, long row);
#endif