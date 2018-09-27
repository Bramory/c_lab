#include "tools.h"
#include <stdio.h>

//change values in the array (1==prime) and (0==compound) 
void sieve ( int size, char *numbers )
{
	for (int i = 3; i * i <= size; i+=2) {
		if ( numbers[i] != 0)
			for(int j = i * i; j <= size; j += i )
				numbers[j] = 0;
	}
}

//print prime numbers from presieved array to the console
int prime_list(int size, char *numbers )
{
	int counter = 1;
	printf ("2 ");//'cause 2 is prime
	for(int i = 3; i <= size; i +=2 ) {
		if ( numbers[i] != 0) 
		{
			printf ("%i ", i );
			counter++;
		}
	}
	return counter;
}

//write prime numbers a b c into the file 
int prime_file(int size, char *numbers)
{
	int counter = 1;
	FILE *file = fopen("Primes.txt", "w");
	if (NULL != file)
	{
		fprintf (file, "2 " );
		for(int i = 3; i <= size; i += 2 ) {
			if ( numbers[i] != 0) 
			{
				fprintf (file, "%i ", i );
				counter++;
			}
		}
		fclose(file);
		return counter;
	}
	else printf("Smth went wrong..");
	return -1;
}

// take only digits from user
int num_scan( void )
{
	int num = 0, proof = 0;
	do
	{
		proof = scanf("%d", &num);
		if(proof == 1) break;
		printf("Incorrect input, enter int\n");
		fflush(stdin);
	}
	while (1);
	return num;
}
