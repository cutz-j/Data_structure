#include <stdio.h>
#include <string.h>
#include "Graph.h"

int q14_1_1(void) {
	ALGraph graph;
	GraphInit(&graph, 6);
	
	AddEdge(&graph, ����, ����);
	AddEdge(&graph, ����, �μ�);
	AddEdge(&graph, ����, �μ�);
	AddEdge(&graph, �μ�, ����);
	AddEdge(&graph, �μ�, ����);
	AddEdge(&graph, ����, ����);
	AddEdge(&graph, ����, ����);

	ShowGraphEdgeInfo(&graph);
	GraphDestroy(&graph);

	return 0;
}

int main(void) {



	return 0;
}