#include <stdio.h>
#include "ArrayList.h"
#include "NameCard.h"

int sub_ch3_c(void) {
	//q3_1_1();
	q3_2_1();
	return 0;
}

int q3_1_1(void) {
	List list;
	int data;
	int sum = 0;
	ListInit(&list);
	for (int i = 1; i < 10; i++) {
		LInsert(&list, i);
	}
	LFirst(&list, &data);
	sum += data;
	for (int i = 2; i < 10; i++) {
		LNext(&list, &data);
		sum += data;
	}
	printf("%d \n", sum);

	if (LFirst(&list, &data)) {
		if (data % 2 == 0 | data % 3 == 0)
			LRemove(&list);
		while (LNext(&list, &data)) {
			if (data % 2 == 0 | data % 3 == 0)
				LRemove(&list);
		}
	}

	if (LFirst(&list, &data)) {
		printf("%d \n", data);
		while (LNext(&list, &data))
			printf("%d \n", data);
	}

	return 0;
}

int q3_2_1(void) {
	List list2;
	NameCard * pcard;
	ListInit(&list2);

	pcard = MakeNameCard("a", "abcd", "010-1111-1111");
	LInsert(&list2, pcard);
	pcard = MakeNameCard("b", "efgh", "010-9339-3888");
	LInsert(&list2, pcard);
	pcard = MakeNameCard("c", "ijkl", "010-3883-8883");
	LInsert(&list2, pcard);
	for (int i = 0; i < 3; i++) {
		pcard = list2.arr[i];
		if (NameCompare(pcard, "efgh") == 0) {
			ShowNameCardInfo(pcard);
			ChangePhoneNum(pcard, "010-9999-9999");
			ShowNameCardInfo(pcard);
			break;
		}
	}
	LFirst(&list2, pcard);
	pcard = LRemove(&list2);
	free(pcard);
	printf("%d \n", LCount(&list2));
	for (int i = 0; i < LCount(&list2); i++) {
		pcard = list2.arr[i];
		ShowNameCardInfo(pcard);
	}
	return 0;
}