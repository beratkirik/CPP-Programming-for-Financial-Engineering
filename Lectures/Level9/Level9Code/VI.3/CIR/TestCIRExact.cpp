// TstCIR.hpp
//
// Defining parameters of CIR zcb
//
// (C) Datasim Education BV 2009-2011
//

#include "CIR.hpp"

#include <vector>
#include <iostream>
using namespace std;

void print(const vector<double>& vec)
{
	cout << endl;
	for (std::size_t i = 0; i < vec.size(); ++i)
	{
		cout << vec[i] << ", ";
	}
	cout << endl;
}

void print(const vector<vector<double>>& matrix)
{
	cout << endl;
	for (std::size_t i = 0; i < matrix.size(); ++i)
	{
		print(matrix[i]);
	}
	cout << endl;
}

int main()
{

	using namespace AffineModel;
	a = 0.0025;
	sig = sqrt(0.01);
	b = 0.05;

	double T = 0.5;

	double d = priceCIR(0.49, T);
	cout << "Bond price: " << d << endl;

	long NR = 6;
	double rMin = 0.0;
	double rMax = 1.0;
	
	vector<double> xarr(NR);
	xarr[0] = rMin;
	xarr[xarr.size()-1] = rMax; // To avoid rounding errors at x = 1.
	double h = (rMax - rMin)/NR;
	for (std::size_t n = 1; n < xarr.size()-1; ++n)
	{
		xarr[n] = xarr[n-1] + h;
	}
	// Choose which model to use 
	double (*affineModel) (double x, double t);
	affineModel = priceCIR;

	vector<double> bondArray = priceCIR(xarr, T, affineModel);
	print(bondArray);

	long NT = 5; double k = T/NT;
	vector<double> tarr(NT);
	tarr[0] = 0.0;
	tarr[tarr.size()-1] = T; // To avoid rounding errors at t = T.
	for (std::size_t n = 1; n < tarr.size()-1; ++n)
	{
		tarr[n] = tarr[n-1] + k;
	}

	vector<vector<double>> result = priceCIR(xarr, tarr, affineModel);
	print(result);

	return 0;
}