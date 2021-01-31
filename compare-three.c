#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h> /* using a boolean value so need to include this up here */

/* a function which takes three integers and sees if any are the same */
int samenumber(int num1, int num2, int num3)
{
    bool x = true;

    if ((num1 == num2) || (num1 == num3) || (num2 == num3))
    {
        x = false;
    }
    return x; /* x will be true if the numbers are different, false if they are the same */
}

/* a function which takes three integers and returns the largest */
int largest(int num1, int num2, int num3) {

   /* local variable declaration */
    int result;
 
    if (num1 > num2 && num1 > num3) /* if the first number is largest */
    {
        result = num1;
    }
    else if (num2 > num1 && num2 > num3) /* if the second number is largest */
    {
        result = num2;
    }
    else /* if the third number is largest */
    {
        result = num3;
    }
    
 
   return result; /* return which number is largest */
}

int main(int argc, char *argv[3])
{
    /* initiate the variables */
    int a = 0;
    int b = 0;
    int c = 0;

    /* turn each argument into an integer and assign them to an integer variable */
    a = atoi(argv[1]);
    b = atoi(argv[2]);
    c = atoi(argv[3]);

    /* see if any of the arguments are the same */
    if (samenumber(a, b, c)) /* if no numbers are the same */
    {
        /* pass the three numbers into the largest function and print the largest one */
        printf("%d is the largest number.\n", largest(a, b, c));
    }
    else /* if two numbers are the same */
    {
        printf("error: two numbers entered are the same\n");
    }
    return 0;
}
