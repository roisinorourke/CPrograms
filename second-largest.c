#include <stdio.h>
#include <stdlib.h>

void secondLargest (int *numbers,int *index, int length)
{

    /* initialise variables */
    int largest = numbers[0];
    int secondlargest = numbers[1];
    
    /* find the largest number */
    for (int i = 0; i < length; i++)
    {
        if (numbers[i] > largest)
        {
            largest = numbers[i];
        }
    }

    /* find the next largest number that isnt the largest number */
    for (int i = 0; i < length; i++)
    {
        if (numbers[i] > secondlargest && numbers[i] != largest)
        {
            secondlargest = numbers[i];
            *index++;
        }
    }
    

    printf("%d\n", secondlargest); /* print second largest number */
    return;
}

int main(int argc, char *argv[])
{
    /* initialise an array of numbers */
    int numbers[argc - 1];

    if (argc == 1)
    {
        printf("Insufficient arguments provided\n");
        return 0;
    }

    for (int i = 1; i < argc; i++)
    {
        if (atoi(argv[i]) < 0)
        {
            printf("Error: only positive integers are permitted.\n");
            return 0;
        }
        else
        {
            /* add each command line argument to the array */
            numbers[i - 1] = atoi(argv[i]);
        }
    }
    /* pass the array to the secondLargest function */
    secondLargest(numbers, &numbers[0], argc - 1);

    return 0;
}
