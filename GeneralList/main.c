#include <stdio.h>
#include <stdlib.h>
#include "./lib/generalList.h"

extern listMgr* initializeList(int ListSize);
extern int addData(listMgr* pListMgr, int pos, int data);
extern int getData(listMgr* pListMgr, int pos);
extern int removeData(listMgr* pListMgr, int pos);
extern void showAllData(listMgr* pListMgr);
extern void removeList(listMgr* pListMgr);

int main()
{
	printf("General List Test\n");

	listMgr* pListMgr = initializeList(LIST_SIZE);

	// Add Data Test 
	for( int i = 0; i < pListMgr->listSize; ++i ) {

		addData(pListMgr, i + 1, (i+1) * (i+1));
	}

	// Show Data Test
	showAllData(pListMgr);

	// Data FULL Test
	addData(pListMgr, 3, 3);

	// Data GET Test 
	int data = getData(pListMgr, 5);
	printf("getData(5) => [%d]\n", data);
	data = getData(pListMgr, 3);
	printf("getData(3) => [%d]\n", data);
	data = getData(pListMgr, 22);
	printf("getData(22) => [%d]\n", data);

	//Memory Free Test 
	removeList(pListMgr);

	return 0;
}
