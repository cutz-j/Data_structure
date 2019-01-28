#include <stdio.h>
#include <stdlib.h>
#include "UsefulHeap.h"

void HeapInit_u(Heap * ph, PriorityComp pc) {
	ph->numofData = 0;
	ph->comp = pc;
}

int HIsEmpty_u(Heap * ph) {
	if (ph->numofData == 0)
		return TRUE;
	else
		return FALSE;
}

int GetParentIDX_u(int idx) {
	return idx / 2;
}

int GetLChildIDX_u(int idx) {
	return idx * 2;
}

int GetRChildIDX_u(int idx) {
	return GetLChildIDX_u(idx) + 1;
}

int GetHiPriChildIDX_u(Heap * ph, int idx) {
	if (GetLChildIDX_u(idx) > ph->numofData)
		return 0;
	else if (GetLChildIDX_u(idx) == ph->numofData)
		return GetLChildIDX_u(idx);
	else {
		if (ph->comp(ph->heapArr[GetLChildIDX_u(idx)], ph->heapArr[GetRChildIDX_u(idx)]) < 0)
			return GetRChildIDX_u(idx);
		else
			return GetLChildIDX_u(idx);
	}
}

void HInsert_u(Heap * ph, HData data) {
	int idx = ph->numofData + 1;

	while (idx != 1) {
		if (ph->comp(data, ph->heapArr[GetParentIDX_u(idx)]) > 0) {
			ph->heapArr[idx] = ph->heapArr[GetParentIDX_u(idx)];
			idx = GetParentIDX_u(idx);
		}
		else
			break;
	}
	ph->heapArr[idx] = data;
	ph->numofData += 1;
}

HData HDelete_u(Heap * ph) {
	HData retData = ph->heapArr[1];
	HData lastElem = ph->heapArr[ph->numofData];
	int parentIdx = 1;
	int childIdx;
	while (childIdx = GetHiPriChildIDX_u(ph, parentIdx)) {
		if (ph->comp(lastElem, ph->heapArr[childIdx]) >= 0)
			break;
		ph->heapArr[parentIdx] = ph->heapArr[childIdx];
		parentIdx = childIdx;
	}
	ph->heapArr[parentIdx] = lastElem;
	ph->numofData -= 1;
	return retData;
}






