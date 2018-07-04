//
//  SumContainers.hpp
//  Exercise 2
//
//  Created by Changheng Chen on 2/6/17.
//  Copyright © 2017 Changheng Chen. All rights reserved.
//

#ifndef SumContainers_hpp
#define SumContainers_hpp

#include <vector>
#include <list>
#include <map>
#include <string>
using namespace std;


// ================== SUM OF ALL ELEMENTS IN CONTAINER ==================

template <typename T>
double Sum(const T& source)
{
    double sum = 0.0;
    
    typename T::const_iterator it;
    typename T::const_iterator end = source.end();
    
    for (it = source.begin(); it != end; ++it)
        sum += *it;
    
    return sum;
}


// Template specialization for map
template <>
double Sum(const map<const string, double>& source)
{
    double sum = 0.0;
    
    map<const string, double>::const_iterator it;
    map<const string, double>::const_iterator end = source.end();
    
    for (it = source.begin(); it != end; ++it)
        sum += it->second;
    
    return sum;
}


// =================== SUM OF ELEMENTS WITHIN A RANGE ===================
template <typename T> 
double Sum(const T& start, const T& end)
{
    double sum = 0.0;
    
    for (T it = start; it != end; ++it)
        sum += *it;
    
    return sum;
}

// Template specialization for container map
template <>
double Sum(const map<const string, double>::const_iterator& start, const map<const string, double>::const_iterator& end)
{
    double sum = 0.0;
    
    map<const string, double>::const_iterator it;
    
    for (it = start; it != end; ++it)
        sum += it->second;
    
    return sum;
}

#endif /* SumContainers_hpp */
