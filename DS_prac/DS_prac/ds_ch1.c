// recursive binary search //
#include <stdio.h>
int count = 0;

int main(void) {
	int arr[10] = {1,2,3,4,5,6,7,8,9,10};
	int arr2[5000] = { 1, };
	int res;
	res = b_search(arr2, sizeof(arr2)/sizeof(int), 7, 0, 4999);
	printf("%d %d", res, count);
	return 0;
}

int b_search(int arr[], int len, int target, int first, int last) {
	int half = (first + last) / 2;
	printf("%d %d \n", half, arr[half]);
	if (arr[half] == target) {
		count += 1;
		return arr[half];
	}
	else {
		if (first >= last) {
			return -1;
		}
		if (target > arr[half]) {
			count += 1;
			return b_search(arr, len, target, half+1, last);
		}
		else {
			count += 1;
			return b_search(arr, len, target, first, half-1);
		}
	}
	return 0;
}