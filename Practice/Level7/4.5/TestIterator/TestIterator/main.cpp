//
//  main.cpp
//  TestIterator
//
//  Test of iterators using the 'find' algorithm:
//
//      1. Ordinary pointers
//      2. List iterators
//      3. istream iterators (read values from a standard input stream). This uses
//      ptrdiff_t in stddf.h for subtracting two pointers.
//
//  Created by Changheng Chen on 2/5/17.
//  Copyright © 2017 Changheng Chen. All rights reserved.
//

#include <list>
#include <iostream>
using namespace std;

void print(const list<int>& myList)
{
    //list<int>::iterator i; // does not compile
    list<int>::const_iterator i;
    
    for (i = myList.begin(); i != myList.end(); ++i)
    {
        cout << *i << ",";
    }
    cout << endl;
}

int main()
{
    
    int a[10] = {12, 3, 25, 7, 11, 213, 7, 123, 29, -31};
    
    
    // List iterator
    list<int> list1;
    for (int i = 0; i < 10; i++)
    {
        list1.push_back(a[i]);
    }
    print(list1);
    
    
    return 0;
}
