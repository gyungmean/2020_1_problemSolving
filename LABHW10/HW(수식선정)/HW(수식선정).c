//20190941 김경민
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

	lastIndex = bucketSize - k - 1; // 가장 최근에 뽑힌 수가 저장된 위치 i

	smallest = 0; // 중복순열	
	for (i = smallest; i < itemSize; i++) {
		bucket[lastIndex + 1] = items[i];
		found = pick(items, itemSize, bucket, bucketSize, k - 1, n) || found;
		//pick에서 하나라도 발견하게 되면 true임
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

	printf("수를 입력: ");
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