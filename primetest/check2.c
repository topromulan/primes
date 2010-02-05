
/* 
 * A function to test if a number is prime
 *
 * 20-22 February 2009, 04- February 2010 by Dale Anderson
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
	 *  The number must not be even (unless 2).
	 *  The number must not be 3.
	 *  The number must be a multiple of 6 +/- 1 
	 *
	 * i.e. number modulo 6 should be 1 or 5 
	 */

	l = number % 6;

	if ( ( ! ( l == 1 || l == 5) ) ) {
		return (number < 4 && number > 0) ? -1 : 0;
	}
//	if ( ! number % 2 ) {
//		/* It's even. Return true if it's 2, else 0. */
//		return (number == 2) ? -1 : 0;
//	}
//
//	if ( number == 3 ) {
//		/* It's 3, the only exception to this rule. */
//		return -1;
//	}
//
//	if ( ( ! ( l == 1 || l == 5) ) ) {
//		/* Not a prime */
//		return 0;
//	}


	/* Test 2.
	 *
	 * See if the number is divisible by any odd numbers
	 *  between 5 and its square root.
	 *
	 * We don't need to check 3, as that is covered above.
	 *
	 * Unless CHECKPRIME_NAIVE is defined (for speed
	 *  comparisons).
	 */

	for ( l = 5; l <= sqrt(number); l += 6 )
		if ( (number % l == 0) || (number % (l + 2) == 0 ) )
			return 0;

	return -1;

}
