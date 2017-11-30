#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "graph_directed_al.h"

extern listMgr* initializeList(int LitSize);
//extern listMgr* createListMgr();
extern int addData(listMgr*,int,int);
extern int getData(listMgr*, int);
extern int removeData(listMgr*, int);
extern void showAllData(listMgr*);
extern void removeList(listMgr*);

graphDAList* createGDAL(int VertexSize)
{
	graphDAList* pGDAL = (graphDAList*)calloc(1, sizeof(graphDAList));
	if ( pGDAL == NULL ) {
		return NULL;
	}

	pGDAL->vertexSize = VertexSize;
	pGDAL->adjacentList = (listMgr**)calloc(1, sizeof(listMgr*) * VertexSize ) ;
	if ( pGDAL->adjacentList == NULL ) {
		return NULL;
	}

	for( int i = 0 ; i < VertexSize; ++i) {
		pGDAL->adjacentList[i] = initializeList(VertexSize);
	}

	return pGDAL;
}

bool addEdgeGDAL(graphDAList* pGDAL, int TailVertex, int HeadVertex)
{

	if ( pGDAL == NULL ) {
		return false;
	}

	if ( TailVertex >= pGDAL->vertexSize || TailVertex < 0 ) {
		return false;
	}

	if ( HeadVertex >= pGDAL->vertexSize || HeadVertex < 0 ) {
		return false;
	}

	addData(pGDAL->adjacentList[TailVertex], HeadVertex+1, 1); 

	return true;
}

bool removeEdgeGDAL(graphDAList* pGDAL, int TailVertex, int HeadVertex)
{

	if ( pGDAL == NULL ) {
		return false;
	}

	if ( TailVertex >= pGDAL->vertexSize || TailVertex < 0 ) {
		return false;
	}

	if ( HeadVertex >= pGDAL->vertexSize || HeadVertex < 0 ) {
		return false;
	}


	listMgr* pListMgr = pGDAL->adjacentList[TailVertex];
	for( int i = 0 ; i < pGDAL->vertexSize; ++i ) {
		if ( getData(pListMgr, HeadVertex + 1 ) == 1 ) {
			removeData(pListMgr, i);
			break;
		}
	}
	
	return true;
}

bool getEdgeGDAL(graphDAList* pGDAL, int TailVertex, int HeadVertex)
{
	bool bRet = false;
	
	if ( pGDAL == NULL ) {
		return bRet;
	}

	if ( TailVertex >= pGDAL->vertexSize || TailVertex < 0 ) {
		return bRet;
	}

	if ( HeadVertex >= pGDAL->vertexSize || HeadVertex < 0 ) {
		return bRet;
	}

	listMgr* pListMgr = pGDAL->adjacentList[TailVertex];
	for( int i = 0 ; i < pGDAL->vertexSize; ++i ) {
		if ( getData(pListMgr, HeadVertex+1) == 1) {
			bRet = true;
			break;
		}
	}

	return bRet;
}

void deleteGDAL(graphDAList* pGDAL)
{
	if ( pGDAL == NULL ) {
		return ;
	}

	for ( int i = 0; i < pGDAL->vertexSize; ++i ) {
		free( pGDAL->adjacentList[i]);
	}

	free(pGDAL->adjacentList);
	free(pGDAL);
}

void displayGDAL(graphDAList* pGDAL)
{
	if ( pGDAL == NULL ) {
		return;
	}

	for( int i = 0 ; i < pGDAL->vertexSize; ++i ) {
		for ( int j = 0 ; j < pGDAL->vertexSize; ++j ) {
			if ( getEdgeGDAL(pGDAL, i, j ) ) {
				printf("1 ");
			} 
			else {
				printf("0 ");

			}
		}

		printf("\n");
	}
}


