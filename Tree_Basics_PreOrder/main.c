#include <stdio.h>
#include <stdlib.h>
#include <string.h>

extern void initializeTree();
extern void makeTree();
extern int traverseTree_PreOrder();

int main()
{
	initializeTree();
	makeTree();
	traverseTree_PreOrder();

	return 0;
}
