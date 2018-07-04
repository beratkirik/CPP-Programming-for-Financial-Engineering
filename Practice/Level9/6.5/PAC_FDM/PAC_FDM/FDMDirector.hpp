//
//  FDMDirector.hpp
//  PAC_FDM
//
//  The class that drives the whole FDM process. It
//  mediates between the Mesh generation class and the
//  FDM class.
//
//  This class computes teh solution up to t = T (expiry).
//
//  Created by Changheng Chen on 2/14/17.
//  Copyright © 2017 Changheng Chen. All rights reserved.
//

#ifndef FDMDirector_hpp
#define FDMDirector_hpp

#include "mesher.hpp"
#include "fdm.hpp"

#include <iostream>
using namespace std;

class FDMDirector
{
private:
    FDMDirector()
    {
        
    }
    
    double T;
    double Xmax;
    
    double k;
    long J, N;
    double tprev, tnow;
    FDM fdm;
    
public:
    Vector<double, long> xarr;  // Mesh array in space S
    Vector<double, long> tarr;  // Mesh array in time
    
public:
    FDMDirector(double XM, double TM, long J, long NT)
    {
        T = TM;
        J = J;
        N = NT;
        Xmax = XM;
        fdm = FDM();
        
        //Create meshes in S and t
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
        // Step 1, 2: Get stuff form Mesher
        tprev = tnow = 0.0;
        k = T/N;
        
        // Step 3: Update new mesh array in FDM scheme
        fdm.initIC(xarr);
    }
    
    void doit()
    {
        // Step 4, 5: Get new coefficient arrays + solve
        for (int n = tarr.MinIndex() + 1; n <= tarr.MaxIndex(); ++n)
        {
            tnow = tarr[n]; // n+1 time step
            fdm.calculateCoefficients(xarr, tprev, tnow);
            fdm.solve(tnow);
            tprev = tnow; // n becomes n+1
        }
    }
};

#endif /* FDMDirector_hpp */
