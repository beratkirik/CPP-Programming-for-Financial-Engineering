//
//  TestLine.cpp
//  Exercise 5
//
//  Created by Changheng Chen on 12/8/16.
//  Copyright © 2016 Changheng Chen. All rights reserved.
//

#include "Point.hpp"
#include "Line.hpp"
#include <iostream>

int main()
{
    // Test line default constructor first
    Line l0;  // Point default constructor is called twice here...
    cout << l0.ToString() << endl;
    cout << endl;
    
    // Define 2 arbitrary points
    Point p1;
    Point p2(1.0,1.0);
    
    // Assign p1 and p2 to l to form a line
    Line l(p1,p2);   // Point copy constructor is called twice here...
    cout << endl;
    
    // Describe line using function ToString()
    cout << l.ToString() << endl;
    cout << endl;
    
    // Calculate line length using function Length()
    cout << "Line Length: " << l.Length() << endl;
    cout << endl;
    
    // Calculate line middle point using function midPoint()
    Point mPoint = l.midPoint();
    cout << "Line middle point: " << mPoint.ToString() << endl;
    cout << endl;
    
    return 0;
}
