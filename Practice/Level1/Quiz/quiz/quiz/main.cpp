//
//  main.cpp
//  quiz
//
//  Created by Changheng Chen on 3/15/17.
//  Copyright © 2017 Changheng Chen. All rights reserved.
//

#include <iostream>

// (1)
int Power(int a, int b)
{
    int result=a;
    for (int i=1; i!=b; i++) result*=a;
    return result;
}

int main()
{
    int i=2; int j=4;
    printf("%d^%d=%d\n", i, j, Power(i,j));
    
    int a = INT_MAX;
    printf("%d\n",a+1);
    
    
    // (2)
    int x=4;
    printf("%d\n", (x*=4, x+2)); // 18
    
    // (3)
    i=0;
    //while (i<2);  // Here the ';' makes an empty while loop, the code prints nothing and hangs
    {
        printf("%d ", i);
    }
    std::cout << std::endl;
    
    // (4)
    int ii,jj;
    for (ii=0, jj=4; ii<jj;)
    {
        printf("%d, %d\n", ii++, jj--); // 0, 4
                                        // 1, 3
    }
    
    // (5)
    double f=4.0;
    f+=4.0+10.0/f+++5.0;
    std::cout << f << std::endl;  // 16.5

    // (6)
    x=10;
    printf("%d, ", x++); printf("%d\n", x-x?--x:++x); // 10, 12
    
    // (7)
    double xx=5/2;
    printf("%.1f\n", xx);// 2.0
    
    
    /*// (8)
    double a1=1;
    
    switch(a1) // invalid, code does not compile
    {
        case 0:
            printf("Zero");
        case 1:
            printf("One");
        case 2:
            printf("Two");
    } */
    
    // (9)
    printf("%d\n", 6^12); // 10
    
    
    // (10)
    int x1=4, y1=8;
    printf("%d, %d\n", x1|y1, x1||y1); // 12, 1
    
    // (11)
    //The two statements are true about Boolean types in C.    
    //The result of a logical expression can be assigned to an int variable. The value will be 0 if the expression was false or 1 if the expression was true.
    //In C there is no Boolean type but a Boolean is int. 0 is interpreted as false. Not 0 is interpreted as true.
    
    
}
