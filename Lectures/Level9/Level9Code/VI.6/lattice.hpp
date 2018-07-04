// Lattice.hpp
//
// Class respresenting a special kind of tree-like matrix that is
// needed in specific applications, for example binomial and trinomial 
// methods in options pricing.
//
// This structure can be used in other applications, such as computer graphics
// and interpolation schemes.
//
// The matrix is 'expanding' in the form of a lattice; we must define a 
// function that states how many elements to create in moving from step 'n' 
// to step 'n+1'. The lattice is recombining or reconnecting as is usual in 
// some applications.
//
//
// This class is a basic data structure that can be used in other classes using
// composition or inheritance.
//
// (C) Datasim Component Technology 2001-2006


#ifndef Lattice_hpp
#define Lattice_hpp


#include "UtilitiesDJD/VectorsAndMatrices/Vector.cpp"


template <class V, class I, int NumberNodes> class Lattice
{ // Generic lattice class

private:

	// Implement as a full nested Vector class
	Array<Vector<V, I>, I >  tree;

	// Redundant data
	I nrows;			// Number of rows
	int typ;			// What kind of lattice (number of nodes)

public:
	// Constructors & destructor
	Lattice();						// Default constructor
	Lattice(const I& Nrows); 	// Number of rows and branch factor
	Lattice(const I& Nrows, const V& val); // + value at nodes
	Lattice(const Lattice<V, I, NumberNodes>& source);		// Copy constructor
	virtual ~Lattice();							// Destructor

	// Iterating in a Lattice; we need forward and backward versions
	I MinIndex() const;								// Return the minimum row index
	I MaxIndex() const;								// Return the maximum row index
	I Depth() const;								// The (depth) number of rows in the lattice


	// Operators
	Lattice<V, I, NumberNodes>& operator = (const Lattice<V, I, NumberNodes>& source);
	Vector<V, I>& operator [] (const I& nLevel );				// Subscripting operator
	const Vector<V, I>& operator [] (const I& nLevel ) const;				// Subscripting operator

	// We need the form of the lattice at the 'base' of the pyramid. This
	// will be needed when we use backward induction 
	Vector<V, I> BasePyramidVector() const;
	I BasePyramidSize() const;					// The number of discrete points at end
	I numberNodes() const;						// Total number of mesh points
};

#endif	