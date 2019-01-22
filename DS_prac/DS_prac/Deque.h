#ifndef __DEQUE_H__
#define __DEQUE_H__

#define TRUE 1
#define FALSE 0

typedef int Data;
typedef struct _node_d {
	Data data;
	struct _node_d * next;
	struct _node_d * prev;
}Node_d;

typedef struct _dldeque {
	Node_d * head;
	Node_d * tail;
}DLDeque;

typedef DLDeque Deque;

void DequeInit(Deque * pdeq);
int DQIsEmpty(Deque * pdeq);
void DQAddFirst(Deque * pdeq, Data data);
void DQAddLast(Deque * pdeq, Data data);
Data DQRemoveFirst(Deque * pdeq);
Data DQRemoveLast(Deque * pdeq);
Data DQGetFirst(Deque * pdeq);
Data DQGetLast(Deque * pdeq);

#endif