#ifndef HASH_H 
#define HASH_H 

typedef struct HASHNODE {
	int key;
	int data;
	struct HASHNODE* pNextNode;
} hashNode;

typedef struct HASH {
	hashNode* pNode;
}hash;


#endif

