#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "CircularQueue.h"
#include "ListBaseQueue.h"
#include "Deque.h"
#include "DequeBaseQueue.h"

int ds_ch7_c(void) {
	//c_queue();
	//list_q();
	//Dequetest();
	q7_1_1();
	return 0;
}

int c_queue(void) {
	Queue_c q;
	QueueInit_c(&q);
	Enqueue_c(&q, 1);
	Enqueue_c(&q, 2);
	Enqueue_c(&q, 3);
	Enqueue_c(&q, 4);
	Enqueue_c(&q, 5);

	while (!QIsEmpty_c(&q))
		printf("%d ", Dequeue_c(&q));

	return 0;
}

int list_q(void) {
	Queue_l q;
	QueueInit_l(&q);
	Enqueue_l(&q, 1);
	Enqueue_l(&q, 2);
	Enqueue_l(&q, 3);
	Enqueue_l(&q, 4);
	Enqueue_l(&q, 5);

	while (!QIsEmpty_l(&q))
		printf("%d ", Dequeue_l(&q));
	
	return 0;
}

int Dequetest(void) {
	Deque deq;
	DequeInit(&deq);
	DQAddFirst(&deq, 3);
	DQAddFirst(&deq, 2);
	DQAddFirst(&deq, 1);
	DQAddLast(&deq, 4);
	DQAddLast(&deq, 5);
	DQAddLast(&deq, 6);
	while (!DQIsEmpty(&deq))
		printf("%d ", DQRemoveFirst(&deq));
	

	
	return 0;
}

int q7_1_1(void) {
	Queue_d q;
	QueueInit_d(&q);
	Enqueue_d(&q, 1);
	Enqueue_d(&q, 2);
	Enqueue_d(&q, 3);
	Enqueue_d(&q, 4);
	Enqueue_d(&q, 5);
	Enqueue_d(&q, 6);
	while (!QIsEmpty_d(&q))
		printf("%d ", Dequeue_d(&q));

	return 0;
}







