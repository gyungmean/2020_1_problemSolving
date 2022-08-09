#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define TRUE 1
#define FALSE 0
int pick(int* items, int n, int* bucket, int bucketSize, int k)
{
	int i, lastIndex, smallest, item, sum = 0, count = 0;
	if (k == 0) {
		for (i = 0; i < bucketSize; i++)
			sum += items[bucket[i]];
		if (sum == 0) {
			/*
			for (i = 0; i < bucketSize; i++)
				printf("%d ", items[bucket[i]]);
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
	for (item = smallest; item < n; item++) {
		bucket[lastIndex + 1] = item;
		count += pick(items, n, bucket, bucketSize, k - 1);
	}

	return count;
}
int main(void)
{
	int* items;
	int* bucket;
	int n, m;
	int i;
	scanf("%d", &n);
	scanf("%d", &m);

	items = (int*)malloc(sizeof(int) * n);
	bucket = (int*)malloc(sizeof(int) * m);

	for (i = 0; i < n; i++)
		scanf("%d", &items[i]);

	printf("%d\n", pick(items, n, bucket, m, m));
}
