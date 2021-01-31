#include <stdio.h>
#include <stdlib.h> /* need to include this for atoi function to work */
#include <stdbool.h> /* using a boolean value so need to include this up here */

/* function to check if a year is a leapyear */
int is_leapyear(int year)
{
    bool x = false;
    if (year % 400 == 0) /* any year divisible by 400 is a leapyear */
    {
        x = true;
    }
    else if ((year % 4 == 0) && !(year % 100 == 0)) /* any year divisible by 4 and not by 100 is a leapyear */
    {
        x = true;
    }
    return x; /* return true if its a leapyear, false other wise */
}

/* function to print the leapyears */
int printleapyears(int startyear, int endyear)
{
    while (startyear <= endyear) /* loop to go through all years between two given years */
    {
        if (is_leapyear(startyear))
        {
            /* if the year is a leapyear, print it */
            printf("%d\n", startyear);
        }
        startyear++;
    }
    return 0;
}

int main(int argc, char *argv[2])
{
    /* initialise variable */
    int startyear = 0;
    int endyear = 0;

    /* turn the arguments into integers and assign them to variables */
    startyear = atoi(argv[1]);
    endyear = atoi(argv[2]);

    printleapyears(startyear, endyear); /* pass the two years into printleapyears function */
    
    return 0;
}
