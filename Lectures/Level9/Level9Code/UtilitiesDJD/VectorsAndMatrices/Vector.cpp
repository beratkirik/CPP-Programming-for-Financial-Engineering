// Vector.cpp
//
// Vector class is an array with mathematical functions
//
// 29 january 1999	RD	Started
// 2002-1-21 DD removed some special functions; delta, gamma etc.
// 2004-3-13 DD new 'Command' non-memebr functions
// 2004-4-14 DD Maths operators +, -, * are now friends
// 2005-12-17 DD size_t --> I
// 2006-1-13 DD Damn it A BUG!!!!!!!!!!!!! was testing FDM from chapter 19
// 2006-2-2 DD all friend members (e.g. operators) must have the template 
// specification otherwise it is not correct C++.
// 2007-12-20 Extra bracket ')' removed that caused a compiler error
/*
template <class V, class I, class S>
Vector<V, I, S> Vector<V, I, S>::operator - () const
{ // Unary minus

	// Create new vector of same size and same starting index
	Vector<V, I, S> result(Size(), MinIndex());

	// Copy all elements negative
	for (I i=MinIndex(); i<=MaxIndex(); i++) 
	/// BUG BUG DAMN IT	result[i] = - result[i];
	result[i] = - (*this)[i];

	// Return result
	return result;
}*/


// (C) Datasim Component Technology 1999-2006

#ifndef Vector_CPP
#define Vector_CPP

#include "UtilitiesDJD/VectorsAndMatrices/Vector.hpp"


// Constructors & destructor
template <class V, class I, class S>
Vector<V, I, S>::Vector(): Array<V, I, S>()
{ // Default constructor
}

template <class V, class I, class S>
Vector<V, I, S>::Vector(I size): Array<V, I, S>(size)
{ // Constructor with size. Start index=1.
}

template <class V, class I, class S>
Vector<V, I, S>::Vector(I size, I start): Array<V, I, S>(size, start)
{ // Constructor with size & start index
}

template <class V, class I, class S>
Vector<V, I, S>::Vector(I size, I start, const V& val): Array<V, I, S>(size, start, val)
{ // Constructor with size & start index

	
}


template <class V, class I, class S>
Vector<V, I, S>::Vector(const Vector<V, I, S>& source): Array<V, I, S>(source)
{ // Copy constructor
}

template <class V, class I, class S>
Vector<V, I, S>::Vector(const Array<V, I, S>& source): Array<V, I, S>(source)
{ // Constructor with a Array
}

template <class V, class I, class S>
Vector<V, I, S>::~Vector()
{ // Destructor
}


// Modifiers
// Operators
template <class V, class I, class S>
Vector<V, I, S>& Vector<V, I, S>::operator = (const Vector<V, I, S>& source)
{ // Assignment operator

	// Exit if same object
	if (this==&source) return *this;

	// Call baseclass assignment
	Array<V, I, S>::operator = (source);

	return *this;
}

template <class V, class I, class S>
Vector<V, I, S> Vector<V, I, S>::operator - () const
{ // Unary minus

	// Create new vector of same size and same starting index
	Vector<V, I, S> result(Size(), MinIndex());

	// Copy all elements negative
	for (I i=MinIndex(); i<=MaxIndex(); i++) 
	/// BUG BUG DAMN IT	result[i] = - result[i];
	result[i] = - (*this)[i];

	// Return result
	return result;
}

template <class V, class I, class S>
Vector<V, I, S> operator + (const Vector<V, I, S>& v, const V& a)
{ // Add v to every element

	// Create new vector of same size and same starting index
	Vector<V, I, S> result(v.Size(), v.MinIndex());

	// Copy all elements + v
	for (I i = v.MinIndex(); i <= v.MaxIndex(); i++) 
		result[i] = v[i] + a;

	// Return result
	return result;
}


template <class V, class I, class S>
Vector<V, I, S> operator + (const V& a, const Vector<V, I, S>& v)
{
	return v + a;
}

template <class V, class I, class S>
Vector<V, I, S> operator * (const Vector<V, I, S>& v, const V& a)
{ // Multiply to every element by a

	// Create new vector of same size and same starting index
	Vector<V, I, S> result(v.Size(), v.MinIndex());

	// Copy all elements + v
	for (I i = v.MinIndex(); i <= v.MaxIndex(); i++) 
		result[i] = v[i] * a;

	// Return result
	return result;
}

template <class V, class I, class S>
Vector<V, I, S> operator * (const V& a, const Vector<V, I, S>& v)
{
	return v * a;
}


template <class V, class I, class S>
Vector<V, I, S> operator - (const Vector<V, I, S>& v, const V& a)
{ // Subtract v from every element

	// Create new vector of same size and same starting index
	Vector<V, I, S> result(v.Size(), v.MinIndex());

	// Copy all elements - v
	for (I i = v.MinIndex(); i <= v.MaxIndex(); i++) 
		result[i] = v[i] - a;

	// Return result
	return result;
}

template <class V, class I, class S>
Vector<V, I, S> operator - (const V& a, const Vector<V, I, S>& v)
{
	// Create new vector of same size and same starting index
	Vector<V, I, S> result(v.Size(), v.MinIndex());

	// Copy all elements - v
	for (I i = v.MinIndex(); i <= v.MaxIndex(); i++) 
		result[i] = a - v[i];

	// Return result
	return result;

}

template <class V, class I, class S>
Vector<V, I, S> Vector<V, I, S>::operator / (const V& a) const
{ // Add v to every element

	// Create new vector of same size and same starting index
	Vector<V, I, S> result(Size(), MinIndex());

	// Copy all elements + v
	for (I i = MinIndex(); i <= MaxIndex(); i++) 
		result[i] = (*this)[i] / a;

	// Return result
	return result;
}


template <class V, class I, class S>
Vector<V, I, S> Vector<V, I, S>::operator + (const Vector<V, I, S>& v) const
{ // Add the elements


	// Create new vector of same size and same starting index
	Vector<V, I, S> result(Size(), MinIndex());

	// Result[x]=Source[x]+v[x];
	for (I i=MinIndex(); i<=MaxIndex(); i++) result[i] = (*this)[i] + v[i];

	// Return result
	return result;
}

template <class V, class I, class S>
Vector<V, I, S> Vector<V, I, S>::operator - (const Vector<V, I, S>& v) const
{ // Subtract the elements


	// Create new vector of same size and same starting index
	Vector<V, I, S> result(Size(), MinIndex());

	// Result[x]=Source[x]-v[x];
	for (I i=MinIndex(); i<=MaxIndex(); i++) result[i] = (*this)[i] - v[i];

	// Return result
	return result;
}

/* ERROR PAST 

template <class V, class I, class S>
Vector<V, I, S>& Vector<V, I, S>::operator -= (const Vector<V, I, S>& v)
{ // Subtract the elements


	for (I i=MinIndex(); i<=MaxIndex(); i++) 
			(*this)[i] = (*this)[i] - v[i]);
	;
	return *this;
};

template <class V, class I, class S>
Vector<V, I, S>& Vector<V, I, S>::operator *= (const Vector<V, I, S>& v)
{ // Multiply the elements


	for (I i=MinIndex(); i<=MaxIndex(); i++) 
		(*this)[i] = (*this)[i] * v[i]);
		
	return *this;
};

*/

template <class V, class I, class S>
Vector<V, I, S>& Vector<V, I, S>::operator += (const V& v)
{ // Add v to every element

	for (I i=MinIndex(); i<=MaxIndex(); i++)
		(*this)[i] = (*this)[i] + v;

	return *this;
}

template <class V, class I, class S>
Vector<V, I, S>& Vector<V, I, S>::operator -= (const V& v)
{ // Subtract v from every element

	for (I i=MinIndex(); i<=MaxIndex(); i++)
		(*this)[i] = (*this)[i] - v;

	return *this;
}

template <class V, class I, class S>
Vector<V, I, S>& Vector<V, I, S>::operator *= (const V& v)
{ // Multiply every element by v

	for (I i=MinIndex(); i<=MaxIndex(); i++) 
		(*this)[i] = (*this)[i] * v;

	return *this;
}

template <class V, class I, class S>
Vector<V, I, S>& Vector<V, I, S>::operator /= (const V& v)
{ // Divide every element by v

	for (I i=MinIndex(); i<=MaxIndex(); i++) 
		(*this)[i] = (*this)[i] / v;

	return *this;
}

template <class V, class I, class S>
Vector<V, I, S>& Vector<V, I, S>::operator += (const Vector<V, I, S>& v)
{ // Add the elements


	for (I i=MinIndex(); i<=MaxIndex(); i++) 
		(*this)[i] = (*this)[i] + v[i];

	return *this;
}

template <class V, class I, class S>
Vector<V, I, S>& Vector<V, I, S>::operator -= (const Vector<V, I, S>& v)
{ // Subtract the elements


	for (I i=MinIndex(); i<=MaxIndex(); i++) 
			(*this)[i] = (*this)[i] - v[i];

	return *this;
}

template <class V, class I, class S>
Vector<V, I, S>& Vector<V, I, S>::operator *= (const Vector<V, I, S>& v)
{ // Multiply the elements


	for (I i=MinIndex(); i<=MaxIndex(); i++) 
		(*this)[i] = (*this)[i] * v[i];
		
	return *this;
}




// Some 'command' type functions that are useful in some applications. Most functions
// are void and this promotes Efficiency. Usability is also enhanced. 
// 

template <class V, class I> void scale(Vector<V,I>& v, const V& a)
{ // v * a

	for (I i = v. MinIndex(); i <= v. MaxIndex(); i++)
	{
		v[i] *= a;
	}


}

template <class V, class I> void scale(const V& a, Vector<V,I>& v)
{ // a * v

	scale(v, a);
}


template <class V, class I> void add(Vector<V,I>& v, const V& a)
{ // v + a

	for (I i = v. MinIndex(); i <= v. MaxIndex(); i++)
	{
		v[i] += a;
	}

}


template <class V, class I> void add(const V& a, Vector<V,I>& v)
{ // a + v

	add(v, a);
}


template <class V, class I> void 
			scaleAndOffset(Vector<V,I>& v, const V& a, const V& b)
{ // (a * v) + b	

	for (I i = v. MinIndex(); i <= v. MaxIndex(); i++)
	{
		v[i] *= a;
		v[i] += b;
	}
}


template <class V, class I> void subtract(Vector<V,I>& v, const V& a)
{ // v - a

	for (I i = v. MinIndex(); i <= v. MaxIndex(); i++)
	{
		v[i] -= a;
	}
}

template <class V, class I> void subtract(const V& a, Vector<V,I>& v)
{ // a - v

	// This operation is not commutative, so redo the for loop

	for (I i = v. MinIndex(); i <= v. MaxIndex(); i++)
	{
		v[i] = a - v[i];
	}
	
}


template <class V, class I> void divide(Vector<V,I>& v, const V& a)
{ // v / a

	for (I i= v. MinIndex(); i <= v. MaxIndex(); i++)
	{
		v[i] /= a;
	}
}


template <class V, class I> void toggleSign(Vector<V,I>& v)
{ // -v (unary minus)

	for (I i = v. MinIndex(); i <= v. MaxIndex(); i++)
	{
		v[i] = -v[i];
	}
}

template <class V, class I> void assign(Vector<V,I>& v, const V& RHS)
{ // All elements = RHS

	for (I i = v. MinIndex(); i <= v. MaxIndex(); i++)
	{
		v[i] = RHS;
	}
}


#endif	// Vector_cpp