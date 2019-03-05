#ifndef __GRAPH_H__
#define __GRAPH_H__

#include "DLinkedList.h"

enum {����, ����, ����, �μ�, ����, ����};

typedef struct _ual {
	int numV;
	int numE;
	List * adjList;
} ALGraph;

void GraphInit(ALGraph * pg, int nv);

void GraphDestroy(ALGraph * pg);

void AddEdge(ALGraph * pg, int fromV, int toV);

void ShowGraphEdgeInfo(ALGraph * pg);

#endif