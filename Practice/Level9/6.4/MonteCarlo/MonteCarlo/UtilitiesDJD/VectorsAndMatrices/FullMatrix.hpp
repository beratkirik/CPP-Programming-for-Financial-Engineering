// FullMatrix.hpp
//
// Template class for normal matrices.
// A size_t is used for indexing. Indexing starts at 1.
//
// (C) Datasim Component Technology 1999

#ifndef FullMatrix_hpp
#define FullMatrix_hpp

#include "UtilitiesDJD/VectorsAndMatrices/MatrixStructure.cpp"
#include "UtilitiesDJD/VectorsAndMatrices/FullArray.hpp"


template <class TValue, class TA=std::allocator<TValue> >
class FullMatrix: public MatrixStructure<TValue>
{
	FullArray<FullArray<TValue, TA>, std::allocator<FullArray<TValue, TA> > > m_structure;

	// Redundant data 
	size_t nr, nc;

public:
	// Constructors & destructor
	FullMatrix();													// Default constructor
	FullMatrix(size_t rows, size_t columns);						// Constructor with size
	FullMatrix(const FullMatrix<TValue, TA>& source);				// Copy constructor
	virtual ~FullMatrix();											// Destructor

	// Selectors
	virtual size_t Rows() const;									// Number of rows
	virtual size_t Columns() const;									// Number of columns

	// Modifiers

	// Operators
	virtual ArrayStructure<TValue>& operator[] (size_t index);					// Subscripting operator
	virtual const ArrayStructure<TValue>& operator[] (size_t index) const;		// Subscripting operator

	FullMatrix<TValue, TA>& operator = (const FullMatrix<TValue, TA>& source);
};



#endif	// FullMatrix_hpp