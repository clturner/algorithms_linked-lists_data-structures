#include <stdlib.h>
#include <stdio.h>
#include <stdlib.h>
#include "palindrome.h"
#include <string.h>
#include <math.h>

/**
 * is_palindrome - Checks if an integer is a plaindrome
 *
 * @n: integer
 * Return: 1 if n is a palindrome, 0 otherwise
 *
 */


int is_palindrome(unsigned long n)
{

        unsigned long a = 0;
        unsigned long new = 0;
        unsigned long saved = 0;

        saved = n;
        while(n != 0)
        {
                a = n;
                a = a % 10;
                new *= 10;
                new = new + a;
                n /= 10;

        }
        if (saved == new)
                return(1);
        else
                return(0);
}
