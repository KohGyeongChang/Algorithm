#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include "./lib/hash.h"

extern hash* initializeHash(int);
extern void displayHash(hash*, int);
extern bool insert(hash*, int, int);
extern bool delete(hash*, int, int);

#define HASH_SIZE 10 
 
int main()
{
	printf("Hash Test\n");
	
	hash* pHash = initializeHash(HASH_SIZE);

	for( int i = 0; i < HASH_SIZE * 3; ++i ) {
		insert(pHash, i, HASH_SIZE);
	}

	displayHash(pHash, HASH_SIZE);

	printf("\n\n");

	int m = 23;
	printf("Trying To Delete Data[%d]\n", m);
	delete(pHash, m, HASH_SIZE);
	displayHash(pHash, HASH_SIZE);
	printf("\n\n");

	m = 4;
	printf("Trying To Delete Data[%d]\n", m);
	delete(pHash, m, HASH_SIZE);
	displayHash(pHash, HASH_SIZE);
	printf("\n\n");

	m = 25;
	printf("Trying To Delete Data[%d]\n", m);
	delete(pHash, m, HASH_SIZE);
	displayHash(pHash, HASH_SIZE);


	return 0;
}
