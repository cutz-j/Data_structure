#ifndef __DEQUE_BASE_QUEUE_H__
#define __DEQUE_BASE_QUEUE_H__

#include "Deque.h"

typedef Deque Queue_d;

void QueueInit_d(Queue_d * pq);
int QIsEmpty_d(Queue_d * pq);
void Enqueue_d(Queue_d * pq, Data data);
Data Dequeue_d(Queue_d * pq);
Data QPeek_d(Queue_d * pq);


#endif