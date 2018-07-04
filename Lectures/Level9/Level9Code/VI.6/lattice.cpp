// Lattice.cpp
//
// Class respresenting a special kind of triangular matrix that is
// needed in specific applications, for example binomial and trinomial 
// methods in options pricing.
//
// The matrix is 'expanding' in the form of a lattice; the user must define a function
// that states how many elements to create in moving from step 'n' to step 'n+1'.
//
// Last modification dates:
//
//	2001-4-23 DD kick-off date
//	2005-1-3 DD new template form; can combine binomial and trinomial
//  methods into 1 class
//	2005-1-4 DD improved, optimised code
//	2005-11-2 DD testing etc.
//
// (C) Datasim Component Technology 2001-2006


#ifndef Lattice_cpp
#define Lattice_cpp


#include "Lattice.hpp"


// Constructors & destructor
template <class V, class I, int NumberNodes> Lattice< V, I, NumberNodes>::Lattice()
{ // Default constructor

		tree = Array<Vector<V, I> > (1, 1); // A flat matrix with 1 row in array
											// Start index == 1
		tree[1] = Vector<V, I> (1,1);
		typ = 2;							// Binomial method

}


template <class V, class I, int NumberNodes> Lattice< V, I, NumberNodes>::Lattice(const I& Nrows)
{ // Number of rows and branch factor


	nrows = Nrows;
	typ = NumberNodes;

	tree = Array<Vector<V, I>, I> (Nrows + 1, 1); // Start index == 1

	I currentBranch = 1;	// There is always one single root

	// Initialise tree vectors (give sizes of vectors)
	for(int n = tree.MinIndex(); n <= tree.MaxIndex(); n++)
	{
		tree[n] = 	Vector<V, I>(currentBranch,1);	

		// Calculate the next number of columns

		currentBranch += (typ - 1);
	}

}

template <class V, class I, int NumberNodes> Lattice< V, I, NumberNodes>::Lattice(const I& Nrows, const V& val)
{ // Number of rows and branch factor


	nrows = Nrows;
	typ = NumberNodes;

	tree = Array<Vector<V, I>, I> (nrows + 1, 1); // Start index == 1

	I currentBranch = 1;	// There is always one single root

	// Initialise tree vectors (give sizes of vectors)
	for(int n = tree.MinIndex(); n <= tree.MaxIndex(); n++)
	{
		tree[n] = 	Vector<V, I>(currentBranch, 1, val);	

		// Calculate the next number of columns

		currentBranch += (typ - 1);
	}

}


template <class V, class I, int NumberNodes> Lattice<V, I, NumberNodes>::Lattice(const Lattice<V, I, NumberNodes>& source)
{ // Copy constructor

	tree = source.tree;
	typ = source.typ;
	nrows = source.nrows;
}

template <class V, class I, int NumberNodes> Lattice<V, I, NumberNodes>::~Lattice()
{ // Destructor

}


// Operators
template <class V, class I, int NumberNodes> Lattice<V, I, NumberNodes>& Lattice< V, I, NumberNodes>::operator = (const Lattice<V, I, NumberNodes>& source)
{

	if (this == &source)
		return *this;

	tree = source.tree;
	typ = source.typ;
	nrows = source.nrows;

	return *this;
}


// Iterating in a Lattice; we need forward and backward versions
template <class V, class I, int NumberNodes> I Lattice< V, I, NumberNodes>::MinIndex() const
{ // Return the minimum row index

	return tree.MinIndex();
}

template <class V, class I, int NumberNodes> I Lattice<V, I, NumberNodes>::MaxIndex() const
{ // Return the maximum row index

	return tree.MaxIndex();

}



template <class V, class I, int NumberNodes> I Lattice<V, I, NumberNodes>::Depth() const
{ // The (depth) number of rows in the lattice

	return tree.Size();
}



template <class V, class I, int NumberNodes>
Vector<V, I>& Lattice<V, I, NumberNodes>::operator [] (const I& nLevel)
{ // Subscripting operator

	return tree[nLevel];
}

template <class V, class I, int NumberNodes>
const Vector<V, I>& Lattice<V, I, NumberNodes>::operator [] (const I& nLevel) const
{ // Subscripting operator

	return tree[nLevel];
}


// We need the form of the lattice at the 'base' of the pyramid. This
// will be needed when we use backward induction 
template <class V, class I, int NumberNodes>
Vector<V, I> Lattice<V, I, NumberNodes>::BasePyramidVector() const
{

	return tree[tree.MaxIndex()];
}

template <class V, class I, int NumberNodes>
I Lattice<V, I, NumberNodes>::BasePyramidSize() const
{ // The number of discrete points at end

	// This is a sequence
	return 1 + nrows *(typ - 1);
}

template <class V, class I, int NumberNodes>
I Lattice<V, I, NumberNodes>::numberNodes() const
{ // The number of discrete points at end

	// Summation (Series)
	double tmp2 = double(nrows * (nrows + 1)) / 2.0;

	return 1 + nrows + (typ -1 ) * I(tmp2);
}

#endif
