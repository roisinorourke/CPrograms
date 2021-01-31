#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>

/* define */
#define MAX_LENGTH 100

/* function to find the length of a string */
int strlength(char *str)
{
    int i = 0;

    for (i = 0; *(str + i) != '\0'; i++);
   
    return i;
}

/* convert a character to lower case */
void convert(char *c)
{
    if (*c >= 'A' && *c <= 'Z') /* if the char is upper case */
    {
        *c += 32; /* plus 32 will change it to its lower case equivalent */
    }
    return;
}

/* remove any white spaces and punctuation marks */
void only_alpha(char *str)
{
    int i = 0;
    int j = 0;

    while (str[i] != '\0')
    {
        if (isalpha(str[i]))
        {
            /* if the char is alpha, we add it back to str, else we just skip it */
            str[j] = str[i];
            j++;
        }
        i++;
    }
    str[j] = '\0';
    return;
}

/* check if a string is a palindrome */
bool is_palindrome(char *str)
{
    bool x = false; /* set x initially to false */
    int len = strlength(str);;
    int count = 0;
    int i = 0;

    for (i = 0; i < len / 2; i++)
    {
        /* if the first char matches the last char */
        if (str[i] == str[len - 1 - i])
        {
            count++;
        }
    }
    /* if every letter has matched it is a palindrome */
    if ( count == i)
    {
        x = true;
    }
    return x; /* x is true if its a palindrome, false if not */
}

int main(void)
{
    char firststring[MAX_LENGTH];
    char *string = NULL; /* declare a pointer */

    printf("Please enter a string:  ");
    printf("\n");

    /* get the string from standard input */
    fgets(firststring, MAX_LENGTH, stdin);

    /* allocate a block of memory for the string */
    string = (char*)malloc(strlength(firststring)*sizeof(char));
    strcpy(string,firststring);

    /* make sure there are no numbers in the string */
    for (int i = 0; i < strlength(string); i++)
    {
        if (isdigit(string[i]))
        {
            printf("Invalid input: Numbers not permitted.\n");
            return 0;
        }
    }

    /* convert the string to all lowercase - easier to check if its a palindrome */
    for (int i = 0; i < strlength(string); i++)
    {
        convert(&string[i]);
    }
    
    /* remove any whitespaces or punctuation */
    only_alpha(string);

    /* check if the string is a palindrome */
    if (is_palindrome(string))
    {
        printf("This string is a palindrome.\n");
    }
    else
    {
        printf("This string is not a palindrome.\n");
    }
    

    return 0;

    /* release the memory allocated for the string */
    free(string);
}
