#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <stdarg.h>

#include "arraylist.h"

int g_listSize;
int g_currIndex;

void printString(char* FileName, const char* pFuncName, int LineNumber, char* pErrString, ...)
{
	char strBuf[100] = {0};
	va_list ap;
	va_start(ap, pErrString);
	vsprintf(strBuf + strlen(strBuf), pErrString, ap);
	printf("[%s] > [%s() : %d] : %s\n", FileName, pFuncName, LineNumber, strBuf);
	va_end(ap);
}


arrayNode** initializeList(int ListSize)
{
	g_listSize = ListSize;
	g_currIndex = 0;
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
		printString(__FILE__, __func__,__LINE__, "ERROR => Failed to Allocate Memory ");
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
		printString(__FILE__, __func__,__LINE__, "ERROR => arrayList Pointer NULL");
		nRet = ERR_NULL_POINTER;
	}
	else if ( g_currIndex >= g_listSize ) {
		printString(__FILE__, __func__,__LINE__, "LIST FULL => NO MORE DATA : Array List Size[%d], Array Current Size[%d]", g_listSize, g_currIndex);
		nRet = STATUS_LIST_FULL;
	}
	else if ( InsertPos == 0 ) {
		printString(__FILE__, __func__,__LINE__, "ERROR : Input InsertPos[%d]",  InsertPos);
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

bool insertData(arrayNode** arrayList, int Key, char* pData, int InsertPos)
{
	int RetVal = checkValidation(arrayList, InsertPos);

	if ( RetVal != STATUS_OK ) {
		printString(__FILE__, __func__, __LINE__, "ERROR => checkValidation() NOT STATUS_OK");
		return false;
	}

	arrayNode* pNewNode = createArrayNode(Key, pData);

	if ( InsertPos < 0 || ( InsertPos > g_listSize && g_currIndex <  g_listSize  ) ) {
		arrayList[g_currIndex++] = pNewNode;
		return true;
	}

	int index = reorderingList(arrayList, InsertPos);
	arrayList[index] = pNewNode;
	g_currIndex++;

	return true;
}

void displayList(arrayNode** arrayList)
{
	//printString(__FILE__, __func__, __LINE__, "Array List =>List Size [%d] :  Current Size [%d]", g_listSize, g_currIndex);

	for( int i = 0; i < g_listSize; ++i ) {
		if ( arrayList[i] ) {
		 	printString(__FILE__, __func__, __LINE__, "List[%d] => Key[%d]:Data[%s]", i, arrayList[i]->key, arrayList[i]->data); 
		}
	}
	printf("\n");
		

}

