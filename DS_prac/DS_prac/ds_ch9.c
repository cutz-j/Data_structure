#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#include "SimpleHeap.h"
//#include "UsefulHeap.h"
#include "PriorityQueue.h"

int main(void) {
	//simple();
	//useful();
	q9_1_1();

	return 0;
}

//int simple(void) {
//	Heap heap;
//	HeapInit(&heap);
//	HInsert(&heap, 'A', 1);
//	HInsert(&heap, 'B', 2);
//	HInsert(&heap, 'C', 3);
//	printf("%c \n", HDelete(&heap));
//	HInsert(&heap, 'A', 1);
//	HInsert(&heap, 'B', 2);
//	HInsert(&heap, 'C', 3);
//	printf("%c \n", HDelete(&heap));
//	while (!HIsEmpty(&heap))
//		printf("%c \n", HDelete(&heap));
//	return 0;
//}

int DataPriorityComp(char * ch1, char * ch2) {
	return strlen(ch2) - strlen(ch1);
    //return ch1 - ch1;
}


int useful(void) {
	Heap heap;
	HeapInit_u(&heap, DataPriorityComp);
	HInsert_u(&heap, 'A');
	HInsert_u(&heap, 'B');
	HInsert_u(&heap, 'C');
	printf("%c \n", HDelete_u(&heap));
	HInsert_u(&heap, 'A');
	HInsert_u(&heap, 'B');
	HInsert_u(&heap, 'C');
	printf("%c \n", HDelete_u(&heap));
	while (!HIsEmpty_u(&heap))
		printf("%c \n", HDelete_u(&heap));
	return 0;
}

int q9_1_1(void) {
	PQueue pq;
	PQueueInit(&pq, DataPriorityComp);
	PEnqueue(&pq, "hi");
	PEnqueue(&pq, "good morning");
	PEnqueue(&pq, "what's up");
	PEnqueue(&pq, "bye-bye");
	PEnqueue(&pq, "EE");
	PEnqueue(&pq, "bloody hell");
	PEnqueue(&pq, "football");
	PEnqueue(&pq, "happy");
	while (!PQIsEmpty(&pq))
		printf("%s \n", PDequeue(&pq));


	return 0;
}




