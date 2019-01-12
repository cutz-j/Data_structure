#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#include "CLinkedList.h"
//#include "member.h"
#include "DBDLinkedList.h"

int main(void) {
	//q5_1_1();
	q5_2_1();
	return 0;
}

//Member * who(List *plist, char *name, int day) {
//	Member *ret;
//	int num = LCount(plist);
//	int i;
//	LFirst(plist, &ret);
//	if (strcmp(ret->name, name) != 0) {
//		for (i = 0; i < num - 1; i++) {
//			LNext(plist, &ret);
//			if (strcmp(ret->name, name) == 0) {
//				break;
//			}
//		}
//		if (i >= num - 1) {
//			return NULL;
//		}
//	}
//	for (i = 0; i < day; i++)
//		LNext(plist, &ret);
//	return ret;
//}
//
//void show(Member * mem) {
//	printf("name: %s \n", mem->name);
//	printf("num: %d \n", mem->num);
//}
//
//int q5_1_1(void) {
//	List list;
//	int data, i, nodeNum;
//	ListInit1(&list);
//	Member * mem;
//	mem = (Member *)malloc(sizeof(Member));
//	mem->num = 111;
//	strcpy_s(mem->name, strlen("aaa")+1, "aaa");
//	LInsert1(&list, mem);
//	
//	mem = (Member *)malloc(sizeof(Member));
//	mem->num = 222;
//	strcpy_s(mem->name, strlen("bbb")+1, "bbb");
//	LInsert1(&list, mem);
//	mem = (Member *)malloc(sizeof(Member));
//	mem->num = 333;
//	strcpy_s(mem->name, strlen("bbb") + 1, "ccc");
//	LInsert1(&list, mem);
//	mem = (Member *)malloc(sizeof(Member));
//	mem->num = 444;
//	strcpy_s(mem->name, strlen("bbb") + 1, "ddd");
//	LInsert1(&list, mem);
//	
//
//	mem = who(&list, "ccc", 2);
//	show(mem);
//
//
//	return 0;
//}

int q5_2_1(void) {
	List list;
	int data;
	ListInit_dbd(&list);

	for (int i = 1; i <= 8; i++) {
		LInsert_dbd(&list, i);
	}

	if (LFirst_dbd(&list, &data)) {
		printf("%d ", data);
		while (LNext_dbd(&list, &data))
			printf("%d ", data);
	}

	if (LFirst_dbd(&list, &data)) {
		if (data % 2 == 0)
			LRemove_dbd(&list);
		while (LNext_dbd(&list, &data)) {
			if (data % 2 == 0)
				LRemove_dbd(&list);
		}
	}
	if (LFirst_dbd(&list, &data)) {
		printf("%d ", data);
		while (LNext_dbd(&list, &data))
			printf("%d ", data);
	}

}