//
//  ShapeVariantGenerator.hpp
//  Exercise 3
//
//  Created by Changheng Chen on 2/10/17.
//  Copyright © 2017 Changheng Chen. All rights reserved.
//

#ifndef ShapeVariantGenerator_hpp
#define ShapeVariantGenerator_hpp

#include <boost/variant.hpp>
#include "WrongShapeException.hpp"

// Typedef for a ShapeType variant
typedef boost::variant<Point, Line, Circle> ShapeType;

ShapeType ShapeVariant()
{
    // "Within this function ask the user for the shape type to create."

    ShapeType MyShape;
    
    string shape;
    cout << "Enter Point, Line, or Circle to create a shape: ";
    cin >> shape;
    
    if (shape == "Point" || shape == "point")
    {
        MyShape = Point();  // Default constructor
    }
    else if (shape == "Line" || shape == "line")
    {
        MyShape = Line();   // Default constructor
    }
    else if (shape == "Circle" || shape == "circle")
    {
        MyShape = Circle(); // Default constructor
    }
    else
    {
        throw WrongShapeException(shape);
    }
    
    return MyShape;
}

#endif /* ShapeVariantGenerator_hpp */
