//
//  TestFibonacci.cpp
//
//  Created by Changheng Chen on 11/3/16.
//  Copyright © 2016 Changheng Chen. All rights reserved.
//
//  Showing the use of recursive functions by implementing
//  Fibonaccid sequences.
//

#include <algorithm>
#include <iostream>
using namespace std;

long Fibonacci(long n)
{ // Recursive function
    
    if (n==0)
    {
        return 0;
    }
    
    if (n==1)
    {
        return 1;
    }
    
    return Fibonacci(n-1) + Fibonacci(n-1);
}

int main()
{ // 0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, 233, 377, 610, 987, 2584, 4181, 6765 ...
    
    int N = 50; // How many Fibonacci numbers to compute
    
    for (int n =0; n < N; ++n)
    {
        cout << Fibonacci(n) << ",";
    }
    
    return 0;
}
