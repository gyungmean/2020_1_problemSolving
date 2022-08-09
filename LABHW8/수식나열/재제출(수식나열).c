//20190941 김경민
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
void pick(int* items, int itemSize, int* bucket, int bucketSize, int k, int n) {
	int i, lastIndex, smallest;
	int total = 0;
	int num = 1;

	if (k == 0) {
		for (i = 0; i < bucketSize; i++) {
			if (bucket[i] > 0) {
				printf("+%d ", bucket[i] * num);
				total += bucket[i] * num++;
			}
			else {
				printf("%d ", bucket[i] * num);
				total += bucket[i] * num++;
			}
		}
		printf("= %d", total);
		printf("\n");
		return;
	}

	lastIndex = bucketSize - k - 1; // 가장 최근에 뽑힌 수가 저장된 위치 i

	smallest = 0; // 중복순열	
	for (i = smallest; i < itemSize; i++) {
		bucket[lastIndex + 1] = items[i];
		pick(items, itemSize, bucket, bucketSize, k - 1);
	}
}
int main(void)
{
	int items[] = { 1, -1 };
	int* bucket;
	int n, i;
	int found = 0;
	int bucketSize = 0;
	int k = 0;

	printf("수를 입력");
	scanf("%d", &n);

	for (i = 1; k < n; i++) {
		k += i;
		bucketsize++;
	}
	for (i = bucketSize; !found; i++) {
		found = pick(items, 2, bucket, i, i, n);
	}
}
