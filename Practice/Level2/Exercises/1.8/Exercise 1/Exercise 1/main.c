//
//  main.c
//  Exercise 1
//
//  Created by Changheng Chen on 11/17/16.
//  Copyright © 2016 Changheng Chen. All rights reserved.
//

#include <stdio.h>

struct Article
{ // Create the struct
    
    int Article_number;
    int Quantity;
    char Description[20];
};

void Print();

int main()
{
    // Initialize the Article option
    struct Article option = {123456, 10, "Some description."};
    Print(&option);
    
    return 0;
}

void Print(struct Article* p)
{ // Access the article via a pointer
    
    printf("Article number: %d\n", (*p).Article_number);
    printf("Article quantity: %d\n", (*p).Quantity);
    printf("Article description: %s\n", (*p).Description);
}
