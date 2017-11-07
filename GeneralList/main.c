#include <stdio.h>
#include <string.h>

typedef struct NODEDATA {

	int data;

} nodeData;

typedef struct LISTMGR{

	int listSize; 
	int currPos;
	nodeData* node;

} listMgr;

listMgr* createList(int ListSize)
{
	listMgr* pListMgr = NULL;

	return pListMgr;
}

int addData(listMgr* pLisMgr, int pos, int data)
{
	return 0;
}

int getData(listMgr* pListMgr, int pos, int data)
{
	return 0;
}

int removeData(listMgr* pListMgr, int pos)
{
	return 0;
}

void showAllData(listMgr* pListMgr)
{

}

void removeList(listMgr* pListMgr)
{

}

int reArrange(listMgr* pListMgr, int startPos)
{
	return 0;
}

int main()
{
	printf("General List Test\n");
	return 0;
}
