//
//  FDM.hpp
//  PAC_FDM
//
//  FDM scheme for 1 factor Black Scholes equation. For the
//  moment we assume explicit Euler.
//
//  Created by Changheng Chen on 2/14/17.
//  Copyright © 2017 Changheng Chen. All rights reserved.
//

#ifndef FDM_hpp
#define FDM_hpp

#include "ParabolicPDE.hpp"
#include "UtilitiesDJD/VectorsAndMatrices/Vector.cpp"
#include "UtilitiesDJD/VectorsAndMatrices/ArrayMechanisms.cpp"

#include <iostream>
using namespace std;

using namespace ParabolicIBVP;

class FDM
{
public:
    // Solver solver;
    
    // Vector<double, long> A, B, C; // LHS coefficients at level n+1
    Vector<double, long> a, bb, c;   // LHS coefficient at level n
    Vector<double, long> RHS;        // Inhomogeneous term
    
    Vector<double, long> vecOld; // Solution at n
    Vector<double, long> vecNew; // Solution at n+1
    
    FDM()
    {
        
    }
    
    void initIC(const Vector<double, long>& xarr)
    { // Initalize the solution at time zero. This occurs only
      // at the interior mesh points of xarr (and there are J-1
      // of them).
        
        vecOld = Vector<double, long> (xarr.Size(), xarr.MinIndex());
        
        // Initialize at the boundaries
        vecOld[vecOld.MinIndex()] = BCL(0.0);
        vecOld[vecOld.MaxIndex()] = BCR(0.0);
        
        // Now initialize values in interior of interval using
        // the initial function 'IC' from the PDE
        for (int j = xarr.MinIndex()+1; j <= xarr.MaxIndex()-1; j++)
        {
            vecOld[j] = IC(xarr[j]);
        }
        
        // print(vecOld);
        
        vecNew = vecOld;  // V2 optimize
    }
    
    const Vector<double, long>& current() const
    {
        return vecNew;
    }
    
    void calculateCoefficients(const Vector<double, long>& xarr, double tprev, double tnow)
    { // Calculate the coefficients for the solver
        
        // Explicit method
        // A = Vector<double, long> (xarr.Size(), xarr.MinIndex(), 0.0);
        // C = A;
        // B = Vector<double, long> (xarr.Size(), xarr.MinIndex(), 1.0);
        
        a = Vector<double, long> (xarr.Size()-2, xarr.MinIndex()+1, 0.0);
        bb = Vector<double, long> (xarr.Size()-2, xarr.MinIndex()+1, 0.0);
        c = Vector<double, long> (xarr.Size()-2, xarr.MinIndex()+1, 0.0);
        RHS = Vector<double, long> (xarr.Size()-2, xarr.MinIndex()+1, 0.0);
        
        double tmp1, tmp2;
        double k = tnow - tprev;
        double h = xarr[xarr.MinIndex()+1] - xarr[xarr.MinIndex()];
        
        for (int j = xarr.MinIndex()+1; j <= xarr.MaxIndex()-1; j++)
        {
            tmp1 = k * ( (sigma)(xarr[j], tprev)/(h*h) );
            tmp2 = k * ( ( (mu)(xarr[j], tprev) * 0.5 )/h );
            
            a[j] = tmp1 - tmp2;
            bb[j] = 1.0 - (2.0 * tmp1) + (k * (b)(xarr[j], tprev));
            c[j] = tmp1 + tmp2;
            RHS[j] = k * f(xarr[j], tprev);
        }
    }
    
    void solve(double tnow)
    {
       // Explict method
        
        vecNew[vecNew.MinIndex()] = BCL(tnow);
        vecNew[vecNew.MaxIndex()] = BCR(tnow);
        
        for (int i = vecNew.MinIndex()+1; i <= vecNew.MaxIndex()-1; i++)
        {
            vecNew[i] = (a[i] * vecOld[i-1]) + (bb[i] * vecOld[i]) + (c[i] * vecOld[i+1]) - RHS[i];
        }
        vecOld = vecNew; // Not the most efficient, V2 can optimize it
    }

};


#endif /* FDM_hpp */
