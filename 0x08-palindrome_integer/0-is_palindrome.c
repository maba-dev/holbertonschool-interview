#include "palindrome.h"
/**
 *is_palindrome - checks whether or not a given unsigned integer is a palindrom
 *
 * @n: number integer
 * Return: 0 or 1
 */

int is_palindrome(unsigned long n)
{
	unsigned long reversed = 0, t = n;

	while (t > 0)
	{
		reversed = reversed * 10 + t % 10;
		t /= 10;
	}
	return (n == reversed);
}
