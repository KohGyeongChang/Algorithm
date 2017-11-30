#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include "./lib/arrayList.h"

#define LIST_SIZE 20

extern listMgr* initializeList(int);
extern bool insertNode(listMgr*, int, char*, int, int);
extern void displayList(listMgr*);
extern void releaseList(listMgr*);
extern int getCurrentLength(listMgr*);
extern node* popNode(listMgr*, int, int);

int main()
{
	printf("Array List Test\n");

	listMgr* pListMgr = initializeList(LIST_SIZE);

	insertNode(pListMgr, 1, "1", REORDER_INSERT_LAST,1);
	insertNode(pListMgr, 2, "2", REORDER_INSERT_LAST,1);
	insertNode(pListMgr, 3, "3", REORDER_INSERT_LAST,1);
	insertNode(pListMgr, 4, "4", REORDER_INSERT_LAST,1);
	insertNode(pListMgr, 5, "5", REORDER_INSERT_FRONT,1);
	printf("Current Length: %d\n", getCurrentLength(pListMgr));
	displayList(pListMgr);

	insertNode(pListMgr, 10, "10", REORDER_INSERT_FRONT,1);
	printf("Current Length: %d\n", getCurrentLength(pListMgr));
	displayList(pListMgr);

	insertNode(pListMgr, 70, "70", REORDER_INSERT_FRONT,1);
	printf("Current Length: %d\n", getCurrentLength(pListMgr));
	displayList(pListMgr);

	insertNode(pListMgr, 45, "45", REORDER_INSERT_RANDOM, 3);
	printf("Current Length: %d\n", getCurrentLength(pListMgr));
	displayList(pListMgr);
	
	node* popedNode = popNode(pListMgr, POP_FRONT, 3);
	printf("Poped Node's key[%d], data[%s]\n", popedNode->key, popedNode->data);
	printf("Current Length: %d\n", getCurrentLength(pListMgr));
	displayList(pListMgr);
	free(popedNode);

	popedNode = popNode(pListMgr, POP_FRONT, 3);
	printf("Poped Node's key[%d], data[%s]\n", popedNode->key, popedNode->data);
	printf("Current Length: %d\n", getCurrentLength(pListMgr));
	displayList(pListMgr);
	free(popedNode);

	popedNode = popNode(pListMgr, POP_RANDOM, 3);
	printf("Poped Node's key[%d], data[%s]\n", popedNode->key, popedNode->data);
	printf("Current Length: %d\n", getCurrentLength(pListMgr));
	displayList(pListMgr);
	free(popedNode);

	return 0;
}
