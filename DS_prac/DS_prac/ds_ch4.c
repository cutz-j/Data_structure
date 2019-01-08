#include <stdio.h>
#include <stdlib.h>
#include "DLinkedList.h"
#include "Point.h"


int main(void) {
	//q4_1_1();
	//q4_2_1();
	//q4_3_1();
	q4_4_1();
	return 0;
}

int q4_1_1(void) {
	Node * head = NULL;
	Node * tail = NULL;
	Node * cur = NULL;

	Node * newNode = NULL;
	int readData;
	head = (Node *)malloc(sizeof(Node)); // dummy node
	tail = head;

	while (1) {
		printf("자연수 입력: ");
		scanf_s("%d", &readData);
		if (readData < 1) {
			break;
		}
		newNode = (Node*)malloc(sizeof(Node));
		newNode->data = readData;
		newNode->next = NULL;

		tail->next = newNode;
		tail = newNode;
	}
	printf("\n");
	if (head == tail) {
		printf("존재하지 않습니다.\n");
	}
	else {
		cur = head;
		printf("%d", cur->data);
		while (cur->next != NULL) {
			cur = cur->next;
			printf("%d", cur->data);
		}
	}
	printf("\n\n");

	if (head == NULL) {
		return 0;
	}
	else {
		Node * delNode = head;
		Node * delNextNode = head->next;
		printf("%d 삭제\n", head->data);
		free(delNode);
		while (delNextNode != NULL) {
			delNode = delNextNode;
			delNextNode = delNextNode->next;
			printf("\d 삭제\n", delNode->data);
			free(delNode);
		}
	}
	return 0;
}

int q4_2_1(void) {
	Node * head = NULL;
	Node * tail = NULL;
	Node * cur = NULL;

	Node * newNode = NULL;
	int readData;
	head = (Node *)malloc(sizeof(Node));
	tail = head;

	while (1) {
		printf("자연수 입력: ");
		scanf_s("%d", &readData);
		if (readData < 1) {
			break;
		}
		newNode = (Node*)malloc(sizeof(Node));
		newNode->data = readData;
		newNode->next = NULL;

		tail->next = newNode;
		tail = newNode;
	}
	printf("\n");
	if (head == tail) {
		printf("존재하지 않습니다.\n");
	}
	else {
		cur = head;		
		while (cur->next != NULL) {
			cur = cur->next;
			printf("%d", cur->data);
		}
	}
	printf("\n\n");

	if (head == tail) {
		return 0;
	}
	else {
		Node * delNode = head;
		Node * delNextNode = head->next;
		while (delNextNode != NULL) {
			delNode = delNextNode;
			delNextNode = delNextNode->next;
			printf("\d 삭제\n", delNode->data);
			free(delNode);
		}
	}
	return 0;

}

int q4_3_1(void) {
	List list;
	Point compPos;
	Point * ppos;

	ListInit(&list);

	ppos = (Point*)malloc(sizeof(Point));
	SetPointPos(ppos, 5, 1);
	LInsert(&list, ppos);
	ppos = (Point*)malloc(sizeof(Point));
	SetPointPos(ppos, 3, 2);
	LInsert(&list, ppos);
	ppos = (Point*)malloc(sizeof(Point));
	SetPointPos(ppos, 4, 3);
	LInsert(&list, ppos);
	ppos = (Point*)malloc(sizeof(Point));
	SetPointPos(ppos, 3, 4);
	LInsert(&list, ppos);

	printf("현재 데이터 수: %d \n", LCount(&list));

	if (LFirst(&list, &ppos)) {
		ShowPointPos(ppos);
		while (LNext(&list, &ppos))
			ShowPointPos(ppos);
	}
	printf("\n");
	compPos.xpos = 2;
	compPos.ypos = 0;

	if (LFirst(&list, &ppos)) {
		if (PointComp(ppos, &compPos) == 1) {
			LRemove(&list);
		}
		while (LNext(&list, &ppos)) {
			if (PointComp(ppos, &compPos) == 1) {
				LRemove(&list);
			}
		}
	}
	printf("현재 데이터 수: %d \n", LCount(&list));
	if (LFirst(&list, &ppos)) {
		ShowPointPos(ppos);
		while (LNext(&list, &ppos))
			ShowPointPos(ppos);
	}
	printf("\n");

	return 0;
}

int whoisfirst(Point *pos1, Point *pos2) {
	if (pos1->xpos < pos2->xpos)
		return TRUE;
	else if (pos1->xpos == pos2->xpos) {
		if (pos1->ypos < pos2->ypos)
			return TRUE;
		else
			return FALSE;
	}
	else
		return FALSE;
		
}

int q4_4_1(void) {
	List list;
	Point compPos;
	Point * ppos;

	ListInit(&list);
	SetSortRule(&list, whoisfirst); // 정렬의 기준 등록

	ppos = (Point*)malloc(sizeof(Point));
	SetPointPos(ppos, 5, 1);
	LInsert(&list, ppos);
	ppos = (Point*)malloc(sizeof(Point));
	SetPointPos(ppos, 3, 2);
	LInsert(&list, ppos);
	ppos = (Point*)malloc(sizeof(Point));
	SetPointPos(ppos, 4, 3);
	LInsert(&list, ppos);
	ppos = (Point*)malloc(sizeof(Point));
	SetPointPos(ppos, 3, 4);
	LInsert(&list, ppos);

	printf("현재 데이터 수: %d \n", LCount(&list));

	if (LFirst(&list, &ppos)) {
		ShowPointPos(ppos);
		while (LNext(&list, &ppos))
			ShowPointPos(ppos);
	}
	printf("\n");
	compPos.xpos = 2;
	compPos.ypos = 0;

	if (LFirst(&list, &ppos)) {
		if (PointComp(ppos, &compPos) == 1) {
			LRemove(&list);
		}
		while (LNext(&list, &ppos)) {
			if (PointComp(ppos, &compPos) == 1) {
				LRemove(&list);
			}
		}
	}
	printf("현재 데이터 수: %d \n", LCount(&list));
	if (LFirst(&list, &ppos)) {
		ShowPointPos(ppos);
		while (LNext(&list, &ppos))
			ShowPointPos(ppos);
	}
	printf("\n");

	return 0;

	return 0;
}