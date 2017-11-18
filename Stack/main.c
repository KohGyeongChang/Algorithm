#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "./lib/stack.h"

extern int initializeStack();
extern void releaseStack();
extern int pushData(char* data);
extern int popData(char* popedString);
extern void showAllData();

int main()
{
	printf("Stack Test\n");
	initializeStack();
	pushData("Start");
	pushData("Zero");
	pushData("Real");
	showAllData();

	char popString[40] = { 0 };
	int nRet = -1;
	nRet = popData(popString);
	if( nRet > -1 ) { 
		printf("Poped String : %s\n", popString);
	}

	nRet = popData(popString);
	if( nRet > -1 ) { 
		printf("Poped String : %s\n", popString);
	}

	nRet = popData(popString);
	if( nRet > -1 ) { 
		printf("Poped String : %s\n", popString);
	}

	nRet = popData(popString);
	if( nRet > -1 ) { 
		printf("Poped String : %s\n", popString);
	}
	showAllData();
	releaseStack();

	return 0;
}
