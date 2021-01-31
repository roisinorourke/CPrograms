#include <stdio.h>
#include <stdlib.h> /* need to include this for atoi function to work */

/* a function to return a hailstone sequence */
int hailstones(int num)
{ 
    /* calculate the hailstone sequence */
    while (num != 1) /* until the number equals one, keep changing and printing the new number */
    {
        if (num % 2 == 0) /* if the number is even, divide by two */
        {
            num = num / 2;
        }
        else
        {
            num = num * 3 + 1; /* if the number is odd, multiply by three and add one */
        }
        printf("%d\n", num); /* print the number from the sequence */
    }
}



int main(int argc, char *argv[1])
{
    /* initialise the variables */
    int num = 0;
    
    num = atoi(argv[1]); /* turn the command-line argument from a string to an integer */

    hailstones(num); /* pass the argument into the hailstones function */
    
    return 0; /* exit the program */
}
