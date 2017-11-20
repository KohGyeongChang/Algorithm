#include <stdio.h>
#include <stdbool.h>
#include "./lib/graph_directed_al.h"

extern graphDAMatrix* createGDAM(int);
extern bool addEdgeGDAM(graphDAMatrix*, int, int);
extern int getEdgeGDAM(graphDAMatrix*, int, int);
extern bool removeEdgeGDAM(graphDAMatrix*, int, int);
extern void deleteGDAM(graphDAMatrix*);
extern void displayGDAM(graphDAMatrix*);

int main()
{
	printf("Graph Directed Adjacent List Test\n");
	
	graphDAMatrix* pGraph = createGDAM(10);
	addEdgeGDAM(pGraph, 0,1);
	addEdgeGDAM(pGraph, 1,1);
	addEdgeGDAM(pGraph, 4,1);
	addEdgeGDAM(pGraph, 0,1);
	addEdgeGDAM(pGraph, 5,1);
	addEdgeGDAM(pGraph, 5,7);
	addEdgeGDAM(pGraph, 7,1);
	addEdgeGDAM(pGraph, 8,1);
	addEdgeGDAM(pGraph, 8,3);
	addEdgeGDAM(pGraph, 8,8);
	addEdgeGDAM(pGraph, 8,9);
	addEdgeGDAM(pGraph, 9,9);
	addEdgeGDAM(pGraph, 10,1);
	displayGDAM(pGraph);
	deleteGDAM(pGraph);

	return 0;
}
