#ifndef __DBD_LINKED_LIST_H__
#define __DBD_LINKED_LIST_H__

#define TRUE 1
#define FALSE 0

typedef int Data;
typedef struct _node {
	Data data;
	struct _node *next;
	struct _node *prev;
}Node;

typedef struct _DBDLinkedList {
	Node *head;
	Node *tail;
	Node *cur;
	int numOfData;
}DBDLinkedList;

typedef DBDLinkedList List;

void ListInit_dbd(List *plist);
void LInsert_dbd(List * plist, Data data);
int LFirst_dbd(List * plist, Data *pdata);
int LNext_dbd(List * plist, Data *pdata);
int LRemove_dbd(List * plist);
int LCount_dbd(List * plist);


#endif