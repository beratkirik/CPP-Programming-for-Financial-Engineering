// FullArray.hpp
//
// Template class for a full (non-sparse) arrays.
//
// (C) Datasim Component Technology 1999

#ifndef FullArray_hpp
#define FullArray_hpp

// Use the STL vector class
#include <vector>
#include "UtilitiesDJD/VectorsAndMatrices/ArrayStructure.cpp"


template <class V, class TA=std::allocator<V> >
							class FullArray: public ArrayStructure<V>
{
private:
	std::vector<V, TA> m_vector;								// Use STL vector class for storage

public:
	// Constructors & destructor
	FullArray();											
	FullArray(size_t size);									
	FullArray(const FullArray<V, TA>& source);				
	virtual ~FullArray();									

	// Selectors
	virtual size_t Size() const;

	// Modifiers

	// Operators
	V& operator[] (size_t index);							
	const V& operator[] (size_t index) const;				

	FullArray<V, TA>& operator = (const FullArray<V, TA>& source);
};


#endif	// DSFullArray_hpp