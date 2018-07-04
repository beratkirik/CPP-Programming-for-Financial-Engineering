//
//  main.cpp
//  Exercise 3
//
//  Created by Changheng Chen on 1/19/17.
//  Copyright © 2017 Changheng Chen. All rights reserved.
//

#include <iostream>
#include "Shape.hpp"
#include "Point.hpp"
#include "Line.hpp"
#include "Circle.hpp"
using namespace chako::CAD;

int main()
{ // TEST OF VIRTUAL DESTRUCTOR
    
    /* Creation order: the base data members are created and initialised,
    then the data members of the derived object are created after which the object exists.
     
    Destruction order: the derived class destructor gets called first,
    after which the destructor for the base part is called. */
    
    Shape* shapes[4];
    shapes[0] = new Shape;
    shapes[1] = new Point;
    shapes[2] = new Line;
    shapes[3] = new Circle;
    
    /* Creation order:
     
     0: Shape default constructor
     
     1: Shape default constructor, Point default constructor.
     
     2: Shape default constructor, 
        Shape default constructor, Point default constructor,  // 1st embedded Point object
        Shape default constructor, Point default constructor,  // 2nd embedded point object
        Line default constructor.
     
     3. Shape default constructor, 
        Shape default constructor, Point default constructor,  // the embedded Point object
        Circle default constructor.
     */
    
    for (int i=0; i!=4; i++)
        delete shapes[i];
    
    /* Destruction order:
     
       0: Shape destructor.
     
       1: Point destructor, Shape destructor.
     
       2: Line destructor,
          Point destructor, Shape destructor,  // 1st embedded Point object is destructed
          Point destructor, Shape destructor,  // 2nd embedded Point object is destructed
          Shape destructor.
     
       3: Circle destructor, 
          Point destructor, Shape destructor,  // the embedded Point object is destructed
          Shape destructor.
     */
    
    return 0;
}
