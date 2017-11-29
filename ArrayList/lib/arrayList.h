#ifndef ARRAY_LIST_H  
#define ARRAY_LIST_H  

#define REORDER_INSERT_FRONT 1
#define REORDER_INSERT_RANDOM 0
#define REORDER_INSERT_LAST -1

#define REORDER_DELETE_FRONT 11
#define REORDER_DELETE_RANDOM 10
#define REORDER_DELETE_LAST -11

#define POP_FRONT 1
#define POP_RANDOM 0
#define POP_LAST -1

typedef struct NODE {
	int key;
	char data[20];
} node;


typedef struct LISTMGR {
	int listSize;
	int currSize;
	node** arrayList;
} listMgr;

#endif





