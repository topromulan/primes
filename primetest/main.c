
/* 
 * A program to test checkprime()
 *
 * 20-22 February 2009 by Dale Anderson
 * dra@redevised.net
 *
 */

#include <stdio.h>
#include <math.h>

int checkprime(unsigned long number);

int main(void)
{
	unsigned long l;

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
		{
			printf("Bingo. %ld was prime.\n", l-1);
		}
		if(checkprime(l+1))
		{
			printf("Bingo. %ld was prime.\n", l+1);
		}
#else
		if(checkprime(l))
		{
			printf("Bingo. %ld was prime.\n", l);
		}
#endif
	}

	return 0;
}
