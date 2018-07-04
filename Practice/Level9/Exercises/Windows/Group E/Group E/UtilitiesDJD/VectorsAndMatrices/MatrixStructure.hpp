// MatrixStructure.hpp
//
// Base class for matrix storage structure.
// A size_t is used for indexing. Indexing starts at 1.
//
// (C) Datasim Component Technology 1999

#ifndef MatrixStructure_hpp
#define MatrixStructure_hpp

#include "ArrayStructure.hpp"


template <class TValue>
class MatrixStructure
{
public:
	// Constructors & destructor
	MatrixStructure();												// Default constructor
	MatrixStructure(const MatrixStructure<TValue>& source);			// Copy constructor
	virtual ~MatrixStructure();										// Destructor

	// Selectors
	virtual size_t Rows() const=0;									// Number of rows
	virtual size_t Columns() const=0;								// Number of columns
	const TValue& Element(size_t row, size_t column) const;			// Get element at position

	size_t MinRowIndex() const;										// Return the minimum row index
	size_t MaxRowIndex() const;										// Return the maximum row index
	size_t MinColumnIndex() const;									// Return the minimum column index
	size_t MaxColumnIndex() const;									// Return the minimum column index

	// Modifiers
	void Element(size_t row, size_t column, const TValue& val);		// Change element at position

	// Operators
	virtual ArrayStructure<TValue>& operator[] (size_t index) = 0;					// Subscripting operator
	virtual const ArrayStructure<TValue>& operator[] (size_t index) const = 0;		// Subscripting operator

	const TValue& operator () (size_t row, size_t column) const;	// Get the element at position
	TValue& operator () (size_t row, size_t column);				// Get the element at position

	MatrixStructure<TValue>& operator = (const MatrixStructure<TValue>& source);
};



#endif	// MatrixStructure_hpp