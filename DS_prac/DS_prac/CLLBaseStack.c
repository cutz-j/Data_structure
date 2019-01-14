#include <stdio.h>
#include <stdlib.h>
#include "CLLBaseStack.h"

void StackInit_c(Stack_c * pstack) {
	pstack->plist = (List *)malloc(sizeof(List));
	ListInit1(pstack->plist);
}

int SIsEmpty_c(Stack_c * pstack) {
	if (LCount1(pstack->plist) == 0)
		return TRUE;
	else
		return FALSE;
}

void SPush_c(Stack_c * pstack, Data data) {
	LInsertFront1(pstack->plist, data);
}

Data SPop_c(Stack_c * pstack) {
	Data data;
	LFirst1(pstack->plist, &data);
	LRemove1(pstack->plist);
	return data;
}

Data SPeek_c(Stack_c * pstack) {
	Data data;
	LFirst1(pstack->plist, &data);
	return data;
}