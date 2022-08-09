#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
void swap(int A[], int a, int b) // ������ ���(�ʿ��ϸ� ���)
{
	int temp;
	temp = A[a];
	A[a] = A[b];
	A[b] = temp;
}
int partition(int A[], int p, int r, int pivot)
{
	// �迭 A[p..r]�� ���ҵ��� pivot�� �����鼭
	// pivot�� �������� �������� ���ġ�ϰ� 
	// pivot�� �ڸ��� ��ġ�� return�Ѵ�.

	// �ڵ� �ۼ�
	int i = p - 1;
	int j = p;
	A[r + 1] = pivot;

	while (j < r + 1) {
		if (A[j] >= pivot)
			j++;
		else {
			swap(A, i + 1, j);
			i++;
			j++;
		}
	}
	for (i = 0; i < r; i++)
		if (A[i] >= pivot)
			break;

	swap(A, i, r + 1);

	return i;
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
	int pivot;
	scanf("%d", &n);

	// ũ�Ⱑ (n + 1)�� ���� �迭 list ����
	// �ڵ� �ۼ�
	list = (int*)malloc(sizeof(int) * (n + 1));

	for (i = 0; i < n; i++)
		scanf("%d", &list[i]);

	scanf("%d", &pivot);

	partition(list, 0, n - 1, pivot);
	printList(list, ++n);

	free(list);
}