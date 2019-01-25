#ifndef __LB_STACK_H__
#define __LB_STACK_H__
#include "BinaryTree.h"

#define TRUE 1
#define FALSE 0

//typedef int Data;
typedef BTreeNode * Data;
typedef struct _node_lb {
	Data data;
	struct _node_lb * next;
}Node_lb;

typedef struct _listStack_lb {
	Node_lb * head;
}ListStack_lb;

typedef ListStack_lb Stack_lb;
void StackInit_lb(Stack_lb * pstack);
int SIsEmpty_lb(Stack_lb * pstack);
void SPush_lb(Stack_lb * pstack, Data data);
Data SPop_lb(Stack_lb * pstack);
Data SPeek_lb(Stack_lb * pstack);

#endif