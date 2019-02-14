#include "QuickSort.h"
#include <stdio.h>

void Swap_q(int arr[], int idx1, int idx2) {
	int temp = arr[idx1];
	arr[idx1] = arr[idx2];
	arr[idx2] = temp;
}

int Partition_q(int arr[], int left, int right) {
	//int pivot = arr[left];
	int low = left+1;
	int high = right;
	int mid = (left + right) / 2;
	int idx_arr[3] = { left, mid, right };
	if (arr[idx_arr[0]] > arr[idx_arr[1]])
		Swap_q(idx_arr, 0, 1);
	if (arr[idx_arr[1]] > arr[idx_arr[2]])
		Swap_q(idx_arr, 1, 2);
	if (arr[idx_arr[0]] > arr[idx_arr[1]])
		Swap_q(idx_arr, 0, 1);
	int pivot = arr[idx_arr[1]];
	Swap_q(arr, left, idx_arr[1]);
	
	printf("pivot: %d \n", pivot);
	
	while (low <= high) {
		while (pivot >= arr[low] && low <= right)
			low++;
		while (pivot < arr[high] && high >= (left+1))
			high--;
		if (low <= high)
			Swap_q(arr, low, high);
	}
	Swap_q(arr, left, high);
	return high;
}

void QuickSort(int arr[], int left, int right) {
	if (left <= right) {
		int pivot = Partition_q(arr, left, right);
		QuickSort(arr, left, pivot - 1);
		QuickSort(arr, pivot + 1, right);
	}
}