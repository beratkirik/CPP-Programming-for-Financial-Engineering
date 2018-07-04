//
//  main.cpp
//  quiz1
//
//  Created by Changheng Chen on 3/14/17.
//  Copyright © 2017 Changheng Chen. All rights reserved.
//


#include <iostream>
using std::cout;

class EA {};
class EB: public EA {};

void F()
{
    throw EB();
}


int main()
{
    try
    {
        F();
    }
    catch(EA&)
    {
        std::cout<<"EA Exception"<<std::endl;
    }
    catch(EB&) // Exception of type 'EB &' will be caught by earlier handler
    {
        std::cout<<"EB Exception"<<std::endl;
    }
    
    std::cout<<"Finished"<<std::endl;
    
    return 0;
}
