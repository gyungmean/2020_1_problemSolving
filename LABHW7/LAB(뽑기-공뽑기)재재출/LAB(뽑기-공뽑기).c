//20190941 ±è°æ¹Î
#include <stdio.h>
void pick(char balls[], int n, int bucket[], int bucketSize, int k)
{
	int i, lastIndex, smallest, item;
	if (k == 0) {
		for (i = 0; i < bucketSize; i++)
			printf("%c ", balls[bucket[i]]);
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
		pick(balls, n, bucket, bucketSize, k - 1);
	}
}
int main()
{
	char balls[7] = { 'A', 'B', 'C', 'D', 'E', 'F', 'G' };
	int bucket[3];

	pick(balls, 7, bucket, 3, 3);
}
