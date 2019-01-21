#ifndef __C_QUEUE_H__
#define __C_QUEUE_H__

#define TRUE 1
#define FALSE 0

#define QUE_LEN 100
typedef int Data;

typedef struct _cQueue {
	int front;
	int rear;
	Data queArr[QUE_LEN];
} CQueue;

typedef CQueue Queue_c;

void QueueInit_c(Queue_c * pq);
int QIsEmpty_c(Queue_c * pq);
void Enqueue_c(Queue_c * pq, Data data);
Data Dequeue_c(Queue_c * pq);
Data QPeek_c(Queue_c * pq);

#endif