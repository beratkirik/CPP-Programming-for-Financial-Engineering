// Point.hpp
//
// Header file for Points in two dimensions. A given Point has 3 coordinates
// for compatibility with other systems. However, it is not possible to
// influence the third coordinate and furthermore, the delivered functionality
// is typically two-dimensional.
//
// (C) Copyright Datasim BV 1995 - 2005

#ifndef Point_HPP
#define Point_HPP

#include <iostream>
using namespace std;



class Point
{
private:
	double x;	// X coordinate
	double y;	// Y coordinate

public:
	// Constructors
	Point();								// Default constructor
	Point(double xval, double yval);		// Initialize with x and y value
	
	~Point();

	// Accessing functions
	double X() const ;					// The x-coordinate
	void X(double newX);
	double Y() const;					// The y-coordinate
	void Y(double newY);

	friend ostream& operator << (ostream& os, const Point& pt);
};



#endif // Point_HPP
