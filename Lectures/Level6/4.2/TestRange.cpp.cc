// TestRange.cpp
//
// Program to test the Range class
//
// The examples are aimed at financial engineering applications
//
// (C) Datasim Education BV 2003-2011
//

#include "Range.cpp"
#include <iostream.h>

int main()
{
	
	// The default type is double
	double closingPrice (45.7);
	double openingPrice (60.0);
	Range<double> bearish (closingPrice, openingPrice);

	// Looking at some prices
	double currentPrice = 50.0;

	bool test1 = bearish.left(currentPrice);
	bool test2 = bearish.right(currentPrice);
	bool test3 = bearish.contains(currentPrice);
	
	if (test1 == false && test2 == false && test3 == true)
		cout << "Everything OK\n";

	// Create a range with float as underlying type
	float closingPriceII (90.0);
	float openingPriceII (60.0);
	Range<float> bulllish (closingPriceII, openingPriceII);


	return 0;
}
