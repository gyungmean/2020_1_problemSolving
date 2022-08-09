//20190941 김경민
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int partition(int A[], int p, int r)
{
	int pivot = A[r];
	int i = p - 1;
	int j = p;
	int temp;

	while (j <= r) {
		if (A[p] > pivot)//A[p] >= pivot
			j++;
		else {
			temp = A[p];
			A[p] = A[i + 1];
			A[i + 1] = temp;
			i++;
			j++;
		}
		p++;
	}

	return i;
}
void quickSort(int A[], int p, int r)
{
	int q;

	if (p < r) {
		q = partition(A, p, r);
		//printList(A,0,9); 넣어서 실험해보고 고치기
		quickSort(A, p, q - 1);
		quickSort(A, q + 1, r);
	}
}
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
int main(void)
{
	int* list;
	int n;

	printf("Enter a number: ");
	scanf("%d", &n);

	list = (int*)malloc(sizeof(int) * n);
	initList(list , n);

	printf("정렬 전: \n");
	printList(list, n);
	
	quickSort(list, 0, n - 1);

	printf("정렬 후: \n");
	printList(list, n);

	free(list);
}