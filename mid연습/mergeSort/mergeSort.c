//20190941 ±è°æ¹Î
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void initArray(int* a, int n)
{
	int i;
	for (i = 0; i < n; i++) {
		a[i] = rand() % 1000;
	}
}
void printArray(int* a, int n)
{
	int i;
	for (i = 0; i < n; i++) {
		printf("%d\t", a[i]);
	}
}
void merge(int* a, int p, int q, int r)
{
	int* temp = (int*)malloc(sizeof(int) * (r - p + 1));
	int i = p, j = q + 1;
	int tempIdx = 0;

	while (i <= q && j <= r)
		if (a[i] <= a[j])
			temp[tempIdx++] = a[i++];
		else
			temp[tempIdx++] = a[j++];

	while (i <= q)
		temp[tempIdx++] = a[i++];

	while (j <= r)
		temp[tempIdx++] = a[j++];

	for (i = p, tempIdx = 0; i <= r; i++)
		a[i] = temp[tempIdx++];

	free(temp);
}
void mergeSort(int* a, int p, int r)
{
	int q;
	if (p < r) {
		q = (p + r) / 2;
		mergeSort(a, p, q);
		mergeSort(a, q + 1, r);
		merge(a, p, q, r);
		//printArray(a, r);
	}
}
int main() {
	int n;
	int* arr;
	srand(time(NULL));

	printf("Enter a number: ");
	scanf("%d", &n);
	arr = (int*)malloc(sizeof(int) * n);

	initArray(arr, n);
	printArray(arr, n);

	mergeSort(arr, 0, n - 1);
	printf("\nÁ¤·Ä ÈÄ\n");
	printArray(arr, n);

	free(arr);
}