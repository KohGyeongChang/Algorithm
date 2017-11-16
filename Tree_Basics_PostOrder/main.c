#include <stdio.h>
#include <stdlib.h>
#include <string.h>

extern void initializeTree();
extern void makeTree();
extern int traverseTree_PostOrder();

int main()
{
	initializeTree();
	makeTree();
	traverseTree_PostOrder();
	return 0;
}
