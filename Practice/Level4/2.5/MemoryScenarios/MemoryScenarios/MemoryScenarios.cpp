//
//  MemoryScenarios.cpp
//
//  Lifecycle management on the heap. Normal scenarios.
//
//  Some exceptions:
//
//       1. No memory allocated for a ptr
//       2. Accessing null/undefined ptr
//       3. Ptr goes out of scope but pointee (memory has been cleaned up)
//       4. 'Double' delete
//
//  Created by Changheng Chen on 1/5/17.
//  Copyright © 2017 Changheng Chen. All rights reserved.
//

#include <iostream>
using namespace std;

struct A
{ // Simple class, struct members are public by definition
    
    int k;
    
    // Note colon syntax in constructors!!!!!
    A(int val = 0): k(val) {}
    A(const A& source) : k(source.k + 2) {}
    
    ~A() {cout << "Bye object of class A, value: " << k << endl;}
};


int main()
{
    {
        A* a = new A();
        delete a;
    }
    cout << "Phase 1\n";
    
    {
        A* a = new A();
        // delete a;    // if not deleted, memory leaks
    }
    cout << "Phase 2\n";
    
    {
        A* a = new A();
        delete a;
        // delete a;  // RT error
    }
    cout << "Phase 3\n";
    
    
    // Arrays
    {
        int N = 4;
        A* arr = new A[N];
        delete [] arr;
    }
    cout << "Phase 4A\n";
    
    {
        int N = 20;
        A* arr = new A[N];
        // delete [] arr;
    }
    cout << "Phase 4B\n";
    
    {
        A* a = new A();
        A* b = a;          // no memory involved, just stack pointers a and b
        delete a;          // only one object is created
        //delete b;
    }
    cout << "Phase 7\n";
    
    {
        A* a = new A(1);
        A b(*a);           // b is a normal object, created with copy constructor
        delete a;
        cout << b.k << endl; // b.k = 3!!!!
    }
    cout << "Phase 8\n";
    
    {
        A* a = new A();
        A b(*a);
        // delete a;
        cout << b.k << endl; // b is normal object, and b.k = 2!!!!
    }
    cout << "Phase 9\n";
    
    {
        A* a = new A();
        A* b = a;          // two pointers
        // delete a;
    }
    cout << "Phase 10\n";
    
    
    
    // A SIMPLE TEST
    int* pi;
    
    pi = NULL;
    pi = new int;
    *pi = 100;
    cout << *pi << endl;   // dereference it
    // pi = NULL;
    
    delete pi;
    
    return 0;
}
