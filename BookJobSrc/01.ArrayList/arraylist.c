#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdarg.h>

#include "arraylist.h"

void printErr(const char* pFuncName, char* pErrString)
{
	printf("[%s] : %s\n", pFuncName, pErrString);
}

arrayNode** initializeList(int Size)
{
	arrayNode** pArrayList = NULL;
	pArrayList = (arrayNode**)calloc(1, sizeof(arrayNode*) * Size);

	return pArrayList;
}

void releaseList(arrayNode** pArrayList, int Size)
{
	for(int i = 0; i < Size; ++i) {
		if ( pArrayList[i] ) {
			free(pArrayList[i]);
			pArrayList[i] = NULL;
		}
	}

	free(pArrayList);

}


bool insertData(arrayNode** pArrayList, int Key, char* pData, int InsertFlag, int InsertPos)
{
	if ( (pArrayList == NULL) || (InsertPos < 1 ) || (InsertPos > LISTSIZE) ) {
		printErr(__func__, 
		return false;
	}
	
	return true;
}



