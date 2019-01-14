#include <stdio.h>
#include <stdlib.h>
#include "CLLBaseStack.h"

int main(void) {																		`
	q6_1_1();
	return 0;
}

int q6_1_1(void) {
	Stack_c Stack;
	StackInit_c(&Stack);
	for (int i = 1; i < 6; i++) {
		SPush_c(&Stack, i);
	}
	while (!SIsEmpty_c(&Stack))
		printf("%d ", SPop_c(&Stack));
	return 0;
}