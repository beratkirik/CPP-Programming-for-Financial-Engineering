// ParabolicPDE.hpp
//
// Namespace containing the function pointers and data
// that represent the defining parameters of the initial 
// boundary value problem for the 1 factor Black Scholes 
// PDE.
//
//	2005-1-5 DD Kick-off code
//
// (C) Datasim Education BV 2005
//

#ifndef ParabolicIBVP_HPP
#define ParabolicIBVP_HPP

namespace ParabolicIBVP
{

	// Coefficients of PDE equation
	double (*sigma)(double x, double t); // Diffusion term
	double (*mu)(double x, double t);	 // Convection term
	double (*b)(double x, double t);	 // Free term
	double (*f)(double x, double t);	 // The forcing term term


	// (Dirichlet) boundary conditions
	double (*BCL)(double t);	 // The left-hand boundary condition
	double (*BCR)(double t);	 // The right-hand boundary condition

	// Initial condition
	double (*IC)(double x);		// The condition at time t = 0

}

#endif