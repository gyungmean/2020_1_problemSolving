#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

int pick(int* items, int itemsize, int* bucket, int bucketSize, int k, int cutline)
{
	// 코드 작성
	int number = 0;
	int i, j, lastIndex, smallest, item;
	int total = 0;
	if (k == 0) {
		for (i = 0; i < bucketSize; i++)
			total += items[bucket[i]];
		if (total >= cutline) {
			/*for (j = 0; j < bucketSize; j++)
				printf("%d ", items[bucket[j]]);
			printf("\n");*/
			return 1;
		}
		return 0;
	}

	lastIndex = bucketSize - k - 1;
	if (bucketSize == k)
		smallest = 0;
	else
		smallest = bucket[lastIndex] + 1;
	for (item = smallest; item < itemsize; item++) {
		bucket[lastIndex + 1] = item;
		number += pick(items, itemsize, bucket, bucketSize, k - 1, cutline);
	}
	return number;
}

int main(void)
{
	int* items;
	int* bucket;
	int cutline, n, m;
	int i;

	scanf("%d", &n);
	items = (int*)malloc(sizeof(int) * n);
	for (i = 0; i < n; i++)
		scanf("%d", &items[i]);

	scanf("%d", &m);
	bucket = (int*)malloc(sizeof(int) * m);

	scanf("%d", &cutline);

	printf("%d\n", pick(items, n, bucket, m, m, cutline));
}