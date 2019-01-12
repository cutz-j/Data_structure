#ifndef __DB_LINKED_LIST_H__
#define __DB_LINKED_LIST_H__

#define TRUE 1
#define FALSE 0

typedef int Data;
typedef struct _node {
	Data data;
	struct _node *next;
	struct _node *prev;
}Node;

typedef struct _DLinkedList {
	Node *head;
	Node *cur;
	int numOfData;
}DBLinkedList;

typedef DBLinkedList List;

void ListInit_db(List *plist);
void LInsert_db(List * plist, Data data);
int LFirst_db(List * plist, Data *pdata);
int LNext_db(List * plist, Data *pdata);
int LPrevious_db(List * plist, Data * pdata);
int LCount_db(List * plist);


#endif