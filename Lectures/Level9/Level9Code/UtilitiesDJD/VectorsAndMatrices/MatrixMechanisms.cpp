// MatrixMechanisms.cpp
//
// Mechanism functions for matrices. 
//
//	Modification dates
//	
//	DD 2004-4-3 Kick off
//	DD 2004-4-9 Power method, code review and round-off
//  DD 2005-12-1 Extracting a row fom a Matrix (can be optmised)
//	DD 2006-8-6 set_diagonal() commented out
//
// (C) Datasim Education BV 2004-2012
//

#ifndef MatrixMechanisms_cpp
#define MatrixMechanisms_cpp


#include "UtilitiesDJD/VectorsAndMatrices/MatrixMechanisms.hpp"
////////////// Useful and Basic Print Functions ////////////////////////////////////////////////////
template <class V, class I> void print(const Matrix<V,I>& mat)
{


	for (int i = mat.MinRowIndex(); i <= mat.MaxRowIndex(); i++)
	{
	
		cout << "\n[";
		for (I j = mat.MinColumnIndex(); j <= mat.MaxColumnIndex()-1; j++)
		{
			cout << mat(i,j) << ", ";
		}
		cout << mat(i, mat.MaxColumnIndex());
		cout << "]" << endl;
	
	}
	cout << endl;
}

#endif