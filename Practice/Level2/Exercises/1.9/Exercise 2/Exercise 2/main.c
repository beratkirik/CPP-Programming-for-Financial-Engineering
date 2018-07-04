//
//  main.c
//  Exercise 2
//
//  Created by Changheng Chen on 11/18/16.
//  Copyright © 2016 Changheng Chen. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE* fp;
    char FileName[255]; // Filename buffer size should be larger;
    int c;              // say at least 255 to at least accommodate the old maximum filepath size.
    
    // (1) Get the file name
    printf("Enter a filename: \n");
    /////scanf("%s",FileName); // scanf() ends taking input upon encountering a whitespace, newline or EOF
                               // gets() considers a whitespace as a part of the input string and ends the input upon encountering newline or EOF.
    gets(FileName);
    
    // (2) Create and write the file
    // open
    fp = fopen(FileName,"w");
    // write
    if (fp == NULL)
    {
        printf("Opening file failed...");
        exit(1);
    }
    else
    {
        // Can avoid that extra getchar() by using gets() instead of scanf() for the filename,
        // which will automatically discard the remaining newline from the input buffer.
        printf("Type in characters to write to file: \n");
        /////////c = getchar();
        
        while ((c = getchar()) != 1) fputc(c, fp);
        
        if (c == 1) printf("CTRL + A is a correct ending.\n");
    }
    // close
    fclose(fp);
    
    return 0;
}
