//
//  TestRegularPointer.cpp
//  Exercise 1
//
//  Created by Changheng Chen on 3/3/17.
//  Copyright © 2017 Changheng Chen. All rights reserved.
//

#include <boost/shared_ptr.hpp>
#include "Array.hpp"
#include "Shape.hpp"
#include "Point.hpp"
#include "Line.hpp"
#include "Circle.hpp"
#include <iostream>

using namespace chako::CAD;
using namespace chako::Containers;

int main()
{
    //================================ REGULAR POINTERS ================================
    
    // Create an array of N pointers to shape
    int N = 3;
    Array<Shape*> shapes2(N);
    //Shape* shapes2[N];
    
    // Fill the array with Shape pointers
    shapes2[0] = new Point(3.0, 4.0);                 // Point
    shapes2[1] = new Line(Point(), Point(3.0, 4.0));  // Line
    shapes2[2] = new Circle(Point(), 1.0);            // Circle
    
    /* The 3 unnamed temporary Point objects for creating
     the Line and Circle objects above are destroyed. */
    
    // Print the shapes
    for (int i = 0; i != N; i++)
        cout << shapes2[i]->ToString() << endl;
    
    // Destroy the pointers
    for (int i = 0; i != N; i++)
        delete shapes2[i];
    
    /* The array object shapes2 is destroyed by the explicitly defined Array destructor:
     delete [] m_data; */
    
    /*N = 10;
     Point *pp;
     pp = new Point[N];
     cout << pp[0];
     delete [] pp;*/
}
