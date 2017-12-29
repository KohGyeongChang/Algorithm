#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "hash.h"

void displayList(int [], int);

int createHashKey(int data, int hashSize)
{
	int key = data ^ (data << 1 ) ^ (data >> 1 ) ;
	key = key % hashSize;

	return key;
}

hashNode* createNode(int data, int hashSize) 
{
	hashNode* pNode = (hashNode*)calloc(1, sizeof(hashNode));
	if ( pNode == NULL) {
		return NULL;
	}

	pNode->key = createHashKey(data, hashSize);
	pNode->data = data;

	return pNode;
}

hash* initializeHash(int hashSize)
{
	hash* pHash = (hash*)calloc(1, sizeof(hash) * hashSize);

	for ( int i = 0; i  < hashSize; ++i ) {
		pHash[ i ].pNode = createNode(0, hashSize);
	}

	return pHash;
}

bool handleHashNode(hash* pHash, hashNode* pNewNode)
{
	bool bRet = false;
	if ( pHash == NULL || pNewNode == NULL ) {
		return bRet;
	}

	hashNode* pExistNode = pHash[ pNewNode->key ].pNode->pNextNode;

	if ( pExistNode == NULL ) {
		pHash[ pNewNode->key ].pNode->pNextNode = pNewNode;
		bRet = true;
	}
	else {

		pNewNode->pNextNode = pExistNode->pNextNode;
		pExistNode->pNextNode = pNewNode;
	}

	return bRet;
	
	 
}

bool insert(hash* pHash, int data, int hashSize)
{
	bool bRet = false;
	hashNode* pNewNode = createNode(data, hashSize);

	if ( pNewNode == NULL) {
		return bRet;
	}

	bRet = handleHashNode(pHash, pNewNode);

	return bRet;
}

bool delete(hash* pHash, int data, int hashSize)
{
	if ( pHash == NULL) {
		return false;
	}

	int key = createHashKey(data, hashSize);

	hashNode* pTmpNode = pHash[ key ].pNode;

	if ( pTmpNode == NULL ) {
		return false;
	}

	bool bFound = false;
	while ( pTmpNode->pNextNode ) {

		if ( pTmpNode->pNextNode->data == data ) {
			bFound = true;
			break;
		}
		pTmpNode = pTmpNode->pNextNode;
	}

	if ( !bFound ) {
		printf("data[%04d] : NOT FOUND\n", data);
		return false;
	}

	hashNode* pDeleteNode = pTmpNode->pNextNode;
	pTmpNode->pNextNode = pDeleteNode->pNextNode;

	if ( pDeleteNode ) {
		free( pDeleteNode);
	}
	return true;
}


void displayHash(hash* pHash, int inputSize) 
{
	for ( int i = 0; i < inputSize; ++i ) {
		hashNode* pNode = pHash[ i ].pNode->pNextNode;

		if ( pNode ) {
			while ( pNode ) {
				if ( pNode->key == 0 && pNode->data == 0) {
					pNode = pNode->pNextNode;
					continue;
				}
				printf("Key[%04d]:data[%04d]->", pNode->key, pNode->data);
				pNode = pNode->pNextNode;
			}
		}
		printf("\n");
	}

}
