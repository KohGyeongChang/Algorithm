#include <stdio.h>
#include <stdlib.h>
#include <string.h>

extern void initializeTree();
extern void makeTree();
extern int traverseTree_InOrder();

int main()
{
	initializeTree();
	makeTree();
	traverseTree_InOrder();

	return 0;
}
