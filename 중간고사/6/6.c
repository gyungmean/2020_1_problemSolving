#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
int pick(int* items, int itemsize, int* bucket, int bucketSize, int k, int target) {
	int i, lastIndex, smallest;
	int sum = 0;
	int count = 0;
	int item;

	lastIndex = bucketSize - k - 1; // 가장 최근에 뽑힌 수가 저장된 위치 index

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

	if (k == 0) // K == 0이지만 sum < target인경우
		return 0;

	if (bucketSize == k)
		smallest = 0;
	else
		smallest = bucket[lastIndex] + 1; // 다음에 넣을 돈

	// bucket에 items의 원소들을 넣으면서 재귀 호출...
	// 코드 작성
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

	scanf("%d", &n); //기부자의 수
	items = (int*)malloc(sizeof(int) * n);
	bucket = (int*)malloc(sizeof(int) * n); //기부자 전원이 내는 경우고려
	for (i = 0; i < n; i++)
		scanf("%d", &items[i]); //기부자의 각각 기부금액수
	scanf("%d", &target); //목표금액

	printf("%d ", pick(items, n, bucket, n, n, target)); //경우의 수 출력
}