#ifndef __USEFUL_HEAP_H__
#define __USEFUL_HEAP_H__

#define TRUE 1
#define FALSE 0
#define HEAP_LEN 100

typedef char * HData;
typedef int Priority;
typedef int PriorityComp(HData * d1, HData * d2);

typedef struct _heap {
	PriorityComp * comp;
	int numofData;
	HData heapArr[HEAP_LEN];
} Heap;

void HeapInit_u(Heap * ph, PriorityComp pc);
int HIsEmpty_u(Heap * ph);
void HInsert_u(Heap * ph, HData data);
HData HDelete_u(Heap * ph);


#endif