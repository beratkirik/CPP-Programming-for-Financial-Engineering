// MP Implementation of the Line segment .cpp

#include "LineSegment.hpp"
#include <cmath>

/*	LineSegment();																// Line with both end Points at the origin
	LineSegment(const Point& p1, const Point& p2);	// Line with end Points [p1, p2]
	LineSegment(const LineSegment& l); 							// Copy constructor
	virtual ~LineSegment();													// Destructor

	// Accesssing functions
	Point start() const;														// Synonym for startPoint
	Point end() const;															// Synonym for endPoint

	// Modifiers
	void start(const Point& pt);										// Set Point pt1
	void end(const Point& pt);											// Set Point pt2

	// Arithemetic
	double length() const;													// Length of line

	// Interaction with Points
	Point midPoint() const;	

	*/

LineSegment::LineSegment() 
{
	//!!!
}

LineSegment::~LineSegment()
{
	
}

LineSegment::LineSegment(const Point& p1, const Point& p2)
{
	startPoint=p1;
	endPoint=p2;
}

LineSegment::LineSegment(const LineSegment& l)
{
	startPoint=l.startPoint;
	endPoint=l.endPoint;
}

Point LineSegment::start() const
{
	return startPoint;
}

Point LineSegment::end() const
{
	return endPoint;
}

void LineSegment::start(const Point& pt)
{
	startPoint=pt;
}

void LineSegment::end(const Point& pt)
{
	endPoint=pt;
}

