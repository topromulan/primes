
/* 
 * A function to test if a number is prime
 *
 * 20-22 February 2009, 04 February 2010 by Dale Anderson
 * dra@redevised.net
 *
 */

#include <math.h>

int checkprime(unsigned long number)
{
	/* A long integer used for work in both tests below */
	unsigned long l;

	/* Test 1.
	 *
	 * Check for common exceptions.
	 *
	 *  Numbers between 1-3 are prime.
	 *  Else the number must be a multiple of 6 +/- 1 to consider.
	 *
	 */

	l = number % 6;

	if ( ( ! ( l == 1 || l == 5) ) ) {
		return (number < 4 && number > 0) ? -1 : 0;
	}


	/* Test 2.
	 *
	 * See if the number is divisible by any odd numbers
	 *  between 5 and its square root.
	 *
	 * This covers even numbers and divisible-by-3 numbers.
	 *
	 * 2 and 3 are covered in test 1.
	 *
	 */

	for ( l = 5; l <= sqrt(number); l += 6 )
		if ( (number % l == 0) || (number % (l + 2) == 0 ) )
			return 0;

	return -1;

}
