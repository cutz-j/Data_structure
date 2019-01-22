#include <stdio.h>
#include <stdlib.h>
#include "DequeBaseQueue.h"

void QueueInit_d(Queue_d * pq) {
	return DequeInit(pq);
}

int QIsEmpty_d(Queue_d * pq) {
	return DQIsEmpty(pq);
}

void Enqueue_d(Queue_d * pq, Data data) {
	return DQAddLast(pq, data);
}

Data Dequeue_d(Queue_d * pq) {
	return DQRemoveFirst(pq);
}

Data QPeek_d(Queue_d * pq) {
	return DQGetFirst(pq);
}