#include <stdio.h>
#include "RadixSort.h"



void RadixSort(int arr[], int num, int maxLen) {
	Queue_l buckets[BUCKET_NUM];
	int bi, pos, di;
	int divfac = 1;
	int radix;

	for (bi = 0; bi < BUCKET_NUM; bi++)
		QueueInit_l(&buckets[bi]);

	for (pos = 0; pos < maxLen; pos++) {
		for (di = 0; di < num; di++) {
			radix = (arr[di] / divfac) % 10;
			Enqueue_l(&buckets[radix], arr[di]);
		}

		for (bi = 0, di = 0; bi < BUCKET_NUM; bi++) {
			while (!QIsEmpty_l(&buckets[bi]))
				arr[di++] = Dequeue_l(&buckets[bi]);
		}
		divfac *= 10;
	}
}