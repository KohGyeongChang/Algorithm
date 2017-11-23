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
	
	graphDAList* pGraph = createGDAL(10);
	addEdgeGDAL(pGraph, 0,1);
	addEdgeGDAL(pGraph, 1,1);
	addEdgeGDAL(pGraph, 4,1);
	addEdgeGDAL(pGraph, 0,1);
	addEdgeGDAL(pGraph, 5,1);
	addEdgeGDAL(pGraph, 5,7);
	addEdgeGDAL(pGraph, 7,1);
	addEdgeGDAL(pGraph, 8,1);
	addEdgeGDAL(pGraph, 8,3);
	addEdgeGDAL(pGraph, 8,8);
	addEdgeGDAL(pGraph, 8,9);
	addEdgeGDAL(pGraph, 9,9);
	addEdgeGDAL(pGraph, 10,1);
	displayGDAL(pGraph);
	deleteGDAL(pGraph);

	return 0;
}
