#include <stdio.h>

int main(void) {
	//bubble_test();
	//selection_test();
	insertion_test();
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
	InsertionSort(arr, sizeof(arr) / sizeof(int));
	for (i = 0; i < 5; i++)
		printf("%d ", arr[i]);
	return 0;
}