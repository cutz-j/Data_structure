#include <stdio.h>
#include <stdlib.h>
#include "DBLinkedList.h"

void ListInit_db(List * plist) {
	plist->head = NULL;
	plist->numOfData = 0;
}

void LInsert_db(List *plist, Data data) {
	Node * newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;

	newNode->next = plist->head;
	if (plist->head != NULL)
		plist->head->prev = newNode;

	newNode->prev = NULL;
	plist->head = newNode;
	(plist->numOfData)++;
}

int LFirst_db(List *plist, Data *pdata) {
	if (plist->head == NULL)
		return FALSE;
	plist->cur = plist->head;
	*pdata = plist->cur->data;
	return TRUE;
}

int LNext_db(List *plist, Data *pdata) {
	if (plist->cur->next == NULL)
		return FALSE;
	plist->cur = plist->cur->next;
	*pdata = plist->cur->data;
	return TRUE;
}

int LPrevious_db(List *plist, Data *pdata) {
	if (plist->cur->prev == NULL)
		return FALSE;
	plist->cur = plist->cur->prev;
	*pdata = plist->cur->data;
	return TRUE;
}

int LCount_db(List *plist) {
	return plist->numOfData;
}