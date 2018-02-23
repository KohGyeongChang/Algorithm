#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <stdarg.h>
#include "arraylist.h"

int g_listSize;
int g_idxToInsert;

arrayNode** initializeList(int ListSize)
{
	g_listSize = ListSize;
	g_idxToInsert = 0;
	arrayNode** pArrayList = NULL;
	pArrayList = (arrayNode**)calloc(1, sizeof(arrayNode*) * g_listSize);

	return pArrayList;
}

void releaseList(arrayNode** arrayList, int Size)
{
	for(int i = 0; i < g_listSize; ++i) {
		if ( arrayList[i] ) {
			free(arrayList[i]);
			arrayList[i] = NULL;
		}
	}
	free(arrayList);
}

arrayNode* createArrayNode(int Key, char* pData)
{
	arrayNode* pNewNode = (arrayNode*)calloc( 1, sizeof(arrayNode) );
	if ( pNewNode == NULL ) {
		printf("ERROR => Failed to Allocate Memory ");
		return pNewNode;
	}

	pNewNode->key = Key;
	strcpy(pNewNode->data, pData);

	return pNewNode;
}

int checkValidation(arrayNode** arrayList, int InsertPos)
{
	int nRet= STATUS_OK;

	if ( arrayList == NULL ) {
		printf("ERROR => arrayList Pointer NULL");
		nRet = ERR_NULL_POINTER;
	}
	else if ( g_idxToInsert >= g_listSize ) {
		printf("LIST FULL => List Size[%d], Current Size[%d]", g_listSize, g_idxToInsert);
		nRet = STATUS_LIST_FULL;
	}
	else if ( InsertPos == 0 ) {
		printf("ERROR : Input InsertPos[%d]",  InsertPos);
		nRet = ERR_WRONG_INDEX;
	}

	return nRet;
}

int reorderingList(arrayNode** arrayList, int InsertPos) 
{
	int arrayIndex= g_listSize - 1;
	int RepeatCnt = g_listSize - InsertPos;

	while ( RepeatCnt > 0 ) {
		arrayList[arrayIndex]  = arrayList[arrayIndex - 1] ;
		RepeatCnt--;
		arrayIndex--;
	}

	return InsertPos - 1;
}

arrayNode** expandList(arrayNode** arrayList)
{
	if ( arrayList == NULL ) {
		printf("ERROR => Input ArrayList NULL");
		return NULL;
	}

	arrayNode** pArrayList = NULL;
	g_listSize *= 2;
	pArrayList = (arrayNode**)calloc(1, sizeof(arrayNode*) * g_listSize );
	if ( pArrayList == NULL ) {
		printf("ERROR => Failed To Allocate Memory");
		return NULL;
	}

	for( int i = 0; i < g_idxToInsert; ++i) {
		pArrayList[i] = arrayList[i];
	}

	free(arrayList);
	arrayList = NULL;

	return pArrayList;
}

int insertData(arrayNode** arrayList, int Key, char* pData, int InsertPos)
{
	int RetVal = checkValidation(arrayList, InsertPos);

	if ( RetVal != STATUS_OK ) {
		printf("ERROR => NOT STATUS_OK");
		return RetVal;
	}

	arrayNode* pNewNode = createArrayNode(Key, pData);

	if ( InsertPos > 0 && (InsertPos-1) < g_idxToInsert ) {

		int index = reorderingList(arrayList, InsertPos);
		arrayList[index] = pNewNode;
		g_idxToInsert++;

		printf("STATUS=> reorderingList Called : (InsertPos-1)[%d], g_idxToInsert[%d]", InsertPos-1,g_idxToInsert);
	}
	else {
		arrayList[g_idxToInsert++] = pNewNode;
	}

	return RetVal;
}

int findData(arrayNode** arrayList, int Key)
{
	int index = -1;
	for( int i = 0; i < g_idxToInsert; ++i) {
		if ( arrayList[i]->key == Key ) {
			index = i;
			break;
		}
	}

	return index;
}

arrayNode* removeHead(arrayNode** arrayList)
{
	arrayNode* popedNode = NULL;
	popedNode = arrayList[0];
	for( int i  = 1; i < g_idxToInsert; ++i) {
		arrayList[i-1] = arrayList[i];
	}
	arrayList[--g_idxToInsert] = NULL;

	return popedNode;
}

arrayNode* removeTail(arrayNode** arrayList)
{
	arrayNode* popedNode = NULL;
	popedNode = arrayList[--g_idxToInsert];
	arrayList[g_idxToInsert] = NULL;

	return popedNode;
}

arrayNode* popData(arrayNode** arrayList, int Key, int popFlag)
{
	if ( arrayList == NULL ) {
		printString(__FILE__, __func__, __LINE__, "ERROR => arrayList NULL");
		printf("ERROR => arrayList NULL");
		return NULL;
	}

	if ( g_idxToInsert ==  0 ) {
		printf("STATUS => arrayList Empty => Key[%d], popFlag[%d]", Key, popFlag);
		return NULL;
	}

	arrayNode* popedNode = NULL;

	if ( popFlag == 1 ) {
		popedNode = removeHead(arrayList);
	}
	else if ( popFlag == -1 ) {
		popedNode = removeTail(arrayList);
	}
	else if ( popFlag == 0 ) {
		int index = findData(arrayList, Key);

		if ( index == 0 ) {
			popedNode = removeHead(arrayList);
		}
		else if ( index == (g_idxToInsert - 1) ) {
			popedNode = removeTail(arrayList);
		}
		else if ( index < 0 ) {
			printf("ERROR => DATA NOT FOUND : key[%d]", Key);
		}
		else {
			popedNode = arrayList[index];
			for( int i  = index ; i < g_idxToInsert; ++i) {
				arrayList[i] = arrayList[i+1];
			}
			arrayList[--g_idxToInsert] = NULL;
		}
	}
	else {
		printf("ERROR => Undefined  Pop Flag : popFlag[%d]", popFlag);
	}

	return popedNode;
}

void displayList(arrayNode** arrayList)
{
	printf("\n");
	for( int i = 0; i < g_listSize; ++i ) {
		if ( arrayList[i] ) {
		 	printf("List[%d] => Key[%d]:Data[%s]", i, arrayList[i]->key, arrayList[i]->data); 
		}
	}
	printf("\n");
		

}

