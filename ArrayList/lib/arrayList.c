#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include "arrayList.h"

void reOrderingInInsert(listMgr* ListMgr, int InsertPos);
void reOrderingInDelete(listMgr* ListMgr, int InsertPos);

node* createNode(int Key, char* pData)
{
	node* pNewNode = (node*)calloc(1, sizeof(node));
	return pNewNode;
}


listMgr* initializeList(int ListSize) 
{
	listMgr* pListMgr = (listMgr*)calloc( 1, sizeof(listMgr));
	if ( pListMgr == NULL ) {
		printf("Error : Failed to calloc listMgr\n");
		return NULL;
	}
	
	node** arrayList = NULL;
	arrayList = (node**)calloc(1, sizeof(node*) * ListSize );

	if ( arrayList == NULL ) {
		printf("Error : Failed to calloc arrayList\n");
		return NULL;
	}

	pListMgr->arrayList = arrayList;
	pListMgr->listSize = ListSize;
	pListMgr->currSize = 0;

	return pListMgr;
}


bool insertNode(listMgr* ListMgr, int Key, char* pData, int InsertFlag, int InsertPos) 
{
	if ( ListMgr == NULL ) {
		printf("Error : Input Parameter [ListMgr] NULL\n"); 
		return false;
	}

	if ( InsertPos > ListMgr->listSize || InsertPos < 1 ) {
		printf("Error : Failed to Insert => ListSize[%d]:InsertPos[%d]\n",ListMgr->listSize, InsertPos );
		return false; 
	}

	if ( ListMgr->currSize == ListMgr->listSize ) {
		printf("Error : Failed to Insert => ArrayList is FULL, ListSize[%d]:CurrSize[%d]\n",
				ListMgr->listSize, ListMgr->currSize);
		return false;
	}

	node* pNewNode = createNode(Key, pData);
	if ( pNewNode == NULL) {
		printf("Error : Failed to calloc node\n");
		return false;
	}

	pNewNode->key = Key;
	strcpy(pNewNode->data, pData);

	if ( InsertFlag == REORDER_INSERT_FRONT || InsertFlag == REORDER_INSERT_RANDOM ) {
		reOrderingInInsert(ListMgr, InsertPos);
		//reOrderingList(ListMgr, InsertFlag, InsertPos);
		ListMgr->arrayList[InsertPos-1] = pNewNode;
		ListMgr->currSize++;

	}
	else if ( InsertFlag == REORDER_INSERT_LAST ) { // Insert To The Last
		ListMgr->arrayList[ListMgr->currSize++] = pNewNode;

	}
	else {
		printf("Error : Wrong Flag....\n");
		return false;
	}


	return true;
}


int findNode(listMgr* ListMgr, int Key)
{
	if ( ListMgr == NULL ) {
		printf("Error : List Mgr is NULL\n");
		return -1;
	}

	int index = 0;	

	for ( int i = 0; i < ListMgr->listSize; ++i ) {
		if( ListMgr->arrayList && ListMgr->arrayList[i] ) {
			if ( ListMgr->arrayList[i]->key == Key ) {
				index = i;
				break;
			}
		}
		else {
			return -1;
		}
	}

	return index;
}


node* popNode(listMgr* ListMgr, int PopFlag, int Key)
{
	if ( ListMgr == NULL || ListMgr->arrayList == NULL ) {
		return NULL;
	}

	node* popedNode = NULL;

	switch ( PopFlag ) {
		
		case POP_FRONT:
			popedNode = ListMgr->arrayList[0];
			ListMgr->arrayList[0] = NULL;
			if (popedNode ) {
				//************************************************************
				// After reOrderingList, Current Size Value should be managed 
				reOrderingInDelete(ListMgr, 1);
				ListMgr->currSize--;
			}
			break;
		case POP_RANDOM:
		{
			int index = findNode(ListMgr,Key); 
			if (index >= 0 ) {
				popedNode = ListMgr->arrayList[index];
				ListMgr->arrayList[index] = NULL;
				if (popedNode ) {
					//************************************************************
					// After reOrderingList, Current Size Value should be managed 
					reOrderingInDelete(ListMgr, index+1);
					ListMgr->currSize--;
				}
			}
		}
			break;
		case POP_LAST:
			popedNode = ListMgr->arrayList[ListMgr->currSize-1];
			if (popedNode ) {
				ListMgr->arrayList[ListMgr->currSize-1] = NULL;
				ListMgr->currSize--;
			}
			break;
		default:
			break;
	}

	return popedNode;
}

bool checkReOrderBoundary(listMgr* ListMgr, int InsertPos)
{
	if ( ListMgr == NULL || InsertPos < 1 ) {
		printf("Error : ListMgr is NULL\n");
		return false;
	}

	if ( InsertPos < 1 ) {
		printf("Error : Wrong InsertPos[%d]\n", InsertPos);
		return false;
	}

	if ( ListMgr->currSize == 0) {
		return false;
	}

	return true;	
}


void reOrderingInInsert(listMgr* ListMgr, int InsertPos)
{
	if ( !checkReOrderBoundary(ListMgr, InsertPos) ) return ;

	int loopCnt = ListMgr->currSize - ( InsertPos - 1 );
	int tmpIndex = ListMgr->currSize;

	while(loopCnt > 0 ) {

		ListMgr->arrayList[tmpIndex] = ListMgr->arrayList[tmpIndex-1]; 

		tmpIndex--;
		loopCnt--;
	}
}


void reOrderingInDelete(listMgr* ListMgr, int InsertPos)
{
	if ( !checkReOrderBoundary(ListMgr, InsertPos) ) return ;

	int loopCnt = ListMgr->currSize - InsertPos;
	int tmpIndex = InsertPos - 1;

	while(loopCnt > 0 ) {

		ListMgr->arrayList[tmpIndex] = ListMgr->arrayList[tmpIndex+1]; 

		tmpIndex++;
		loopCnt--;
	}

	ListMgr->arrayList[tmpIndex] = NULL;

}


bool releaseList(listMgr* ListMgr)
{
	if (ListMgr == NULL ) {
		printf("Error : ListMgr is NULL\n");
		return false;
	}

	if ( ListMgr->arrayList == NULL ) {
		printf("Error : ListMgr->arrayList is NULL\n");
		return false;
	}

	for ( int i =0 ;i < ListMgr->listSize; ++i ) {
		if( ListMgr->arrayList[i] ) {
			free(ListMgr->arrayList[i]);
		}
	}

	free(ListMgr->arrayList);
	ListMgr->arrayList = NULL;

	free(ListMgr);
	ListMgr = NULL;

	return true;
}

int getCurrentLength(listMgr* ListMgr)
{
	if ( ListMgr == NULL ) {
		printf("Error : ListMgr is NULL\n");
		return -1;
	}

	return ListMgr->currSize;
}


void displayList(listMgr* ListMgr) 
{
	if ( ListMgr == NULL ) {
		return;
	}

	for( int i = 0; i < ListMgr->listSize; ++i) {
		if ( ListMgr->arrayList == NULL ) {
			return;
		}

		if ( ListMgr->arrayList[i] ) {
			printf("[%d] %d %s \n", i, ListMgr->arrayList[i]->key, ListMgr->arrayList[i]->data);
		}

	}

	printf("\n\n");

}
