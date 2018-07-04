//
//  STL101.cpp
//  STL101
//
//  Examples to show how sequence containers (vector) work
//
//  Created by Changheng Chen on 1/23/17.
//  Copyright © 2017 Changheng Chen. All rights reserved.
//

#include <vector>
#include <list>
#include <string>
#include <iostream>
using namespace std;


template <class T>
void print(const vector<T>& vec)
{ // A generic print function for vectors
    
    cout << endl << "Size of vector is " << vec.size() << "\n[";
    
    // We must use a const iterator here, otherwise we get a complier error.
    typename vector<T>::const_iterator i;
    
    for (i = vec.begin(); i != vec.end(); ++i)
    {
        cout << *i << ",";
    }
    
    cout << "]\n";
}


int main()
{
    size_t n = 10;
    double val = 3.14;
    vector<double> vector2(n, val);  // Create n copies of val
    
    cout << "Size of vector2 " << vector2.size() << endl;
    
    // Access elements of the vector by using the indexing operator []
    // Change some values here and there
    vector2[0] = 2.0;
    vector2[1] = 456.76;
    
    int last_element = vector2.size() - 1.0;   // -1 vs -1.0
    vector2[last_element] = 55.66;
    
    print(vector2);
    
    vector2.reserve(1000);  // Reserve 1000 elements
    cout << "Size of vector2 " << vector2.size() << endl;
    cout << "Capacity: " << vector2.capacity() << endl;
    cout << "Hardware Capacity: " << vector2.max_size() << endl;
    
    vector2.clear();
    cout << "Size of vector2 " << vector2.size() << endl;  // Changes to 0
    cout << "Capcity: " << vector2.capacity() << endl;  // Does not change, still 1000
    cout << "Hardware Capcity: " << vector2.max_size() << endl;
    
    // Test list
    list<double> myList;
    myList.push_back(22.0);
    myList.push_front(33);
    cout << myList.size() << endl;
    
    return 0;
}
