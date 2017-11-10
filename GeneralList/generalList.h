#include <stdio.h>
#include <stdlib.h>

#define LIST_SIZE 30

typedef struct DATALIST {

	int data;

} dataList;

typedef struct LISTMGR{

	int listSize; 
	int currSize;
	dataList* dataList;

} listMgr;



