//
//  main.cpp
//  Exercise 4
//
//  Created by Changheng Chen on 1/19/17.
//  Copyright © 2017 Changheng Chen. All rights reserved.
//

#include "Line.hpp"
#include "Circle.hpp"
#include <iostream>
using namespace chako::CAD;

int main()
{
    /* What implementation did you give the Draw() function in Shape?
       Draw() in Shape has no implementation, and is a PVMF.
       Try to create an instance of the Shape class. Is this possible?
       No, Shape is an ABC as it has a PVMF, and it cannot be instantiated. 
     */
    
    Shape* shapes[10];
    
    shapes[0] = new Point;                                  // Default constructor
    shapes[1] = new Point(1.0);                             // Constructor with equal coordinates
    shapes[2] = new Point(3.0, 4.0);                        // Constructor with two coordinates
    shapes[3] = new Point(Point(0.0));                      // Copy constructor
    shapes[4] = new Line;                                   // Default constructor
    shapes[5] = new Line(Point(1.0, 2.5), Point(3.4, 5.2)); // Constructor 
    shapes[6] = new Line(Line());                           // Copy constructor
    shapes[7] = new Circle;                                 // Default constructor
    shapes[8] = new Circle(Point(), 1.0);                   // Constructor
    shapes[9] = new Circle(Circle());                       // Copy constructor
    
    for (int i=0; i!=10; i++)
    {
        shapes[i]->Draw();                                  // PVMF
        cout << shapes[i]->ToString() << endl << endl;
        delete shapes[i];
    }

    return 0;
}
