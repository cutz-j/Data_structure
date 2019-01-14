#ifndef __CLL_BASE_STACK_H__
#define __CLL_BASE_STACK_H__
#include "CLinkedList.h"

typedef struct _listStack_c {
	List * plist;
}ListStack_c;

typedef ListStack_c Stack_c;
void StackInit_c(Stack_c * pstack);
int SIsEmpty_c(Stack_c * pstack);
void SPush_c(Stack_c * pstack, Data data);
Data SPop_c(Stack_c * pstack);
Data SPeek_c(Stack_c * pstack);

#endif