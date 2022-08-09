#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
void insertTheNum(int A[], int size, int num)
{
	// �ڵ� �ۼ�
	int i, j, k, temp;
	for (i = 0; i < size; i++) {
		if (A[i] > num) break;
	}
	for (j = size - 1; j >= i; j--) {
		A[j + 1] = A[j];
	}
	A[i] = num;
}

void printList(int A[], int size)
{
	int i;
	for (i = 0; i < size; i++)
		printf("%d ", A[i]);
	printf("\n");
}

int main(void)
{
	int n;
	int* list;
	int i;
	int newNum;
	scanf("%d", &n);

	// ũ�Ⱑ (n + 1)�� �迭 list�� �������� �����Ѵ�.
	// �ڵ� �ۼ�
	list = (int*)malloc(sizeof(int) * (n + 1));

	for (i = 0; i < n; i++)
		scanf("%d", &list[i]);

	scanf("%d", &newNum);

	insertTheNum(list, n, newNum);
	printList(list, ++n);

	free(list);
}