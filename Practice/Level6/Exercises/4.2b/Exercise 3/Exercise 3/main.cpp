//
//  main.cpp
//  Exercise 3
//
//  Created by Changheng Chen on 1/24/17.
//  Copyright © 2017 Changheng Chen. All rights reserved.
//

#include "PointArray.hpp"
using namespace chako::CAD;
using namespace chako::Containers;

int main()
{
    // (0) Create sample Point arrays
    PointArray parr1;         // Default constructor
    PointArray parr2(12);     // Constructor with array size
    PointArray parr3(parr2);  // Copy constructor
    PointArray parr4(10);     // Consructor with a different input size

    
    // (1) Check if DefaultSize() == Size()
    cout << "Default size of parr1: " << parr1.DefaultSize() << endl;
    cout << "Size of parr1: " << parr1.Size() << "\n\n";
    
    
    // (2) Assign arbitrary values to parr1 and parr2
    for (int i = 0; i < parr1.Size(); i++)
    {
        parr1[i] = Point((random() % 10)/2.0,(random() % 10)/2.0); // Generate pseudo-random points
        parr2[i] = Point((random() % 10)/2.0,(random() % 10)/2.0); // Generate pseudo-random points
    }
    
    
    // (3) Test assignment operator = ()
    parr3 = parr1;  // Assign parr1 to parr3
    
    cout << "Testing operator = ()..." << endl;
    for (int i = 0; i < parr3.Size(); i++)
    {
        if (parr1[i] == parr3[i])
            cout << "parr1[i] = parr3[i] = " << parr1[i] << endl;  // Print Point if parr1[i]==parr3[i]
    }
    cout << endl;
    
    
    // (4) Test function Length()
    cout << "Total length of the points in parr1: " << parr1.Length() << endl;
    cout << "Total length of the points in parr2: " << parr2.Length() << endl;
    cout << "Total length of the points in parr3: " << parr3.Length() << endl;
    cout << "Total length of the points in parr4: " << parr4.Length() << endl;
    cout << endl;
    
    
    // (5.1) Test Size Mismatch Exception catching
    try
    { // Assignment parr3 (size 12) to parr4 (size 10)
        
        cout << "Size of parr3: " << parr3.Size() << endl;
        cout << "Size of parr4: " << parr4.Size() << endl;
        parr4 = parr3;
    }
    catch (ArrayException& ex)
    {
        cout << ex.GetMessage() << endl;
    }
    catch (...)
    {
        cout << "An unhandled exception has occurred..." << endl;
    }
    
    // (5.2) Test Total Length Exception catching
    PointArray parr5(1);    // Create a Point array with size 1
    try
    {
        cout << parr5.Length() << endl;
    }
    catch (ArrayException& ex)
    {
        cout << ex.GetMessage() << endl;
    }
    catch (...)
    {
        cout << "An unhandled exception has occurred..." << endl;
    }
    
    return 0;
}
