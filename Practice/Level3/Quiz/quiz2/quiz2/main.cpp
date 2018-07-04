//
//  main.cpp
//  quiz2
//
//  Created by Changheng Chen on 3/14/17.
//  Copyright © 2017 Changheng Chen. All rights reserved.
//

#include <iostream>

// A union is a special data type available in C that allows to store different data types in the same memory location. You can define a union with many members, but only one member can contain a value at any given time. Unions provide an efficient way of using the same memory location for multiple-purpose.

union Name
{
    char firstName[10];
    char lastName[10];   // 1 byte per character
};

int main()
{
    union Name name;
    strcpy(name.firstName, "Dennis");
    strcpy(name.lastName, "Ritchie");
    printf("%lu", sizeof(name)); // 10
    std::cout << name.firstName << name.lastName << std::endl; // RitchieRitchie
    //printf("%d", sizeof(name)); // output is 'unsigned long'
    
    
    
    // (7) create string
    char* str1="Hello World";
    char str2[]="Hello World";
    
    char* s1;
    char s2[80]; strcpy(s2, s1);
}
