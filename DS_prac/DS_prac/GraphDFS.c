#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "GraphDFS.h"
#include "DLinkedList.h"
#include "ArrayBaseStack.h"

int WhoIsPrecede(int data1, int data2);

void DfsGraphInit(ALGraph * pg, int nv) {
	pg->visitInfo = (int *)malloc(sizeof(int)*pg->numV);
	memset(pg->visitInfo, 0, sizeof(int) * pg->numV);
}

void DfsGraphDestroy(ALGraph * pg) {
	if (pg->visitInfo != NULL)
		free(pg->visitInfo);
}

int VisitVertex(ALGraph * pg, int visitV) {
	if (pg->visitInfo[visitV] == 0) {
		pg->visitInfo[visitV] = 1;
		printf("%c ", visitV + 64);
		return TRUE;
	}
	return FALSE;
}

void DfsShowGraphVertex(ALGraph * pg, int startV) {
	Stack_ab stack;
	int visitV = startV;
	int nextV;

	StackInit_ab(&stack);
	VisitVertext(pg, visitV);
	SPush_ab(&stack, visitV);

	while (LFirst(&(pg->adjList[visitV]), &nextV) == TRUE) {
		int visitFlag = FALSE;
		if (VisitVertex(pg, nextV) == TRUE) {
			SPush_ab(&stack, visitV);
			visitV = nextV;
			visitFlag = TRUE;
		}
		else {
			while (LNext(&(pg->adjList[visitV]), &nextV) == TRUE) {
				if (VisitVertext(pg, nextV) == TRUE) {
					SPush_ab(&stack, visitV);
					visitV = nextV;
					visitFlag = TRUE;
					break;
				}
			}
		}

		if (visitFlag == FALSE) {
			if (SIsEmpty_ab(&stack) == TRUE)
				break;
			else
				visitV = SPop_ab(&stack);
		}

	}

	memset(pg->visitInfo, 0, sizeof(int) * pg->numV);

}

void DfsAddEdge(ALGraph * pg, int fromV, int toV) {
	LInsert(&(pg->adjList[fromV]), toV);
	LInsert(&(pg->adjList[toV]), fromV);
	pg->numE += 1;
}

void DfsShowGraphEdgeInfo(ALGraph * pg) {
	int i;
	int vx;

	for (i = 0; i < pg->numV; i++) {
		printf("%c와 연결된 정점: ", i + 65);

		if (LFirst(&(pg->adjList[i]), &vx)) {
			printf("%c ", vx + 65);
			while (LNext(&(pg->adjList[i]), &vx))
				printf("%c ", vx + 65);
		}
		printf("\n");
	}
}

int WhoIsPrecede(int data1, int data2) {
	if (data1 < data2)
		return 0;
	else
		return 1;
}



















