//20190941 ����
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
int pick(int* items, int itemSize, int* bucket, int bucketSize, int k, int n) {
	int i, lastIndex, smallest;
	int total = 0;
	int num = 1;
	int found = 0;

	if (k == 0) {
		for (i = 0; i < bucketSize; i++) 
			total += bucket[i] * num++;

		if (total == n) {
			num = 1;
			for (i = 0; i < bucketSize; i++) {
				if (bucket[i] > 0) 
					printf("+%d ", bucket[i] * num++);
				else
					printf("%d ", bucket[i] * num++);
			}
			printf("\n");
			return 1;
		}
		return 0;
	}

	lastIndex = bucketSize - k - 1; // ���� �ֱٿ� ���� ���� ����� ��ġ i

	smallest = 0; // �ߺ�����	
	for (i = smallest; i < itemSize; i++) {
		bucket[lastIndex + 1] = items[i];
		found = pick(items, itemSize, bucket, bucketSize, k - 1, n) || found;
		//pick���� �ϳ��� �߰��ϰ� �Ǹ� true��
		if (found) break;
	}
	return found;
}
int main(void)
{
	int items[] = { 1, -1 };
	int* bucket;
	int n, i;
	int found = 0;
	int bucketSize = 0;
	int k = 0;

	printf("���� �Է�: ");
	scanf("%d", &n);

	for (i = 1; k < n; i++) {
		k += i;
		bucketSize++;
	}

	bucket = (int*)malloc(sizeof(int) * bucketSize);
	for (i = bucketSize; !found; i++) {
		bucket = (int*)malloc(sizeof(int) * i);
		found = pick(items, 2, bucket, i, i, n);
	}

	free(bucket);
}