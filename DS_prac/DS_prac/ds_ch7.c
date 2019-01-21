#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "CircularQueue.h"
#include "ListBaseQueue.h"

int main(void) {
	//c_queue();
	list_q();
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