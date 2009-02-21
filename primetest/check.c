
/* 
 * A function to test if a number is prime
 *
 * 20-22 February 2009 by Dale Anderson
 * dra@redevised.net
 *
 */

#include <stdio.h>
#include <math.h>

int checkprime(unsigned long number)
{
	/* A long integer used for work in both tests below */
	unsigned long l;

	/* Test 1.
	 *
	 * Check if the number could possibly be prime (natural multiple
	 *  of 6 +/- 1 
	 *
	 * i.e. number modulo 6 should be 1 or 5 
	 */

/* define CHECKPRIME_NOCHECK1 if you
 *  are loading the inputs properly and don't
 *  need the test */

#ifndef CHECKPRIME_NOCHECK1
	l = number % 6;

	if ( ( ! ( l == 1 || l == 5) ) && ( number != 3 ) && ( number != 2 ) )
	{
		/* Not a prime */
		return 0;
	}

	if ( ! number % 2 )
	{
		/* It's even. Return true if it's 2, else 0. */
		return (number == 2) ? -1 : 0;
	}

	if ( number == 3 )
	{
		/* It's 3 */
		return -1;
	}
#endif

	/* Test 2.
	 *
	 * See if the number is divisible by any odd numbers
	 *  between 3 and its square root.
	 *
	 * Unless CHECKPRIME_NAIVE is defined (for speed
	 *  comparisons).
	 */

#ifndef CHECKPRIME_NAIVE

	for ( l = 3; l <= sqrt(number); l += 2 )
#else
	for ( l = 2; l <= number / 2; l += 1 )
#endif
	{
		if(number % l == 0)
		{
			return 0;
		}
	}

	return -1;

}
