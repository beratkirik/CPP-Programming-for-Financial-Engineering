//
//  ParabolicPDE.hpp
//  PAC_FDM
//
//  Namespace containing the function pointers and data
//  that represent the defining parameters of the initial
//  boundary value problem for the 1 factor Black Scholes
//  PDE.
//
//  Created by Changheng Chen on 2/14/17.
//  Copyright © 2017 Changheng Chen. All rights reserved.
//

#ifndef ParabolicPDE_hpp
#define ParabolicPDE_hpp

namespace ParabolicIBVP
{
    // Coefficients of PDE equation
    double (*sigma)(double x, double t); // Diffusion term
    double (*mu)(double x, double t);    // Convection term
    double (*b)(double x, double t);     // Free term
    double (*f)(double x, double t);     // The forcing term
    
    // (Dirichelet) boundary conditions
    double (*BCL)(double t);   // The left-hand boundary condition
    double (*BCR)(double t);   // The righ-hand boundary condition
    
    // Initial condition
    double (*IC)(double x);    // The condition at time t = 0
}


#endif /* ParabolicPDE_hpp */
