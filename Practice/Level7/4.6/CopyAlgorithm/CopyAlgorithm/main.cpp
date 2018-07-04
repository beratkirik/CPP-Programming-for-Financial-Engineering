//
//  main.cpp
//  CopyAlgorithm
//
//  Created by Changheng Chen on 2/6/17.
//  Copyright © 2017 Changheng Chen. All rights reserved.
//

#include <iostream>
#include <list>
#include <vector>

using namespace std;

int main()
{
    vector<double> src; // Vector source
    list<double> des;   // List destination
    
    // Fill source.
    src.push_back(1);
    src.push_back(2);
    src.push_back(3);
    
    // Copy source to destination.
    copy(src.begin(), src.end(), back_inserter(des));
    
    // Copy destination to cout.
    copy(des.begin(),des.end(), ostream_iterator<double>(cout, "\n"));
    
    return 0;
}
