//
//  main.cpp
//  quiz4
//
//  Created by Changheng Chen on 3/14/17.
//  Copyright © 2017 Changheng Chen. All rights reserved.
//

#include <iostream>
using namespace std;

void F(int i)
{
    if (i%2) throw i;   // if 0 = false, otherwise true
    std::cout<<"Correct number"<<std::endl;
}

int main()
{
    try
    {
        for (int i=0; i<2; i++)
        {
            F(i); std::cout<<"Next iteration"<<std::endl;
        }
    }
    catch(int i)
    {
        std::cout<<"Exception: "<<i<<std::endl; return i; // return 1 !!!! terminnated here!!!!!!
    }
    
    std::cout<<"Finished"<<std::endl; // Not excuted...
    
    return 0;
}
