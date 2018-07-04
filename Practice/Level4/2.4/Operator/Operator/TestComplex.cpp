//
//  TestComplex.cpp
//  Operator
//
//  Created by Changheng Chen on 12/15/16.
//  Copyright © 2016 Changheng Chen. All rights reserved.
//

#include "Complex.hpp"
#include <iostream>
using namespace std;

int main()
{
    /* int size=3; int* a=new int[size];
    for (int i=0; i<size; i++) a[i]=10-i;
    std::cout<<a[1]<<", "<<*a<<", "<<(a+1)[0]<<", "<<*a+1<<std::endl;
    delete[] a; */
    
    
    /*Which of the options below is the best operator declaration to add and assign two objects of type Complex (Complex+=Complex)?

    Complex& operator += (const Complex& c); */
    
    /* Which of the options below is the best operator declaration to add a two objects of type Complex (Complex+Complex)?
     
         Complex operator + (const Complex& c) const; */
    
    /*  Friend functions can access the 'this' pointer. WRONG!!! */
    
    
    Complex z1(-23.0, 5.3);
    Complex z2(2.0, 3.0);
    
    z2 = z1;
    
    z2 += 10.0;
    
    z2 = z1 + z2 * 10.0;
    
    cout << z1 << z2 << endl;  // operator precedence rules are the same
    
    /* z2 = mpi(z2);
    cout << z2 << endl << endl;
    
    Complex z3 = z1 * z2;
    z3 = z2 + z1 * 2.0;
    Complex z4 = 2.0 * z3; // 2.0 * z4 is uninitialzed when used within its own initialization
    Complex z5 = - z3;
    
    cout << z1;
    cout << z3;
    cout << z5; cout << "****\n";
    
    Complex z6 = z2 * 2.0;
    Complex z7 = 2.0 * z2;
    Complex z8 = z2 * 2.0;
    Complex z9 = z6 * z7;
    
    cout << z6;
    cout << z7;
    cout << z8; cout << "****\n";
    
    Complex z10 = z1.add(z2);  // z1 + z2
    cout << z10;
    
    Complex z0(1.0, 2.0);
    z4 = z3 = z1 = z0;         // Reference!!!
    cout << "Chain: \n" << z0 << z1 << z3 << z4;
    
    z4 += z1;                  // Add z4 by z1 and modify it
    cout << z4;
    
    cout << "modulus: " << mod(z4) << endl; */
    
    return 0;
}
