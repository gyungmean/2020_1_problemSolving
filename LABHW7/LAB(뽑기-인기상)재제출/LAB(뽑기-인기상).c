//20190941 ±è°æ¹Î
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
void pick(char* actors[], int n, int bucket[], int bucketSize, int k)
{
	int i, lastIndex, smallest, item;
	if (k == 0) {
		for (i = 0; i < bucketSize; i++)
			printf("%s\t", actors[bucket[i]]);
		printf("\n");
		return;
	}

	lastIndex = bucketSize - k - 1;
	if (bucketSize == k)
		smallest = 0;
	else
		smallest = bucket[lastIndex] + 1;
	for (item = smallest; item < n; item++) {
		bucket[lastIndex + 1] = item;
		pick(actors, n, bucket, bucketSize, k - 1);
	}
}
int main()
{
	char *actors[5] = { "°øÀ¯", "±è¼öÇö", "¼ÛÁß±â", "Áö¼º", "Çöºó" };
	int n;
	int *bucket;

	printf("ÀÎ±â»ó ¸î ¸í? ");
	scanf("%d", &n);

	bucket = (int*)malloc(sizeof(int) * n);

	pick(actors, 5, bucket, n, n);

	free(bucket);
}
