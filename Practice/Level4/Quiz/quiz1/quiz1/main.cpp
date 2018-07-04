//
//  main.cpp
//  quiz1
//
//  Created by Changheng Chen on 3/14/17.
//  Copyright © 2017 Changheng Chen. All rights reserved.
//

#include <iostream>

// (2)
// The variable x is a global variable only accessible in the current compilation unit and not as external global variable in another compilation unit.
namespace
{
    int x=20;
}


int main()
{
    // (1)
    //This code implements the default constructor of class B that is in namespace A that is nested in another namespace A.
    //A::A::B::B() { }
    
    // (3)
    int size=3; int* a=new int[size];
    for (int i=0; i<size; i++) a[i]=10-i;  // 10, 9, 8
    std::cout<<a[1]<<", "<<*a<<", "<<(a+1)[0]<<", "<<*a+1<<std::endl; // 9, 10, 9, 11
    delete[] a;
    
    // (4)
    // The best operator declaration to add a two objects of type Complex (Complex+Complex)?
    // Complex operator + (const Complex& c) const;
    //
    // The best operator declaration to add and assign two objects of type Complex (Complex+=Complex)?
    // Complex& operator += (const Complex& c) const; //!!!!!!! xxx
    // Complex& operator += (const Complex& c); 
    //
    // The best operator declaration to add a double and a Complex object (double+Complex)?
    // friend Complex operator + (double d, const Complex& c);
    //
    // The best way to support the index operator for integer indices ([int])?
    // const Type& operator [] (int index) const; Type& operator [] (int index);
    //
    // The following declares and allocates an array of int pointers:
    // int** array=new int*[size];

    int** array;
    array = new int*[3];
    
    
    // (5)
    //MyClass* mc=new MyClass; // creates a single MyClass object on the heap (default constructor)
    
    
    /* (6)
     Which statement is false about friends?
     
     Friend functions can access the 'this' pointer. (FALSE)
     Friend functions can access the private members of the class they are friend of.
     A class cannot access the private members of its friend classes.
     Friends violate the information hiding principle of object-oriented programming.
     */
    
    
    /* (7) This code does not compile
    namespace A::B
    {
        class MyClass
        {
        };
    }
    */
    
    
    
    return 0;
}
