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

listMgr* createListMgr()
{
	listMgr* pListMgr = (listMgr*)calloc(1, sizeof(listMgr));
	if( pListMgr == NULL ) {
		return NULL;
	}

	return pListMgr;
}

dataList* createList(int ListSize)
{
	dataList* pDataList = (dataList*)calloc(1, sizeof(dataList) * ListSize );
	if( pDataList == NULL ) {
		return NULL;
	}

	return pDataList;
}

listMgr* initializeList(int ListSize)
{
	listMgr* pListMgr =  createListMgr(ListSize);
	if( pListMgr == NULL ) {
		printf("List Magager Memory Allocation FAIL\n");
		return NULL;
	}

	dataList* pDataList = createList(ListSize);
	if( pDataList == NULL ) {
		printf("Data List Memory Allocation FAIL\n");
		return NULL;
	}

	pListMgr->listSize = ListSize;
	pListMgr->currSize = 0;
	pListMgr->dataList = pDataList;

	printf("initializeList SUCCESS\n");

	return pListMgr;
}

int reArrange(listMgr* pListMgr, int Pos)
{
	// Check if List if FULL
	if ( pListMgr->currSize == pListMgr->listSize ) {
		printf("Data List Full\n");
		return -1;
	}

	// Check if Pos is over ListSize 
	if ( Pos > pListMgr->listSize ) {
		printf("Index Error\n");
		return -1;
	}

	//int reArrangeCnt = pListMgr->currSize - arrayIndex + 1;
	int reArrangeCnt = pListMgr->listSize - Pos;

	int tmpArrayIndex = pListMgr->listSize - 1;
	while( reArrangeCnt ) {

		pListMgr->dataList[ tmpArrayIndex ] = pListMgr->dataList[ tmpArrayIndex - 1 ];
		reArrangeCnt--;
		tmpArrayIndex--;
	}

	return  Pos - 1 ;
}

int addData(listMgr* pListMgr, int pos, int data)
{
	int index = reArrange(pListMgr, pos);

	if( index < 0 ) {
		printf("Index reArrange FAIL : Input Pos[%d], Input Data[%d]\n", pos, data);
		return -1;
	}

	pListMgr->dataList[index].data = data;
	pListMgr->currSize++;
	return 0;
}

int getData(listMgr* pListMgr, int pos)
{
	if ( pos > pListMgr->listSize || pos < 1 ) {
		printf("Out of Range\n");
		return -1;
	}

	int data = pListMgr->dataList[pos - 1].data;
	return data;
}

int removeData(listMgr* pListMgr, int pos)
{
	pListMgr->dataList[pos - 1].data = 0;
	pListMgr->currSize--;
	return 0;
}

void showAllData(listMgr* pListMgr)
{
	for( int i = 0; i < pListMgr->listSize; ++i) {
		printf("data List value[%02d] : [%04d]\n",i+1, pListMgr->dataList[i].data);
	}

}

void removeList(listMgr* pListMgr)
{

	free(pListMgr->dataList);
	free(pListMgr);
}


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
