//20190941 김경민
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char actor[5][10] = { "공유", "김수현", "송중기", "지성", "현빈" };
void pick(int n, char bucket[][10], int bucketSize, int k)
{
	int i, lastIndex, smallest, item;
	int chosen;
	if (k == 0) {
		for (i = 0; i < bucketSize; i++)
			printf("%s\t", bucket[i]);
		printf("\n");
		return;
	}

	lastIndex = bucketSize - k - 1;
	smallest = 0;
	for (item = smallest; item < n; item++) {
		chosen = 0;
		for (i = 0; i <= lastIndex; i++) {
			if (strcmp(bucket[i], actor[item]) == 0)
				chosen = 1;
		}
		if (chosen == 0) {
			strcpy(bucket[lastIndex + 1], actor[item]);
			pick(n, bucket, bucketSize, k - 1);
		}
	}
}
int main()
{
	int n, i;
	char** bucket;

	printf("상의 종류는? ");
	scanf("%d", &n);

	bucket = (char**)malloc(sizeof(char) * n);
	for (i = 0; i < n; i++)
		bucket[i] = (char*)malloc(sizeof(char) * 10);
	printf("상1\t상2\n");

	pick(5, bucket, n, n);

	for (i = 0; i < n; i++)
		free(bucket[i]);
	free(bucket);
}
