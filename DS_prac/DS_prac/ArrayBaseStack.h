#ifndef __AB_STACK_H__
#define __AB_STACK_H__

#define TRUE 1
#define FALSE 0
#define STACK_LEN 100

typedef int Data;
typedef struct _arracyStack_ab {
	Data stackArr[STACK_LEN];
	int topIndex;
}ArrayStack_ab;

typedef ArrayStack_ab Stack_ab;

void StackInit_ab(Stack_ab * pstack);
int SIsEmpty_ab(Stack_ab * pstack);
void SPush_ab(Stack_ab * pstack, Data data_ab);
Data SPop_ab(Stack_ab * pstack);
Data SPeek(Stack_ab * pstack);

#endif