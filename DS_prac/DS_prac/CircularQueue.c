#include <stdio.h>
#include <stdlib.h>
#include "CircularQueue.h"

void QueueInit_c(Queue_c * pq) {
	pq->front = 0;
	pq->rear = 0;
}

int QIsEmpty_c(Queue_c * pq) {
	if (pq->front == pq->rear)
		return TRUE;
	else
		return FALSE;
}

int NextPosIdx(int pos) {
	if (pos == QUE_LEN - 1)
		return 0;
	else
		return pos + 1;
}

void Enqueue_c(Queue_c * pq, Data data) {
	if (NextPosIdx(pq->rear) == pq->front)
		exit(-1);
	pq->rear = NextPosIdx(pq->rear);
	pq->queArr[pq->rear] = data;
}

Data Dequeue_c(Queue_c * pq) {
	if (QIsEmpty_c(pq))
		exit(-1);
	pq->front = NextPosIdx(pq->front);
	return pq->queArr[pq->front];
}

Data QPeek_c(Queue_c * pq) {
	if (QIsEmpty_c(pq))
		exit(-1);
	return pq->queArr[NextPosIdx(pq->front)];
}






