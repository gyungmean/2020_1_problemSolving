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
		if (A[p] > pivot)
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
int find(int A[], int p, int r, int order)//order말고 keyIndex로 바꾸기
{
	int n = partition(A, p, r);

	if (order - 1 == n)
		return A[n];
	else if (order > n)
		find(A, n + 1, r, order);
	else
		find(A, p, n - 1, order);
}
int main(void)
{
	int* list;
	int n;
	int order;

	printf("Enter a number: ");
	scanf("%d", &n);

	list = (int*)malloc(sizeof(int) * n);
	initList(list, n);

	printf("몇번째로 작은 수: ");
	scanf("%d", &order);
;
	printList(list, n);

	printf("%d번째로 작은 수는 %d\n", order, find(list, 0, n - 1, order));

	free(list);
}