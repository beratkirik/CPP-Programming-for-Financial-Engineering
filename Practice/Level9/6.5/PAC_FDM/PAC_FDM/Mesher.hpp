//
//  Mesher.hpp
//  PAC_FDM
//
//  A simple mesher on a 1d domain. We divide
//  an interval into J+1 mesh points, J-1 of which
//  are internal mesh points.
//
//  Created by Changheng Chen on 2/14/17.
//  Copyright © 2017 Changheng Chen. All rights reserved.
//

#ifndef Mesher_hpp
#define Mesher_hpp

#include "UtilitiesDJD\VectorsAndMatrices\Vector.cpp"
#include <vector>
using namespace std;

class Mesher
{
public:
    double a, b;    // In space
    
    Mesher()
    {
        a =0.0; b = 1.0;
    }
    
    Mesher (double A, double B)
    { // Describe the domain of integration
        
        a = A;
        b = B;
    }
    
    Vector<double, long> xarr(int J)
    {
        // NB Full array (includes end points)
        
        double h = (b - a) / double (J);
        
        int size = J+1;
        int start = 1;
        
        Vector<double, long> result(size, start);
        result[result.MinIndex()] = a;
        
        for (int j = result.MinIndex()+1; j <= result.MaxIndex(); j++)
        {
            result[j] = result[j-1] + h;
        }
        
        return result;
    }
    
    vector<double> Xarr(int J)
    { // Return as an STL vector
        
        // NB Full array (includes end points)
        
        double h = (b - a) / double (J);
        
        int size = J+1;
        int start = 1;
        
        vector<double> result(size, start);
        result[0] = a;
        
        for (int j = 1; j < result.size(); j++)
        {
            result[j] = result[j-1] + h;
        }
        
        return result;
    }
    
};

#endif /* Mesher_hpp */
