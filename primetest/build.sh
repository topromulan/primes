
LOWBALL=1234567890
HIGHBALL=1999999999

if [ ! -d bin ]
then
	echo $0: mkdir bin/ and try again > /dev/stderr
	exit 1;
fi

rm -f bin/* || exit 1

gcc -o bin/check				\
	-D HIGHBALL=$HIGHBALL			\
	-D LOWBALL=$LOWBALL			\
	main.c check.c				\
	-lm -ffast-math				&&
	
gcc -o bin/check-loaded				\
	-D LOADED				\
	-D HIGHBALL=$HIGHBALL			\
	-D LOWBALL=$LOWBALL			\
	main.c check.c				\
	-lm -ffast-math				&&

gcc -o bin/check-naive				\
	-D CHECKPRIME_NAIVE			\
	-D HIGHBALL=$HIGHBALL			\
	-D LOWBALL=$LOWBALL			\
	main.c check.c				\
	-lm -ffast-math				&&

#This test is invalid, (skipping check 1 without
# loading the test properly).
#gcc -o bin/check-nocheck1			\
	#-D CHECKPRIME_NOCHECK1			\
	#-D HIGHBALL=$HIGHBALL			\
	#-D LOWBALL=$LOWBALL			\
	#main.c check.c				\
	#-lm -ffast-math				&&

gcc -o bin/check-loaded-nocheck1		\
	-D LOADED				\
	-D CHECKPRIME_NOCHECK1			\
	-D HIGHBALL=$HIGHBALL			\
	-D LOWBALL=$LOWBALL			\
	main.c check.c				\
	-lm -ffast-math				&&
	
gcc -o bin/check-naive-nocheck1			\
	-D CHECKPRIME_NAIVE			\
	-D CHECKPRIME_NOCHECK1			\
	-D HIGHBALL=$HIGHBALL			\
	-D LOWBALL=$LOWBALL			\
	main.c check.c				\
	-lm -ffast-math				&&

gcc -o bin/check-loaded-naive-nocheck1		\
	-D LOADED				\
	-D CHECKPRIME_NOCHECK1			\
	-D CHECKPRIME_NAIVE			\
	-D HIGHBALL=$HIGHBALL			\
	-D LOWBALL=$LOWBALL			\
	main.c check.c				\
	-lm -ffast-math				&&

echo Build OK.

