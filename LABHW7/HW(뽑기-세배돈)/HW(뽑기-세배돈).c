//20190941 ±è°æ¹Î
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
void pick(int money, int bills[], int n, int bucket[], int bucketSize)
{
	int i;
	if (money == 0) {
		for (i = 0; i < bucketSize; i++)
			printf("%d ", bucket[i]);
		printf("\n");
		return;
	}
	else if (money < 0 || n == 3) {
		return;
	}

	if (money - bills[n] >= 0) {
		bucket[bucketSize] = bills[n];
		pick(money - bills[n], bills, n, bucket, bucketSize + 1);
		pick(money, bills, n + 1, bucket, bucketSize);
	}
}
int main()
{
	int money;
	int bills[3] = { 1000, 5000, 10000 };
	int* bucket;
	int n;

	printf("¼¼¹èµ· ±Ý¾× ÀÔ·Â: ");
	scanf("%d", &money);
	n = money / 1000;
	bucket = (int*)malloc(sizeof(int) * n);

	pick(money, bills, 0, bucket, 0);
}
