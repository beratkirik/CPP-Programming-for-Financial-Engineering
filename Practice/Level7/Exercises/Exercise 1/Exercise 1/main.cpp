//
//  main.cpp
//  Exercise 1
//
//  Created by Changheng Chen on 2/6/17.
//  Copyright © 2017 Changheng Chen. All rights reserved.
//

#include <iomanip>
#include <iostream>
#include <list>
#include <vector>
#include <map>
using namespace std;

int main()
{
    
    // (1) Create list, add and access data
    list<double> l; // Create list
  
    l.push_front(1);   // Add element: 1
    l.push_back(2);    // Add element: 1, 2
    l.push_back(3);    // Add element: 1, 2, 3
    
    cout << "First element: " << l.front() << endl; // Access 1st element: 1
    cout << "Last element: "  << l.back()  << endl; // Access 2nd element: 3
    cout << endl;
    
    
    
    // (2) Create vector, add and access data
    /* Vector growth: 
     
       Initial size and capacity of vector are both 0; then both size and capacity become 1.
     
       Afterwards, vector capacity jumps to 2*N every time vector size reaches the vector capacity,
       here N is the vector's previous capacity and N>=1.
     */
    
    // Create vector, add element with push_back(), and check size() and capacity()
    vector<double> v;
    cout << setw(20) << "v size:  " << v.size() << "  capacity:  " << v.capacity() << endl;
    for (int i = 0; i < 32; ++i)  // Check the growth of vector
    {
        v.push_back(i);
        cout << "v[i]=" << setw(4) << v[i] << "  v size: " << setw(2)
        << v.size() << "  capacity: " << setw(2) << v.capacity() << endl;
    }
    cout << endl;
    
    
    
    // (3) Create map and use operator [] to access elements
    // Create map with key (const char*) and value (double)
    map<const char*, double> score;
    map<const char*, double>::iterator iterator;
    
    score["English"] = 97.0;  // Add element
    score["History"] = 98.0;  // Add element
    score["Physics"] = 99.0;  // Add element
    
    // Get score of English
    cout << "English score: " << score["English"] << endl;
    
    // Get score of Physics
    iterator = score.find("Physics");
    cout << "Physics score: " << (*iterator).second << endl;

    return 0;
}
