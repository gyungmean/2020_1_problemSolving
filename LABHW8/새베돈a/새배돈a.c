//20190941 ����
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
void pick(int* items, int itemsize, int* bucket, int bucketSize, int k, int money) { //�ߺ� ����
	int i, lastIndex, smallest;
	int sum = 0;

	if (k == 0) {
		for (i = 0; i < bucketSize; i++)
			sum += items[bucket[i]];
		if (sum == money) {
			for (i = 0; i < bucketSize; i++)
				printf("%6d ", items[bucket[i]]);
			printf("\n");
		}
		return;
	}

	lastIndex = bucketSize - k - 1; // ���� �ֱٿ� ���� ���� ����� ��ġ index

	if (bucketSize == k)
		smallest = 0;
	else
		smallest = bucket[lastIndex]; // �ߺ�����!!!

	for (i = smallest; i < itemsize; i++) {
		if (smallest <= items[i]) {
			bucket[lastIndex + 1] = i;
			pick(items, itemsize, bucket, bucketSize, k - 1, money);
		}
	}
}
int main(void)
{
	int items[4] = { 0, 1000, 5000, 10000 };
	int* bucket;
	int money, n;

	scanf("%d", &money);
	n = money / 1000;
	bucket = (int*)malloc(sizeof(int) * n);

	pick(items, 4, bucket, n, n, money);

	free(bucket);
}