//20190941 ����
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
void pick(int numbers[], int n, int* bucket, int bucketSize, int k)
{
	int i, lastIndex, smallest, item, rslt;
	if (k == 0) {
		rslt = 0;
		for (i = 0; i < bucketSize; i++) {
			if (numbers[bucket[i]] > 0)
				printf("+%d ", numbers[bucket[i]]);
			else
				printf("%d ", numbers[bucket[i]]);
			rslt += numbers[bucket[i]];//���� ��� ���
		}
		printf("= %d ", rslt);
		printf("\n");
		return;
	}

	lastIndex = bucketSize - k - 1;
	if (bucketSize == k)
		smallest = 0;
	else
		smallest = bucket[lastIndex] + 1;
	for (item = smallest; item < n * 2; item++) {
		if (item - bucket[lastIndex] == n) //���밪 ������ ����
			continue;
		bucket[lastIndex + 1] = item;
		pick(numbers, n, bucket, bucketSize, k - 1);
	}
}
int main()
{
	int* numbers;
	int n, i, j;
	int bucket[2];

	printf("Enter a number(1���� n����): ");
	scanf("%d", &n);

	numbers = (int*)malloc(sizeof(int) * n * 2);
	for (i = 0; i < n * 2 / 2; i++)//0���� n * 2 / 2 ���� ��� 1~n
		numbers[i] = i + 1;
	for (j = i, i = 0; j < n * 2; j++)// n * 2 / 2 + 1���� n * ���� ���� -1~-n
		numbers[j] = -numbers[i++];

	pick(numbers, n, bucket, 2, 2);

	free(numbers);
}
