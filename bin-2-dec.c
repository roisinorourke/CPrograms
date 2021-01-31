#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <stdbool.h>

/* find the length of a string */
int strlength(char *str)
{
   int i = 0;

   for (i = 0; *(str + i) != '\0'; i++);
   
   return i;
}

/* function reverse a string */
void reverse(char *str)
{
   char *start, *end, tmp;
   
   /* prevent memory locations with 0 */
   if (str != NULL && *str != 0)
   {
      start = str;
      end = start + strlength(str) - 1;
      
      while (end > start)
      {
         /* swap the first element with the last element */
         tmp = *start;
         *start = *end;
         *end = tmp;

         /* move onto the second and second last element... */
         start++;
         end--;
      }
   }
}

/* change the binary number to a decimal */
void bin_to_dec(char *str)
{
   reverse(str); /* reverse the binary number */

   int dec = 0;

   for (int i = 0; i < strlength(str); i++)
   {
      /* convert the char to a digit */
      int x = str[i] - '0';
      
      dec += (x * (pow(2, i)));
   }
   printf("%d\n", dec);
}

/* function to make sure there aren't too many digits or digits besides 1 or 0. */
bool errors(char *str)
{
   bool x = true;
   bool y = true;

   /* if the binary number is longer than eight digits long */
   if (strlength(str) > 8)
   {
      x = false;
      printf("Too many binary digits entered.\n");
   }
   for (int i = 0; i < strlength(str); i++)
   {
      /* check if the digit is either 0 or 1 */
      if (str[i] != '0' && str[i] != '1') 
      {
         x = false;
         y = false;
      }
   }
   if (y == false)
   {
      printf("Only digits 1 and 0 are permitted.\n");
   }
   
   return x; /* if x is still true there are no errors */
}

int main(int argc, char *argv[])
{
   /* initialise a string variable */
   char bin[100];

   for (int i = 1; i < argc; i++)
   {
      /* add each command line argument to the bin string */
      strcat(bin, argv[i]);
   }

   if (errors(bin)) /* if there are no errors -> returns true */
   {
       bin_to_dec(bin);
   }

   return 0;
}