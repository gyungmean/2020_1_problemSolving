//20190941 ±è°æ¹Î //i-> <-j
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
int partition(int A[], int start, int end)
{
	int pivot = A[end];
	int i = start;
	int j = end - 1;
	int temp;

	while (1) {
		while (A[i] < pivot) {
			i++;
		}
		while (A[j] > pivot) {
			j--;
		}
		if (i >= j)
			break;
		swap(A, i, j);
	}
	swap(A, end, i);

	printList(A, end + 1);
	return i;
}
void quickSort(int A[], int p, int r)
{
	int q;

	if (p < r) {
		q = partition(A, p, r);
		quickSort(A, p, q - 1);
		quickSort(A, q + 1, r);
	}
}
int main(void)
{
	//int* list;
	int list[8] = { 14, 23, 88, 96, 4, 72, 26, 34 };
	int n;

	printf("Enter a number: ");
	scanf("%d", &n);

	//list = (int*)malloc(sizeof(int) * n);
	//initList(list, n);

	printf("Á¤·Ä Àü: \n");
	printList(list, n);

	quickSort(list, 0, n - 1);

	printf("Á¤·Ä ÈÄ: \n");
	printList(list, n);

	//free(list);
}