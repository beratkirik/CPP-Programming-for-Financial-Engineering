//
//  main.cpp
//  quiz2
//
//  Created by Changheng Chen on 3/14/17.
//  Copyright © 2017 Changheng Chen. All rights reserved.
//

#include <iostream>
using namespace std;

template<typename T>
void func(T value)
{
    const T& ref = value; // Declare a const reference to value
    T* p = new T;         // T* p; p = new T; // Default constructor is called
    T temp(23);           // Declare and define a new variable: int temp = 23;
    
    cout << temp << endl; // 23
    cout << *p << endl;   // 0, dereference *p = 0
    cout << p << ", " << value << ", " << ref << endl; // 0x100300330 (address #), 10, 10
}

int main()
{
    int d = 10;
    func<int>(d);
    
    return 0;
}
