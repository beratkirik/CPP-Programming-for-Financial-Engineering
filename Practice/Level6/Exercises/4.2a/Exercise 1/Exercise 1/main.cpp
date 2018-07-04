//
//  main.cpp
//  Exercise 1
//
//  Created by Changheng Chen on 1/23/17.
//  Copyright © 2017 Changheng Chen. All rights reserved.
//

#include <iostream>
//#include "Array.cpp" // Can #include "Array.hpp" instead if "Array.cpp" is included in "Array.hpp"
#include "Array.hpp"
#include "Line.hpp"
#include "Circle.hpp"
using namespace chako::CAD;
using namespace chako::Containers;

/*  Tip, by placing the following code at the end of the array header file, but before the header file’s #endif, the client can keep including the header file for template classes instead of the source file. Can you explain how this works?
 
    "Uninstanciated templates cannot be stored in an .o file for the linker. Thus when using a template class, the implementation of the template class must be known at compile-time, while with regular classes the implementation of the class can be linked later at link time from an .o file."
 
    Thus, to let the compiler have access to the implementation of the template, one can 1) include the template .cpp file in main.cpp file, or 2) include the template .cpp in the template .hpp file and then include the .hpp file in main.cpp. Therefore, the compiler will be able to instantiate the template and create .o files for linking at link time.
*/

int main()
{
    // (1) Create arrays of point, line, and circles
    int size(10);
    Array<Point> points(size);             // Create an array of points
    Array<Line> lines(size);               // Create an array of lines
    Array<Circle> circles(size);           // Create an array of circles
    
    
    // (2) Test some functions
    points[1].Draw();                      // Test PVMF Draw()
    cout << lines[3] << endl;              // Print the 4th element in lines
    cout << circles[6].ToString() << endl; // Call ToString()
    
    
    // (3) Set points elements here and there, and print the array
    Point p(3.0, 4.0);
    
    points[2] = p;
    points[4].X(2.0);
    points[4] *= 3.0;
    points[6].Y(-1.0);
    points[8] = -2.0 * points[2];
    
    cout << endl;
    for (int i=0; i<points.Size(); i++)
    {
        cout << i << "  " << points[i] << endl;
    }
    
    
    // (4) Test Exception catching
    try
    {
        cout << circles[10] << endl;       // Access an element out of bounds
    }
    catch (ArrayException& ex)             // Catch exception object
    {
        cout << endl << ex.GetMessage();   // Print the error message
    }
    catch(...)
    {
        cout << "An unhandled exception has occurred..." << endl;
    }
    
    return 0;
}
