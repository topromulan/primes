
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
	 * This covers even numbers and divisible-by-3 numbers.
	 */

	l = number % 6;

	if ( ( ! ( l == 1 || l == 5) ) ) {
		return (number < 4 && number > 0) ? -1 : 0;
	}


	/* Test 2.
	 *
	 * Check if the number is divisible by any odd numbers
	 *  5 or 7 plus any multiple of 6 
	 *  less than number's square root.
	 *
	 */

	for ( l = 5; l <= sqrt(number); l += 6 )
		if ( (number % l == 0) || (number % (l + 2) == 0 ) )
			return 0;

	return -1;

}
