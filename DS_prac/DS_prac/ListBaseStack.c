#include <stdio.h>
#include <stdlib.h>
#include "ListBaseStack.h"

void StackInit_lb(Stack_lb * pstack) {
	pstack->head = NULL;
}

int SIsEmpty_lb(Stack_lb * pstack) {
	if (pstack->head == NULL)
		return TRUE;
	else
		return FALSE;
}

void SPush_lb(Stack_lb * pstack, Data data) {
	Node_lb * newNode = (Node_lb*)malloc(sizeof(Node_lb));
	newNode->data = data;
	newNode->next = pstack->head;
	pstack->head = newNode;
}

Data SPop_lb(Stack_lb * pstack) {
	Data rdata;
	Node_lb * rnode;

	if (SIsEmpty_lb(pstack))
		exit(-1);
	rdata = pstack->head->data;
	rnode = pstack->head;
	pstack->head = pstack->head->next;
	free(rnode);
	return rdata;
}

Data SPeek_lb(Stack_lb * pstack) {
	if (SIsEmpty_lb(pstack))
		exit(-1);
	return pstack->head->data;
}




