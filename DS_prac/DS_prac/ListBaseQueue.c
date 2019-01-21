#include <stdio.h>
#include <stdlib.h>
#include "ListBaseQueue.h"

void QueueInit_l(Queue_l * pq) {
	pq->front = NULL;
	pq->rear = NULL;
}

int QIsEmpty_l(Queue_l * pq) {
	if (pq->front == NULL)
		return TRUE;
	else
		return FALSE;
}

void Enqueue_l(Queue_l * pq, Data data) {
	Node * newNode = (Node *)malloc(sizeof(Node));
	newNode->next = NULL;
	newNode->data = data;

	if (QIsEmpty_l(pq)) {
		pq->front = newNode;
		pq->rear = newNode;
	}
	else {
		pq->rear->next = newNode;
		pq->rear = newNode;
	}
}

Data Dequeue_l(Queue_l * pq) {
	Node * delNode;
	Data retData;

	if (QIsEmpty_l(pq))
		exit(-1);
	delNode = pq->front;
	retData = delNode->data;
	pq->front = pq->front->next;
	free(delNode);
	return retData;
}

Data QPeek_l(Queue_l * pq) {
	if (QIsEmpty_l(pq))
		exit(-1);
	return pq->front->data;
}