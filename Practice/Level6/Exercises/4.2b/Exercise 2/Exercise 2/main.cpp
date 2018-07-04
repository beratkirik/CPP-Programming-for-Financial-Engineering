//
//  main.cpp
//  Exercise 2
//
//  Created by Changheng Chen on 1/24/17.
//  Copyright © 2017 Changheng Chen. All rights reserved.
//

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstdlib>
#include "NumericArray.hpp"
#include "Point.hpp"
using namespace chako::CAD;
using namespace chako::Containers;
using namespace std;

int main()
{
    /* What assumptions do you make about the type used as template argument?
       The class template 'template <typename T> class NumericArray' can only be instantiated as classes
       of numeric data types.
     
       Can you create a numeric array with Point objects?
       NumericArray is supposed to support numeric data types, and errors may occur if numeric operations
       are performed on Point objects, such as (Point * Point) operation.
    */
    
    
    // (0) Create sample numeric arrays
    NumericArray<int> intArray1;                     // Default constructor
    NumericArray<int> intArray2(12);                 // Constructor with array size
    NumericArray<int> intArray3(intArray2);          // Copy constructor
    NumericArray<int> intArray4(10);                 // Consructor with a different input size
    
    
    // (1) Check if DefaultSize() == Size()
    cout << "Default size of intArray1: " << intArray1.DefaultSize() << endl;
    cout << "Size of intArray1: " << intArray1.Size() << "\n\n";
    
    
    // (2) Assign arbitrary values to intArray1 and intArray2
    cout << "intArray1[i] + intArray2[i] = ?\n";     // List the sum of intArray1[i] and intArray2[i]
    for (int i=0; i<intArray1.Size(); i++)
    {
        intArray1[i] = random() % 10;                // Generate a pseudo-random number between 0 and 9
        intArray2[i] = random() % 10;                // Generate a pseudo-random number between 0 and 9
        
        cout << setw(7) << intArray1[i] << setw(8)
        << " + " << setw(6) << intArray2[i] << setw(9)
        << " = " << intArray1[i] + intArray2[i] << endl;
    }
    cout << endl;
    
    
    // (3) Test operator overloading: operator = () and perator + ()
    intArray3 = intArray1 + intArray2;               // Add intArray1 and intArray2, assign to intArray3
    intArray1 = intArray3;                           // Assign intArray3 to intArray1

    cout << "Testing operator + () and operator = ()..." << endl;
    cout << "intArray1[i]  intArray3[i]" << endl;
    for (int i=0; i<intArray3.Size(); i++)
    {
        cout << setw(7) << intArray1[i]              // Check if intArray1[i] = intArray3[i]
        << setw(14) << intArray3[i] << endl;
    }
    cout << endl;

    
    // (4) Test global operator overloading: operator * ()
    cout << "Testing operator * ()..." << endl;
    
    intArray2 = 6.0 * intArray3;                     // Switch order of operand
    intArray2 = intArray2 * 0.5;                     // Scale intArray3 by 3 and assign it to intArray2
    
    cout << "intArray2[i]  3 * intArray3[i]" << endl;
    for (int i=0; i<intArray3.Size(); i++)
    {
        cout << setw(7) << intArray2[i]              // Check if intArray2[i] = 3*intArray3[i]
        << setw(14) << 3 * intArray3[i] << endl;
    }
    cout << endl;
    
    
    // (5) Test function DotProduct()
    cout << "Testing DotProduct()..." << endl;
    int dot_prod = intArray2.DotProduct(intArray3);  // Take dot product of intArray2 and intArray3
    cout << "Dot product of intArray2 and intArray3: " << dot_prod << endl << endl;
    
    
    // (6.1) Test Out of Bounds Exception catching
    try
    {
        cout << intArray1[-1] << endl;
    }
    catch (ArrayException& ex)                       // Catch exception object
    {
        cout << ex.GetMessage() << endl;             // Print the error message
    }
    catch(...)
    {
        cout << "An unhandled exception has occurred..." << endl;
    }
    
    // (6.2) Test Size Mismatch Exception catching
    try
    {
        cout << "Size of intArray3: " << intArray3.Size() << endl;
        cout << "Size of intArray4: " << intArray4.Size() << endl;
        intArray4 = intArray3;
    }
    catch (ArrayException& ex)                       // Catch exception object
    {
        cout << ex.GetMessage() << endl;             // Print the error message
    }
    catch(...)
    {
        cout << "An unhandled exception has occurred..." << endl;
    }
    
    
    // (7) Try to create numeric arrays with Point objects and do some tests
    NumericArray<Point> pts1;                        // Default constructor
    NumericArray<Point> pts2(12);                    // Constructor with size
    NumericArray<Point> pts3(pts1);                  // Copy constructor
    NumericArray<Point> pts4(14);                    // Constructor with a different size
    
    cout << "Size of pts1: " << pts1.Size() << endl; // Check size of pts1: default size
    cout << "pts3[10]: " << pts3[10] << endl;        // Element of array from copy constructor
    
    pts2 = pts1 * 2;                                 // OK, Point has operator * () defined
    pts2 = pts1 + pts2;                              // OK, Point has operator + () defined
    //Point p = pts1.DotProduct(pts2);               // NOT OK, Point * Point operation does not exist
    //cout << p << endl;
     
    return 0;
}
