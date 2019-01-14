#ifndef __C_LINKED_LIST_H__
#define __C_LINKED_LIST_H__
//#include "member.h"

#define TRUE 1
#define FALSE 0

typedef int Data;
//typedef Member *Data;

typedef struct _node {
	Data data;
	struct _node * next;
}Node;

typedef struct _CLL {
	Node * tail;
	Node * cur;
	Node * before;
	int numOfData;
}CList;

typedef CList List;

void ListInit1(List * plist);
void LInsert1(List * plist, Data data);
void LInsertFront1(List * plist, Data data);

int LFirst1(List * plist, Data * pdata);
int LNext1(List * plist, Data * pdata);
Data LRemove1(List * plist);
int LCount1(List * plist);


#endif