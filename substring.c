#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>

/* find the length of a string */
int strlength(char *str)
{
    int i = 0;

    for (i = 0; *(str + i) != '\0'; i++);
   
    return i;
}

/* check for invalid characters in the string */
bool non_char(char *str)
{
    for (int i = 0; i < strlength(str); i++)
    {
        if ( isalpha(str[i]) == 0) /* if there is an invalid character, return true */
        return true; 
    }

    return false; /* false if no invalid characters have been found */
}

/* print the results of is_substring */
void result(bool x, char *string, char *substring)
{
    if (x)
    {
        printf("the string '%s' is contained in the string '%s'\n", substring, string);
    }
    else
    {
        printf("the string '%s' is not contained in the string '%s'\n", substring, string);
    }
    return;
}

/* check if there is a substring */
void is_substring(char *string, char *substring)
{
    /* initialise variables */
    int str_length = strlength(string);
    int sub_length = strlength(substring);
    int range = str_length - sub_length + 1;

    bool x = false;

    for (int i = 0; i < range; i++) /* loop to go through main string */
    {
        int j = 0;
        int k = i;
        int count = 0;

        while (j < sub_length) /* loop to go through the substring */
        { 
            if (substring[j] == string[k])
            {
                count++;
                j++;
                k++;
            }
            else
            {
                j++;
            }
        }

        /* if every element in substring has matched the string */
        if (count == sub_length)
        {
            x = true; /* there is a substring */
        }
    }    
    
    /* pass the bool value and strings to the result function */
    result(x, string, substring);
    return;
}

int main()
{
    /* initialise two strings */
    char string[100];
    char substring[100];

    printf("Enter the first string:\n");
    scanf("%s", &string);
    
    /* check the string is valid */
    if (non_char(string))
    {
        printf("Invalid character entered\n");
        return 0;
    }

    printf("Enter the second string:\n");
    scanf("%s", &substring);
    
    if (non_char(substring))
    {
        printf("Invalid character entered\n");
        return 0;
    }

    /* pass the two strings to the is_substring function */
    is_substring(string, substring);

    return 0;
}
