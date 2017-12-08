#ifndef ARRAY_LIST_H
#define ARRAY_LIST_H

#define ERR_DEFAULT			1000
#define ERR_NULL_POINTER	1010
#define ERR_WRONG_INDEX		1020

#define STATUS_LIST_FULL	2000
#define STATUS_OK			5000



typedef struct ARRAY_NODE {
	int key;
	char data[40];

}arrayNode;


#endif
