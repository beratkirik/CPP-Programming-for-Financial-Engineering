//
//  main.cpp
//  quiz3
//
//  Created by Changheng Chen on 3/14/17.
//  Copyright © 2017 Changheng Chen. All rights reserved.
//

#include <stdio.h>

struct Point
{
    double x;
    double y;
};

int main()
{
    struct Point p, *pp=&p;
    //struct Point p, *pp;
    //pp = &p;
    printf("%.2f\n", pp->x);  // 0.00
    printf("%.2f\n",(*pp).y); // 0.00
}

