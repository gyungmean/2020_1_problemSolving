//20190941 ±è°æ¹Î
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
void pick(int n, int* bucket, int bucketSize, int k)
{
	int i, lastIndex, smallest, item;
	int chosen;
	if (k == 0) {
		for (i = 0; i < bucketSize; i++)
			printf("%d", bucket[i]);
		printf("\n");
		return;
	}

	lastIndex = bucketSize - k - 1;
	smallest = 0;
	for (item = smallest; item < n; item++) {
		bucket[lastIndex + 1] = item;
		pick(n, bucket, bucketSize, k - 1);
	}
}
int main()
{
	int n;
	int* bucket;

	printf("ÀÚ¸®¼ö ÀÔ·Â: ");
	scanf("%d", &n);
	bucket = (int*)malloc(sizeof(int) * 3);

	pick(4, bucket, n, n);

	free(bucket);
}
