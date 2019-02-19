#include <stdio.h>
#include "UsefulHeap.h"
#include "QuickSort.h"
#include "RadixSort.h"

int ds_ch10_c(void) {
	//bubble_test();
	////selection_test();
	//insertion_test();
	//heap_test();
	//merge_test();
	//quick_test();
	//radix_test();
	inter_test();
	return 0;
}

void BubbleSort(int arr[], int n) {
	int i, j;
	int temp;
	for (i = 0; i < n-1; i++) {
		for (j = 0; j < (n-i) - 1; j++) {
			if (arr[j] > arr[j + 1]) {
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
}

void SelectionSort(int arr[], int n) {
	int i, j;
	int maxIdx;
	int temp;

	for (i = 0; i < n - 1; i++) {
		maxIdx = i;
		for (j = i + 1; j < n; j++) {
			if (arr[j] < arr[maxIdx])
				maxIdx = j;
		}
		temp = arr[i];
		arr[i] = arr[maxIdx];
		arr[maxIdx] = temp;
	}
}

void InsertionSort(int arr[], int n) {
	int i, j;
	int insData;

	for (i = 1; i < n; i++) {
		insData = arr[i];
		for (j = i - 1; j >= 0; j--) {
			if (arr[j] > insData)
				arr[j + 1] = arr[j];
			else
				break;
		}
		arr[j + 1] = insData;
	}
}


int BSearch(int arr[], int first, int last, int target) {
		int i, j;
		int half = (first + last) / 2;
		if (arr[half] == target)
			return half;
		else if (arr[half] > target)
			if (half - 1 - first <= 1)
				return half;
			else
				return BSearch(arr, first, half, target);
		else if (arr[half] < target)
			if (last - half + 1 <= 1)
				return half;
			return BSearch(arr, half+1, last, target);
}

void B_InsertionSort(int arr[], int n) {
	int i, j;
	int insData, temp;
	int num;

	for (i = 1; i < n; i++) {
		insData = arr[i];
		j = i - 1;
		num = BSearch(arr, 0, j, insData);
		arr[num] = insData;
	}
}

int PriComp(int n1, int n2) {
	return n2 - n1;
}

void HeapSort(int arr[], int n, PriorityComp pc) {
	Heap heap;
	int i;
	HeapInit_u(&heap, pc);
	for (i = 0; i < n; i++)
		HInsert_u(&heap, arr[i]);
	for (i = 0; i < n; i++)
		arr[i] = HDelete_u(&heap);
}

void MergeTwoAreas(int arr[], int left, int mid, int right) {
	int fIdx = left;
	int rIdx = mid+1;
	int i;
	int * sortArr = (int*)malloc(sizeof(int)*(right + 1));
	int sIdx = left;
	while (fIdx <= mid && rIdx <= right) {
		if (arr[fIdx] <= arr[rIdx])
			sortArr[sIdx] = arr[fIdx++];
		else
			sortArr[sIdx] = arr[rIdx++];
		sIdx++;
	}
	if (fIdx > mid) {
		for (i = rIdx; i <= right; i++, sIdx++)
			sortArr[sIdx] = arr[i];
	}
	else {
		for (i = fIdx; i <= mid; i++, sIdx++)
			sortArr[sIdx] = arr[i];
	}
	for (i = left; i <= right; i++)
		arr[i] = sortArr[i];
	free(sortArr);
}

void MergeSort(int arr[], int left, int right) {
	int mid;
	if (left < right) {
		mid = (left + right) / 2;
		MergeSort(arr, left, mid);
		MergeSort(arr, mid + 1, right);
		MergeTwoAreas(arr, left, mid, right);
	}
	
}


int ISearch(int arr[], int first, int last, int target) {
	int i, j;
	int half = ((double)(target - arr[first]) / (arr[last] - arr[first]) * (last - first) + first);
	if (arr[half] == target)
		return half;
	else if (arr[half] > target)
		if (half - 1 - first <= 1)
			return half;
		else
			return ISearch(arr, first, half, target);
	else if (arr[half] < target)
		if (last - half + 1 <= 1)
			return half;
	return ISearch(arr, half + 1, last, target);
}


int bubble_test(void) {
	int arr[4] = { 5,2,1,4 };
	int i;
	BubbleSort(arr, sizeof(arr)/sizeof(int));
	printf("%d %d \n", sizeof(arr), sizeof(int));
	for (i = 0; i < 4; i++)
		printf("%d ", arr[i]);
	return 0;
}

int selection_test(void) {
	int arr[5] = { 5,2,1,4,3 };
	int i;
	SelectionSort(arr, sizeof(arr) / sizeof(int));
	for (i = 0; i < 5; i++)
		printf("%d ", arr[i]);
	return 0;
}

int insertion_test(void) {
	int arr[5] = { 5,2,1,4,3 };
	int i;
	B_InsertionSort(arr, sizeof(arr) / sizeof(int));
	for (i = 0; i < 5; i++)
		printf("%d ", arr[i]);
	return 0;
}

int heap_test(void) {
	int arr[5] = { 5, 2, 1, 4, 3 };
	int i;
	HeapSort(arr, sizeof(arr) / sizeof(int), PriComp);
	for (i = 0; i < 5; i++)
		printf("%d ", arr[i]);
	return 0;
}

int merge_test(void) {
	int arr[7] = { 3, 2, 4, 1, 7,6, 5 };
	int i;

	MergeSort(arr, 0, sizeof(arr) / sizeof(int) - 1);
	for (i = 0; i < 7; i++)
		printf("%d ", arr[i]);
	printf("\n");
	return 0;
}

int quick_test(void) {
	int arr[15] = { 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15 };
	int len = sizeof(arr) / sizeof(int);
	QuickSort(arr, 0, sizeof(arr)/sizeof(int)-1);
	for (int i = 0; i < len; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
	return 0;
}

int radix_test(void) {
	int arr[7] = { 13, 212, 14, 7141, 10987, 6, 15 };
	int len = sizeof(arr) / sizeof(int);
	int i;
	RadixSort(arr, len, 5);
	for (i = 0; i < len; i++)
		printf("%d ", arr[i]);
	printf("\n");

	return 0;
}

int inter_test(void) {
	int arr[5] = { 1,3,5,7,9 };
	int idx;

	idx = ISearch(arr, 0, sizeof(arr) / sizeof(int) - 1, 7);
	if (idx == -1)
		return;
	else
		printf("dix : %d\n", idx);
	return 0;
}