// ArrayStructure.hpp
//
// Base class for array storage structure.
// A size_t is used for indexing. Indexing starts at 1 in this class and its
// dervived classes. These derived classes must implement the indexing [] operator.
//
// (C) Datasim Component Technology 1999

#ifndef ArrayStructure_hpp
#define ArrayStructure_hpp

template <class V>
class ArrayStructure
{
public:
	// Constructors & destructor
	ArrayStructure();												// Default constructor
	ArrayStructure(const ArrayStructure<V>& source);				// Copy constructor
	virtual ~ArrayStructure();										// Destructor

	// Selectors
	virtual size_t Size() const=0;									// Size of the array
	const V& Element(size_t index) const;						// Get element at position

	size_t MinIndex() const;									// Return the minimum index == 1
	size_t MaxIndex() const;									// Return the maximum index == size

	// Modifiers
	void Element(size_t index, const V& val);					// Change element at position

	// Operators
	virtual V& operator[] (size_t index) = 0;			
	virtual const V& operator[] (size_t index) const = 0;

	ArrayStructure<V>& operator = (const ArrayStructure<V>& source);
};

#endif	// ArrayStructure_hpp    

