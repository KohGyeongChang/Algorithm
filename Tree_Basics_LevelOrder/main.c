#include <stdio.h>
#include <stdlib.h>
#include <string.h>

extern void initializeTree();
extern void makeTree();
extern int traverseTree_LevelOrder();

int main()
{
	initializeTree();
	makeTree();
	traverseTree_LevelOrder();

	return 0;
}
