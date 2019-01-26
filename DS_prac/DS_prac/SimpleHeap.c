#include <stdio.h>
#include <stdlib.h>
#include "SimpleHeap.h"

void HeapInit(Heap * ph) {
	ph->numofData = 0;
}

int HIsEmpty(Heap * ph) {
	if (ph->numofData == 0)
		return TRUE;
	else
		return FALSE;
}

int GetParentIDX(int idx) {
	return idx / 2;
}

int GetLChildIDX(int idx) {
	return idx * 2;
}

int GetRChildIDX(int idx) {
	return GetLChildIDX(idx) + 1;
}

int GetHiPriChildIDX(Heap * ph, int idx) {
	if (GetLChildIDX(idx) > ph->numofData)
		return 0;
	else if (GetLChildIDX(idx) == ph->numofData)
		return GetLChildIDX(idx);
	else {
		if (ph->heapArr[GetLChildIDX(idx)].pr > ph->heapArr[GetRChildIDX(idx)].pr)
			return GetRChildIDX(idx);
		else
			return GetLChildIDX(idx);
	}
}

void HInsert(Heap * ph, HData data, Priority pr) {
	int idx = ph->numofData + 1;
	HeapElem nelem = { pr, data };
	while (idx != 1) {
		if (pr < (ph->heapArr[GetParentIDX(idx)].pr)) {
			ph->heapArr[idx] = ph->heapArr[GetParentIDX(idx)];
			idx = GetParentIDX(idx);
		}
		else
			break;
	}
	ph->heapArr[idx] = nelem;
	ph->numofData += 1;
}






