// Vector.hpp
//
// Vector class is an array with mathematical functions.
//
// (C) Datasim Component Technology 1999-2006

#ifndef Vector_hpp
#define Vector_hpp

#include "UtilitiesDJD/VectorsAndMatrices/Array.cpp"

// Default structure is FullArray with default allocator. Default integral type is int.
template <class V, class I=int, class S=FullArray<V> >
class Vector: public Array<V, I, S>
{
private:
public:
	// Constructors & destructor
	Vector();									// Default constructor
	Vector(I size);						// Constructor with size. Start index=1.
	Vector(I size, I start);				// Constructor with size & start index
	Vector(I size, I start, const V& val);	// Constructor with size & start index + value
	Vector(const Vector<V, I, S>& source);		// Copy constructor
	Vector(const Array<V, I, S>& source);		// Copy with an array as argument
	virtual ~Vector();							// Destructor


	// Return the sum of the elements
	// Operators
	Vector<V, I, S>& operator = (const Vector<V, I, S>& source);

	Vector<V, I, S> operator - () const;		// Unary minus

	template <class V, class I, class S>
	friend Vector<V, I, S> operator + (const Vector<V, I, S>& v,const V& a);	// Add v to every element

	template <class V, class I, class S>
	friend Vector<V, I, S> operator + (const V& a,	const Vector<V, I, S>& v);

	template <class V, class I, class S>
	friend Vector<V, I, S> operator - (const Vector<V, I, S>& v, const V& a);	// Subtract v from every element

	template <class V, class I, class S>
	friend Vector<V, I, S> operator - (const V& a,	const Vector<V, I, S>& v);

	template <class V, class I, class S>
	friend Vector<V, I, S> operator * (const Vector<V, I, S>& v, 
										const V& a);	// Multiply every element by v

	template <class V, class I, class S>
	friend Vector<V, I, S> operator * (const V& a,	const Vector<V, I, S>& v);

	Vector<V, I, S> operator / (const V& a) const;	// Divide every element by a
	
	Vector<V, I, S> operator + (const Vector<V, I, S>& v) const;	// Add the elements
	Vector<V, I, S> operator - (const Vector<V, I, S>& v) const;	// Subtract the elements
	Vector<V, I, S> operator * (const Vector<V, I, S>& v) const;	// Multiply the elements
	Vector<V, I, S> operator / (const Vector<V, I, S>& v) const;	// Divide the elements

	Vector<V, I, S>& operator += (const V& v);	// Add v to every element
	Vector<V, I, S>& operator -= (const V& v);	// Subtract v from every element
	Vector<V, I, S>& operator *= (const V& v);	// Multiply every element by v
	Vector<V, I, S>& operator /= (const V& v);	// Divide every element by v

	Vector<V, I, S>& operator += (const Vector<V, I, S>& v);// Add the elements
	Vector<V, I, S>& operator -= (const Vector<V, I, S>& v);// Subtract the elements
	Vector<V, I, S>& operator *= (const Vector<V, I, S>& v);// Multiply the elements
};

// Some 'command' type functions that are useful in some applications. Most functions
// are void and this promotes Efficiency. Usability is also enhanced. 
// 

template <class V, class I> void scale(Vector<V,I>& v, const V& a); // v * a
template <class V, class I> void scale(const V& a, Vector<V,I>& v); // a * v

template <class V, class I> void add(Vector<V,I>& v, const V& a); // v + a
template <class V, class I> void add(const V& a, Vector<V,I>& v); // a + v

template <class V, class I> void 
			scaleAndOffset(Vector<V,I>& v, const V& a, const V& b); // (a * v) + b	

template <class V, class I> void subtract(Vector<V,I>& v, const V& a); // v - a
template <class V, class I> void subtract(const V& a, Vector<V,I>& v); // a - v

template <class V, class I> void divide(Vector<V,I>& v, const V& a); // v / a

template <class V, class I> void toggleSign(Vector<V,I>& v); // -v (unary minus)


template <class V, class I> void assign(Vector<V,I>& v, const V& RHS); // All elements = RHS






#endif	// Vector_hpp