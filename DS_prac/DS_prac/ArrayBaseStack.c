#include <stdio.h>
#include <stdlib.h>
#include "ArrayBaseStack.h"

void StackInit_ab(Stack_ab * pstack) {
	pstack->topIndex = -1;
}

int SIsEmpty_ab(Stack_ab * pstack) {
	if (pstack->topIndex == -1)
		return TRUE;
	else
		return FALSE;
}

void SPush_ab(Stack_ab * pstack, Data data) {
	pstack->topIndex += 1;
	pstack->stackArr[pstack->topIndex] = data;
}

Data SPop_ab(Stack_ab * pstack) {
	int rIdx = pstack->topIndex;
	if (SIsEmpty_ab(pstack))
		exit(-1);
	pstack->topIndex -= 1;
	return pstack->stackArr[pstack->topIndex];
}

Data SPeek_ab(Stack_ab * pstack) {
	if (SIsEmpty_ab(pstack))
		exit(-1);
	return pstack->stackArr[pstack->topIndex];
}