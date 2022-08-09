#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
int pick(int* items, int itemsize, int* bucket, int bucketSize, int k, int target) {
	int i, lastIndex, smallest;
	int sum = 0;
	int count = 0;
	int item;

	lastIndex = bucketSize - k - 1; // ���� �ֱٿ� ���� ���� ����� ��ġ index

	for (i = 0; i <= lastIndex; i++)
		sum += items[bucket[i]];

	if (sum >= target) {
		if (k != 0) {
			/*for (i = 0; i <= lastIndex; i++)
				printf("%d ", items[bucket[i]]);
			printf("\n");*/
			count++;
		}
		else if (k == 0) {
			/*for (i = 0; i <= lastIndex; i++)
				printf("%d ", items[bucket[i]]);
			printf("\n");*/
			return 1;
		}
	}

	if (k == 0) // K == 0������ sum < target�ΰ��
		return 0;

	if (bucketSize == k)
		smallest = 0;
	else
		smallest = bucket[lastIndex] + 1; // ������ ���� ��

	// bucket�� items�� ���ҵ��� �����鼭 ��� ȣ��...
	// �ڵ� �ۼ�
	for (item = smallest; item < itemsize; item++) {
		bucket[lastIndex + 1] = item;
		count += pick(items, itemsize, bucket, bucketSize, k - 1, target);
	}
	return count;
}
int main(void)
{
	int n, i;
	int* items;
	int target;
	int* bucket;

	scanf("%d", &n); //������� ��
	items = (int*)malloc(sizeof(int) * n);
	bucket = (int*)malloc(sizeof(int) * n); //����� ������ ���� �����
	for (i = 0; i < n; i++)
		scanf("%d", &items[i]); //������� ���� ��αݾ׼�
	scanf("%d", &target); //��ǥ�ݾ�

	printf("%d ", pick(items, n, bucket, n, n, target)); //����� �� ���
}