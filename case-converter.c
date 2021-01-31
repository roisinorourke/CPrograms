#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>

/* function to find the length of a string */
int strlength(char *str)
{
   int i = 0;

   for (i = 0; *(str + i) != '\0'; i++);
   
   return i;
}

/* function to convert the case of a character using ASCII values */
void convert(char *c)
{
    if (*c >= 97 && *c <= 122) /* if the char is lower case */
    {
        *c -= 32; /* minus 32 will change it to its upper case equivalent */
    }
    else
    {
        *c += 32;
    }
    return;
}

int main()
{
    char str[100];
    bool x = true;
    
    printf("Enter a string of upper and lower case letters\n");
    scanf("%s", &str);

    for (int i = 0; i < strlength(str); i++)
    {
        /* check for invalid characters */
        if (isalpha(str[i]) == 0)
        {
            x = false;
        }
    }
    
    if (x) /* if x is still true and no invalid characters found */
    {
        for (int i = 0; i < strlength(str); i++)
        {
            /* convert each character individually using pointers */
            convert(&str[i]);
        }
        printf("%s\n", str); /* print the converted string */
    }

    else
    {
        printf("Invalid character entered.\n");
    }
    
    return 0;
}
