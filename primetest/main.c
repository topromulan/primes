
/* 
 * A program to test checkprime()
 *
 * 20-22 February 2009,4-? February 2010 by Dale Anderson
 * dra@redevised.net
 *
 */

#include <stdio.h>
#include <math.h>

int checkprime(unsigned long number);

int main(void)
{
	unsigned long l;
	unsigned long total=0;

#ifdef LOADED
	unsigned long begin;

	/*
	 * round to the nearest multiple of 6
	 *
	 * note: the loaded test assumes we are starting above 3.
	 *
	 */

	begin = (LOWBALL < 6) ? 6 : LOWBALL - LOWBALL % 6;

	for(l=begin; l<=HIGHBALL; l+=6)
#else
	for(l=LOWBALL; l<=HIGHBALL; l+=1)
#endif
	{
#ifdef LOADED
		if(checkprime(l-1))
			total++;
		if(checkprime(l+1))
			total++;
#else
		if(checkprime(l)) {
			total++;
//			printf("%lu was prime\n", l);
		}
#endif
	}

	printf("I find %lu primes between %lu and %lu\n", total, LOWBALL, HIGHBALL);

	return 0;
}
