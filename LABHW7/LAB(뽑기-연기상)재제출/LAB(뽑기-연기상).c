//20190941 ����
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
void pick(char* actors[], int n, int* bucket, int bucketSize, int k)
{
	int i, lastIndex, smallest, item;
	int chosen;
	if (k == 0) {
		for (i = 0; i < bucketSize; i++)
			printf("%s\t", actors[bucket[i]]);
		printf("\n");
		return;
	}

	lastIndex = bucketSize - k - 1;
	smallest = 0;
	for (item = smallest; item < n; item++) {
		chosen = 0;
		for (i = 0; i <= lastIndex; i++) {
			if (bucket[i] == item)
				chosen = 1;
		}
		if (chosen == 0) {
			bucket[lastIndex + 1] = item;
			pick(actors, n, bucket, bucketSize, k - 1);
		}
	}
}
int main()
{
	char* actors[5] = { "����", "�����", "���߱�", "����", "����" };
	int n;
	int* bucket;

	printf("���� ������? ");
	scanf("%d", &n);

	bucket = (int*)malloc(sizeof(int) * n);

	printf("��1\t��2\n");
	pick(actors, 5, bucket, n, n);

	free(bucket);
}
