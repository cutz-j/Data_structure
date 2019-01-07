#include <stdio.h>
#include <stdlib.h>

typedef struct _node {
	int data;
	struct _node * next;
}Node;

int main(void) {
	q4_1_1();
	return 0;
}

int q4_1_1(void) {
	Node * head = NULL;
	Node * tail = NULL;
	Node * cur = NULL;

	Node * newNode = NULL;
	int readData;

	while (1) {
		printf("자연수 입력: ");
		scanf_s("%d", &readData);
		if (readData < 1) {
			break;
		}
		newNode = (Node*)malloc(sizeof(Node));
		newNode->data = readData;
		newNode->next = NULL;

		if (tail == NULL) {
			tail = newNode;
		}
		else {
			newNode->next = head;
		}

		head = newNode;
	}
	printf("\n");
	if (head == NULL) {
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