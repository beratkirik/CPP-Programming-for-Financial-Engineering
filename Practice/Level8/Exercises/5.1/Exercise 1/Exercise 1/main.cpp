//
//  main.cpp
//  Exercise 1
//
//  Created by Changheng Chen on 2/9/17.
//  Copyright © 2017 Changheng Chen. All rights reserved.
//

#include <boost/shared_ptr.hpp>
#include "Array.hpp"
#include "Line.hpp"
#include "Circle.hpp"

using namespace chako::CAD;
using namespace chako::Containers;

int main()
{
    // Typedefs for a shared pointer to shape and for an array of shared pointers to shape
    typedef boost::shared_ptr<Shape> ShapePtr;
    typedef Array<ShapePtr> ShapeArray;
    
    // Create an array of N shared pointers to shapes
    int N = 3;
    ShapeArray shapes1(N);
    
    // Create shared pointers to Point, Line, and Circle
    ShapePtr p(new Point(3.0, 4.0));                // Point
    ShapePtr l(new Line(Point(), Point(3.0, 4.0))); // Line
    ShapePtr c(new Circle(Point(), 1.0));           // Circle
    
    /* The 3 unnamed temporary Point objects for creating 'l' and 'c' are destroyed. */

    // Fill the array with the defined shared pointers
    shapes1[0] = p;
    shapes1[1] = l;
    shapes1[2] = c;
    
    // Print the shapes
    cout << endl;
    for (int i = 0; i < N; ++i)
        cout << (*shapes1[i]).ToString() << endl;

    cout << endl; // Deletion of the shapes will be done automatically after printing...
    
    /* The Shape objects along with their embedded objects are destroyed automatically. 
       And array 'shapes' is destroyed by the Array destructor (delete [] m_data;). */

    return 0;
}
