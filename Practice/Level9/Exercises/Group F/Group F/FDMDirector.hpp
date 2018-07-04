// FDMDirector.hpp
//
// The class that drives the whole FDM process. It
// mediates between the Mesh generation class and the 
// FDM class.
//
// This class computes the solution up to t = T (expiry).
//
// (C) Datasim Education BV 2005-2011
//

#ifndef FDMDirector_HPP
#define FDMDirector_HPP

#include "mesher.hpp"
#include "fdm.hpp"

#include <iostream>
using namespace std;

class FDMDirector
{

private:
	FDMDirector ()
	{


	}

	double T;
	double Xmax;

	double k;
	long J, N;
	double tprev, tnow;
	FDM fdm;

public:
	Vector<double, long> xarr; // Mesh array in space S
	Vector<double, long> tarr; // Mesh array in time 

public:
	FDMDirector (double XM, double TM, long J, long NT)
	{

		T = TM;
		J = J;
		N = NT;
		Xmax = XM;
		fdm = FDM();

		// Create meshes in S and t
		Mesher mx(0.0, Xmax);
		xarr = mx.xarr(J);

		Mesher mt(0.0, T);
		tarr = mt.xarr(NT);

		Start();
	}

	
	const Vector<double, long>& current() const
	{
		return fdm.current();
	}

	void Start() // Calculate next level
	{
		// Steps 1, 2: Get stuff from Mesher
		tprev = tnow = 0.0;
		k = T/N;
	
		// Step 3: Update new mesh array in FDM scheme
		fdm.initIC(xarr);

	}

	void doit()
	{
		// Step 4, 5: Get new coefficient arrays + solve
		
		for (int n = tarr.MinIndex() +1; n <= tarr.MaxIndex(); ++n)
		{
				tnow = tarr[n]; // n+1
				fdm.calculateCoefficients(xarr, tprev, tnow);
				fdm.solve(tnow);
				tprev = tnow; // n becomes n+1
		}
		
	}
};

#endif