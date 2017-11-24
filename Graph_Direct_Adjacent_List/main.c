#include <stdio.h>
#include <stdbool.h>
#include "./lib/graph_directed_al.h"

extern graphDAList* createGDAL(int);
extern bool addEdgeGDAL(graphDAList*, int, int);
extern int getEdgeGDAL(graphDAList*, int, int);
extern bool removeEdgeGDAL(graphDAList*, int, int);
extern void deleteGDAL(graphDAList*);
extern void displayGDAL(graphDAList*);

int main()
{
	printf("Graph Directed Adjacent List Test\n");
	
	graphDAList* pGraph = createGDAL(6);

	addEdgeGDAL(pGraph, 0,1);
	addEdgeGDAL(pGraph, 1,2);
	addEdgeGDAL(pGraph, 2,0);
	addEdgeGDAL(pGraph, 2,3);
	addEdgeGDAL(pGraph, 3,2);
	addEdgeGDAL(pGraph, 3,4);
	addEdgeGDAL(pGraph, 4,5);
	addEdgeGDAL(pGraph, 5,3);

	displayGDAL(pGraph);
	deleteGDAL(pGraph);

	return 0;
}
