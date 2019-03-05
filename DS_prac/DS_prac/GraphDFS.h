#ifndef __AL_GRAPH_DFS_H__
#define __AL_GRAPH_DFS_H__

#include "DLinkedList.h"

enum { A, B, C, D, E, F, G };

typedef struct _ual {
	int numV;
	int numE;
	List * adjList;
	int * visitInfo;
} ALGraph;

void DfsInit(ALGraph * pg, int nv);

void DfsDestroy(ALGraph * pg);

void DfsAddEdge(ALGraph * pg, int fromV, int toV);

void DfsShowGraphEdgeInfo(ALGraph * pg);

void DfsShowGraphVertext(ALGraph * pg, int startV);


#endif