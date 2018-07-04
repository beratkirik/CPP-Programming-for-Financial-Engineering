//
//  main.c
//  Exercise 2
//
//  Created by Changheng Chen on 11/11/16.
//  Copyright © 2016 Changheng Chen. All rights reserved.
//

#include <stdio.h>

int main()
{
    int amount_of_characters = 0, amount_of_words = 0, amount_of_newlines = 0;
    char text, last_text;
    
    printf("Entern text for evaluating statistics: \n");
    
    text = getchar();
    last_text = text;
    
    do
    {
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
        
        if ((int)text==-1) // Special scenario: The first input is '^D'
        {
            amount_of_characters--;
        }
        
        last_text = text;
        text = getchar();
    }
    while ((int)text != -1); // int(CTRL + D) has value -1 on this Mac!

    printf("Amount of characters is %d \n", amount_of_characters);
    printf("Amount of words is %d \n", amount_of_words);
    printf("Amount of newlines is %d \n", amount_of_newlines);
    
    return 0;
}
