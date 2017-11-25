#ifndef GRAPH_DIRECTED_ADJACENTLIST_H
#define GRAPH_DIRECTED_ADJACENTLIST_H

#include "../../Graph_CommLib/generalList.h"

typedef struct GRAPH_DIRECTED_ADJACENTLIST{

	int vertexSize;
	listMgr** adjacentList;

} graphDAList;

#endif

