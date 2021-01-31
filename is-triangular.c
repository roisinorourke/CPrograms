#include <stdio.h>
#include <stdlib.h> /* need to include this for atoi function to work */
#include <stdbool.h> /* using a boolean value so need to include this up here */

/* function to check if the number is triangular and return boolean value */
int is_triangular(int num)
{
    /* initialise the local variables */
    int count = 0;
    int i = 0;
    bool x = false;
    
    while (count <= num)
    {
        count += i; /* keep adding 1, 2, 3 ... to count until it equals the number, or becomes bigger than it */
        if (count == num)
        {
            x = true; /* if count == num then the number is triangular, so let x be true */
        }
        i++;
    }
    return x;
}

int main(int argc, char * argv[1]) 
{
    int num = 0;
    num = atoi(argv[1]); /* atoi turns the command-line argument from a string to an integer */
    
    if (is_triangular(num)) /* if is_triangular is true */
    {
        printf("%d is a triangular number.\n", num);
    }

    else /* if num is not triangular */
    {
        printf("%d is not a triangular number.\n", num);
    }
    
    
    exit(0); /* exit the program */
}