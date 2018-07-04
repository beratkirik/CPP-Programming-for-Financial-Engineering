// NormalGenerator.cpp
// Class hierarchy for generating random numbers, 
// vectors and matrices.
// 
// This hierarchy uses the Template Method Pattern and it
// delegates to a Strategy pattern for generating uniform
// random numbers.
//
// The solution is object-oriented and uses run-time polymorphic
// functions. In another chapter we use policy classes and templates.
//
// Last modifucation dates:
//
//	2008-3-6 DD kick off
//  2009-5-16 DD generate fixed arrays of normal variates
//	2009-6-29 DD Boost Normal generator
//  2012-1-17 DD minimal Boost
//
// (C) Datasim Education BV 2008-20012
//

#include "UtilitiesDJD/RNG/NormalGenerator.hpp"
#include <cmath>



BoostNormal::BoostNormal() : NormalGenerator ()
{
	rng = boost::lagged_fibonacci607();
	nor = boost::normal_distribution<>(0,1);
	myRandom = new boost::variate_generator<boost::lagged_fibonacci607&, boost::normal_distribution<> >
			(rng, nor);

}


// Implement (variant) hook function
double BoostNormal::getNormal() const
{
	return (*myRandom)();
}


BoostNormal::~BoostNormal() 
{

	delete myRandom;
}



