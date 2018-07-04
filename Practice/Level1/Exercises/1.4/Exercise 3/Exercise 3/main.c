//
//  main.c
//  Exercise 3
//
//  Created by Changheng Chen on 11/11/16.
//  Copyright © 2016 Changheng Chen. All rights reserved.
//

#include <stdio.h>

int main()
{
    int amount_of_characters = 0, amount_of_words = 0, amount_of_newlines = 0;
    int itext, ilast_text;
    char text;
    
    printf("Entern text for evaluating statistics: \n");
    
    text = getchar();
    itext = (int)text;
    ilast_text = itext;
    
    // int(CTRL + D) has value -1 on this Mac!
    while (itext!=-1)
    {
        /* Count words (2 scenarios):
         last_text                    text
         (1) (not ' '  && not '\n' && not Tab)      ' '
         (2) (not ' '  && not '\n' && not Tab)      '\n'   */
        
        switch (itext)
        {
            // text==' ' && last_text!=' ' && last_text!='\n' && last_text!=Tab
            case (32):
            {
                switch (ilast_text)
                {
                    case (32):
                        break;
                    case (10):
                        break;
                    case (9):
                        break;
                    default:
                        amount_of_words++;
                        break;
                }
                break;
            }
                
            // text=='\n' && last_text!='\n' && last_text!=' ' && last_text!=Tab
            case (10):
            {
                switch (ilast_text)
                {
                    case (10):
                        break;
                    case (32):
                        break;
                    case (9):
                        break;
                    default:
                        amount_of_words++;
                        break;
                }
                break;
            }
                
        }
        
        
        switch (itext)
        {
            // Count newlines by counting '\n'
            case(10):
                amount_of_newlines++;
                break;
            // Count characters: One space/tab is counted as one character, and '\n' is not.
            default:
                amount_of_characters++;
                break;
        }
        
        ilast_text = itext;
        text = getchar();
        itext = (int)text;
    }
    
    printf("Amount of characters is %d \n", amount_of_characters);
    printf("Amount of words is %d \n", amount_of_words);
    printf("Amount of newlines is %d \n" ,amount_of_newlines);
    
    return 0;
}
