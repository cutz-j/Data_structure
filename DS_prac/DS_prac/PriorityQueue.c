#include "PriorityQueue.h"
#include "UsefulHeap.h"

void PQueueInit(PQueue * ppq, PriorityComp pc) {
	HeapInit_u(ppq, pc);
}

int PQIsEmpty(PQueue * ppq) {
	return HIsEmpty_u(ppq);
}

void PEnqueue(PQueue * ppq, PQData data) {
	HInsert_u(ppq, data);
}

HData PDequeue(PQueue * ppq) {
	return HDelete_u(ppq);
}