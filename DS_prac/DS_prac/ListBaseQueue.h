#ifndef __LB_QUEUE_H__
#define __LB_QUEUE_H__

#define TRUE 1
#define FALSE 0

typedef int Data;
typedef struct _node {
	Data data;
	struct _node * next;
}Node;

typedef struct _lQueue {
	Node * front;
	Node * rear;
} LQueue;

typedef LQueue Queue_l;

void QueueInit_l(Queue_l * pq);
int QIsEmpty_l(Queue_l * pq);
void Enqueue_l(Queue_l * pq, Data data);
Data Dequeue_l(Queue_l * pq);
Data QPeek_l(Queue_l * pq);

#endif