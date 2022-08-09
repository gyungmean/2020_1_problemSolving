//20190941 ±è°æ¹Î
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void printList(int* a, int n)
{
	int i;
	for (i = 0; i < n; i++) {
		printf("%d\t", a[i]);
	}
	printf("\n");
}
void initList(int* a, int n)
{
	srand(time(NULL));
	int i;
	for (i = 0; i < n; i++) {
		a[i] = rand() % 100;
	}
}
void swap(int* A, int a, int b)
{
	int temp;
	temp = A[a];
	A[a] = A[b];
	A[b] = temp;
}
void selection_sort(int* a, int n)
{
	int i, j, max, maxIdx, temp;

	for (i = 0; i < n - 1; i++) {
		max = a[0];
		maxIdx = 0;
		//maxÃ£±â
		for (j = 0; j <= n - i - 1; j++) {
			if (max <= a[j]) {
				max = a[j];
				maxIdx = j;
			}
		}
		swap(a, n - i - 1, maxIdx);
	}
}
int main(void)
{
	int n, i;
	int* arr;
	srand(time(NULL));

	printf("Enter a number: ");
	scanf("%d", &n);
	arr = (int*)malloc(sizeof(int) * n);

	if (!arr) { return 0; }

	initList(arr, n);
	printList(arr, n);

	selection_sort(arr, n);
	printf("Á¤·ÄµÈ ÈÄ:\n");
	printList(arr, n);

	free(arr);


}