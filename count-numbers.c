#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

/* find the length of a string */
int strlength(char *str)
{
    int i = 0;

    for (i = 0; *(str + i) != '\0'; i++);
   
    return i;
}

/* function to check for any non digits */
bool non_digits(char *num)
{
    for (int i = 0; i < strlength(num); i++)
    {
        if ( isdigit(num[i]) == 0)
        return true;
    }

    return false;
}

/* count how many odd and even numbers occur */
int count_even_and_odd(int numbers[], int len)
{
    /* initialise counts */
    int evencount = 0;
    int oddcount = 0;

    for (int i = 0; i < len; i++)
    {
        if (numbers[i] % 2 == 0)
        {
            evencount++;
        }
        else
        {
            oddcount++; /* if number is not divisible by two -> odd */
        }
    }
    /* print count of odd and even numbers */
    printf("Number of odd numbers: %d\nNumber of even numbers: %d\n",oddcount, evencount);

    return 0;
}

/* check if a number is prime */
int is_prime(int num)
{
    bool x = true;
    
    if (num < 2)
    {
        x = false;
    }
    
    for (int i = 2; i < num; i++)
    {
        if (num % i == 0)
        {
            x = false;
        }
    }
    return x; /* if number is prime, return true, else false */
}

/* count how many prime numbers occur */
int count_primes(int numbers[], int len)
{
    int primecount = 0;
    
    for (int i = 0; i < len; i++)
    {
        if (is_prime(numbers[i]))
        {
            primecount++;
        }
    }
    /* print count of prime numbers */
    printf("Number of prime numbers: %d\n", primecount);

    return 0;
}

int main(int argc, char *argv[])
{
    /* initialise an array of numbers */
    int numbers[argc - 1];

    if (argc == 1)
    {
        printf("insufficient command line arguments.\n");
        return 0;
    }
    for (int i = 1; i < argc; i++)
    {
        if (atoi(argv[i]) < 0) /* if number is negative */
        {
            printf("Error: Only positive integers are permitted.\n");
            return 0;
        }

        else if (non_digits(argv[i])) 
        {
            printf("Error: only numbers are permitted.\n");
            return 0; /* if non-number is found exit the program */
        }

        /* add the command line arguments to the numbers array */
        numbers[i - 1] = atoi(argv[i]);
    }    

    /* pass the array of numbers to the count functions */
    count_even_and_odd(numbers, argc - 1);
    count_primes(numbers, argc - 1);

    return 0;
}
