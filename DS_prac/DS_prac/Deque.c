#include <stdio.h>
#include <stdlib.h>
#include "Deque.h"

void DequeInit(Deque * pdeq) {
	pdeq->head = NULL;
	pdeq->tail = NULL;
}

int DQIsEmpty(Deque * pdeq) {
	if (pdeq->head == NULL) {
		return TRUE;
	}
	else
		return FALSE;
}

void DQAddFirst(Deque * pdeq, Data data) {
	Node_d * newNode = (Node_d *)malloc(sizeof(Node_d));
	newNode->data = data;
	newNode->next = pdeq->head;
	if (DQIsEmpty(pdeq))
		pdeq->tail = newNode;
	else
		pdeq->head->prev = newNode;
	newNode->prev = NULL;
	pdeq->head = newNode;
}

void DQAddLast(Deque * pdeq, Data data) {
	Node_d * newNode = (Node_d *)malloc(sizeof(Node_d));
	newNode->data = data;
	newNode->prev = pdeq->tail;
	if (DQIsEmpty(pdeq))
		pdeq->head = newNode;
	else
		pdeq->tail->next = newNode;
	newNode->next = NULL;
	pdeq->tail = newNode;

}

Data DQRemoveFirst(Deque * pdeq) {
	Node_d * rnode = pdeq->head;
	Data rdata = rnode->data;
	if (DQIsEmpty(pdeq))
		exit(-1);
	pdeq->head = pdeq->head->next;
	free(rnode);
	if (pdeq->head == NULL)
		pdeq->tail = NULL;
	else
		pdeq->head->prev = NULL;
	return rdata;
}

Data DQRemoveLast(Deque * pdeq) {
	Node_d * rnode = pdeq->tail;
	Data rdata = rnode->data;
	if (rnode == NULL)
		exit(-1);
	pdeq->tail = pdeq->tail->prev;
	free(rnode);
	if (pdeq->tail == NULL)
		pdeq->head = NULL;
	else
		pdeq->tail->next = NULL;
	return rdata;
}

Data DQGetFirst(Deque * pdeq) {
	if (DQIsEmpty(pdeq))
		exit(-1);
	return pdeq->head->data;
}

Data DQGetLast(Deque * pdeq) {
	if (DQIsEmpty(pdeq))
		exit(-1);
	return pdeq->tail->data;
}