//20190941 김경민
//i랑 j동시진행
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
void swap(int *A, int a, int b)
{
	int temp;
	temp = A[a];
	A[a] = A[b];
	A[b] = temp;
}
int partition(int A[], int start, int end)
{
	int pivot = A[end];
	int i = start - 1;
	int j = start;
	int temp;

	while (j <= end) {
		if (A[j] > pivot)
			j++;
		else {
			swap(A, i + 1, j);
			i++;
			j++;
		}
	}
	//printList(A, end + 1);
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
	int *list;
	int n;

	printf("Enter a number: ");
	scanf("%d", &n);

	list = (int*)malloc(sizeof(int) * n);
	initList(list, n);

	printf("정렬 전: \n");
	printList(list, n);

	quickSort(list, 0, n - 1);

	printf("정렬 후: \n");
	printList(list, n);

	free(list);
}