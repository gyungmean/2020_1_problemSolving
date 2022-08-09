//20190941 ±è°æ¹Î
#include <stdio.h>
void pick(int n, char* bucket, int bucketSize, int k)
{
	int i, lastIndex;
	char smallest, item;

	if (k == 0) {
		for (i = 0; i < bucketSize; i++)
			printf("%c ", bucket[i]);
		printf("\n");
		return;
	}

	lastIndex = bucketSize - k - 1;
	if (bucketSize == k)
		smallest = 'A';
	else
		smallest = bucket[lastIndex] + 1;
	for (item = smallest; item < n + 65; item++) {
		bucket[lastIndex + 1] = item;
		pick(n, bucket, bucketSize, k - 1);
	}
}
int main()
{
	int n = 7;
	char bucket[3];

	pick(n, bucket, 3, 3);
}
