#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "graph_directed_al.h"

graphDAMatrix* createGDAM(int VertexSize)
{
	graphDAMatrix* pGDAM = (graphDAMatrix*)calloc(1, sizeof(graphDAMatrix));
	if ( pGDAM == NULL ) {
		return NULL;
	}

	pGDAM->vertexSize = VertexSize;
	pGDAM->adjacentMatrix = (int**)calloc(1, sizeof(int*) * VertexSize ) ;
	if ( pGDAM->adjacentMatrix == NULL ) {
		return NULL;
	}

	for( int i = 0 ; i < VertexSize; ++i) {
		pGDAM->adjacentMatrix[i] = (int*)calloc(1, sizeof(int) * VertexSize);

		if ( pGDAM->adjacentMatrix[i] == NULL ) {
			for( int j = 0; j < i;++j) {
				free(pGDAM->adjacentMatrix[j]);
			}
			return NULL;
		}
	}

	return pGDAM;
}

bool addEdgeGDAM(graphDAMatrix* pGDAM, int TailVertex, int HeadVertex)
{

	if ( pGDAM == NULL ) {
		return false;
	}

	if ( TailVertex >= pGDAM->vertexSize || TailVertex < 0 ) {
		return false;
	}

	if ( HeadVertex >= pGDAM->vertexSize || HeadVertex < 0 ) {
		return false;
	}

	pGDAM->adjacentMatrix[TailVertex][HeadVertex] = 1;

	return true;
}

bool removeEdgeGDAM(graphDAMatrix* pGDAM, int TailVertex, int HeadVertex)
{

	if ( pGDAM == NULL ) {
		return false;
	}

	if ( TailVertex >= pGDAM->vertexSize || TailVertex < 0 ) {
		return false;
	}

	if ( HeadVertex >= pGDAM->vertexSize || HeadVertex < 0 ) {
		return false;
	}

	pGDAM->adjacentMatrix[TailVertex][HeadVertex] = 0;

	return true;
}

int getEdgeGDAM(graphDAMatrix* pGDAM, int TailVertex, int HeadVertex)
{
	
	if ( pGDAM == NULL ) {
		return false;
	}

	if ( TailVertex >= pGDAM->vertexSize || TailVertex < 0 ) {
		return false;
	}

	if ( HeadVertex >= pGDAM->vertexSize || HeadVertex < 0 ) {
		return false;
	}

	return pGDAM->adjacentMatrix[TailVertex][HeadVertex];
}

void deleteGDAM(graphDAMatrix* pGDAM)
{
	if ( pGDAM == NULL ) {
		return ;
	}

	for ( int i = 0; i < pGDAM->vertexSize; ++i ) {
		free( pGDAM->adjacentMatrix[i]);
	}

	free(pGDAM->adjacentMatrix);
	free(pGDAM);
}

void displayGDAM(graphDAMatrix* pGDAM)
{
	if ( pGDAM == NULL ) {
		return;
	}

	for( int i = 0 ; i < pGDAM->vertexSize; ++i ) {
		for ( int j = 0 ; j < pGDAM->vertexSize; ++j ) {
			printf("%d ",getEdgeGDAM(pGDAM, i, j ));
		}

		printf("\n");
	}
}



