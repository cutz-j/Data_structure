#include <stdio.h>
#include <string.h>
#include "Graph.h"

int q14_1_1(void) {
	ALGraph graph;
	GraphInit(&graph, 6);
	
	AddEdge(&graph, ¼öÁ¤, Á¤Èñ);
	AddEdge(&graph, ¼öÁ¤, ¹Î¼®);
	AddEdge(&graph, Á¤Èñ, ¹Î¼®);
	AddEdge(&graph, ¹Î¼®, ÁöÀ²);
	AddEdge(&graph, ¹Î¼®, Áö¹Î);
	AddEdge(&graph, ÁöÀ², µ¿¼ö);
	AddEdge(&graph, Áö¹Î, µ¿¼ö);

	ShowGraphEdgeInfo(&graph);
	GraphDestroy(&graph);

	return 0;
}

int main(void) {



	return 0;
}