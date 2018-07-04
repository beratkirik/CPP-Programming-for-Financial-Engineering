// Point.cpp
//
// Header file for Points in two dimensions. A given Point has 3 coordinates
// for compatibility with other systems. However, it is not possible to
// influence the third coordinate and furthermore, the delivered functionality
// is typically two-dimensional.
//
// Last Modifications:
// chap04 AM Kick off
// chap05 AM Changed using const and reference
// chap05 AM Added copy constructor
// 2005-5-20 DD modified POINT -> Point
// 2008-10-12 DD remove a function
// 2009-1-11 DD distance fn.
//
// (C) Copyright Datasim BV 1995 - 2006

#include "Point.hpp"
#include <cmath>

Point::Point() : x(0), y(0) // Colon syntax!!!!!!!!!!!!!!!!!
{// Default constructor
	
//	x = y =0.0;
}

Point::Point(double newx, double newy) : x(newx), y(newy)
{// Initialize using newx and newy
	
/*	x = newx;
	y = newy;*/
}
Point::~Point()
{// Des...
	
	cout << "bye my point..\n";
}

double Point::X() const
{
	return x;
}

void Point::X(double newX)
{ 
	x = newX;
}


double Point::Y() const 
{
	return y;
}

void Point::Y(double newY)
{ 
	y = newY;
}