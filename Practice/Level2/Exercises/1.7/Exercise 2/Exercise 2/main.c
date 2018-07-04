//
//  main.c
//  Exercise 2
//
//  Created by Changheng Chen on 11/17/16.
//  Copyright © 2016 Changheng Chen. All rights reserved.
//

/* Calculate the length of a string */
    
#include <stdio.h>
#include <string.h>
    
#define MAXLINE 30
    
// String length declaration
int Length(char str[]);
    
int main()
{
    char string[MAXLINE+1]; // Line of maximum 30 chars + \0
    int c;                  // The input character
    int i=0;                // The counter
        
    // Print intro text
    printf("Type up to %d chars. Exit with ^Z\n", MAXLINE);
        
    // Get the characters
    while ((c=getchar())!=EOF && i<MAXLINE)
    { // Append entered character to string
        
        string[i++]=(char)c;
    }
    string[i]='\0'; // String must be closed with \0
        
    printf("Function Length: String length is %d\n", Length(string));
    printf("Function strlen: String length is %ld\n", strlen(string));
    
    return 0;
}
    
/* Implement the Length() function here */
int Length(char str[])
{
    /*
    int i = 0;
    char* p;
    
    while (*(p = &str[i]) != '\0') {i++;}
    // while (str[i] != '\0') {i++;} // Alternative method
    
    return i; */
    
    int i = 0;
    while(str[i++] != '\0');
    
    return i-1;
}
