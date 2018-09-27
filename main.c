//find prime numbers in area [2..N]
// All rights reserved. Code by Bramory
#include "tools.h"

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <memory.h>
#include <time.h>



void main_process(int N)
{
	const int prNameSize = 100;
	char* process_name = ""; //= malloc(prNameSize * sizeof(*process_name)); // there's is stackoverflow??
	char* numbers = malloc(N * sizeof(*numbers)); // there's too			
	
	int counter = 0;
	double AllTime = 0, time = 0; 
	struct timespec begin, end; 
	for(int sw = 0; sw < 3; sw++) {
		clock_gettime (CLOCK_REALTIME, &begin);

		switch (sw) {
			case 0:
				memset (numbers, 1, N * sizeof(char));
				process_name = "memset ";
			break;

			case 1:
				process_name = "sieve ";
				//strncpy (process_name, "sieve ", strlen("sieve "));
				sieve(N, numbers );
			break;

			case 2:
				process_name = "output";
				//strncpy (process_name, "output", strlen("output"));
				counter = prime_file(N, numbers);
			break;
		}
/* ************************* */clock_gettime (CLOCK_REALTIME, &end);
		time = (end.tv_sec - begin.tv_sec) + (end.tv_nsec - begin.tv_nsec) / 1e9;
		printf ("\nTime for %s - %.9f sec", process_name, time);
		AllTime += time;		
	}
	process_name = "process";
	printf ("\nTime for %s - %.9f sec - find %d numbers\n\n", process_name, AllTime, counter);
	//printf ("%.9f\n",AllTime);
	printf ("\nSee all the numbers in \"Primes.txt\"\n");
	free(numbers);
}
 
//must be 168 primes from N == 1000
unsigned int N = 200 * pow(10, 6); 
int main(int argc, char *argv[])
{	
	if (argc > 1)
	{	
		N = atoi(argv[1]);
		//printf ("%d", N);
	}

	if (N < 2)
	{
		system("find . -type f -iname \"primes.txt\" -delete");
		printf("There no primes numbers\n");
		return 0;	
	}

	for(int i = 0; i < 1; i++) {
		main_process(N);
		N += 20 * pow (10, 6);
	}
	return 0;
}