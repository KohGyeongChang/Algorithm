#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "doublyLinkedList.h"

extern int initializedoublyLinkedList();
extern void releasedoublyLinkedList();
extern int addData(char* data, int key);
extern int getData(char* bufString, int key);
extern int deleteData(int key);
extern void showAllData();
extern void showAllData_R();

int main()
{
	printf("Single Linked List Test\n");
	initializedoublyLinkedList();
	addData("Start", 2);
	addData("Zero", 22);
	addData("Real", 222);
	showAllData();
	showAllData_R();

	char bufString[40] = { 0 };
	int nRet = -1;
	nRet = getData(bufString, 2);
	if( nRet > -1 ) { 
		printf("Data String : %s\n", bufString);
	}

	nRet = getData(bufString, 22);
	if( nRet > -1 ) { 
		printf("Data String : %s\n", bufString);
	}

	nRet = getData(bufString, 222);
	if( nRet > -1 ) { 
		printf("Data String : %s\n", bufString);
	}

	nRet = getData(bufString, 234);
	if( nRet > -1 ) { 
		printf("Data String : %s\n", bufString);
	}

	deleteData(222);
	showAllData();
	showAllData_R();
	releasedoublyLinkedList();

	return 0;
}
