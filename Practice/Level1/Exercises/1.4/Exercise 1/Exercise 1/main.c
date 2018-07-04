//
//  main.c
//  Exercise 1
//
//  Created by Changheng Chen on 11/4/16.
//  Copyright © 2016 Changheng Chen. All rights reserved.
//

#include <stdio.h>

int main()
{
    int amount_of_characters = 0, amount_of_words = 0, amount_of_newlines = 0;
    char text, last_text;
    
    printf("Enter text for evaluating statistics: \n");
    
    text = getchar();
    last_text = text;
    
    // int(CTRL + D) has value -1 on this Mac!
    while ((int)text!=-1) 
    {
        // 32 is ASCII for space, 9 is for tab and 10 is for the key enter
        /* Count words (2 scenarios):
                      last_text                    text
        (1) (not ' '  && not '\n' && not Tab)      ' '
        (2) (not ' '  && not '\n' && not Tab)      '\n'   */
        
        if (text==' ' && last_text!=' ' && last_text!='\n' && (int)last_text!=9)
        {
            amount_of_words++;
        }
        else if (text=='\n' && last_text!='\n' && last_text!=' ' && (int)last_text!=9)
        {
            amount_of_words++;
        }
        
        if (text=='\n') // Count newlines by counting '\n'
        {
            amount_of_newlines++;
        }
        else // Count characters: Space is counted as character, and '\n' is not.
        {
            amount_of_characters++;
        }
        
        last_text = text;
        text = getchar();
    }
    
    printf("Amount of characters is %d \n", amount_of_characters);
    printf("Amount of words is %d \n", amount_of_words);
    printf("Amount of newlines is %d \n", amount_of_newlines);
    
    return 0;
}
