#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
void swap(int A[], int a, int b) // 선택적 사용(필요하면 사용)
{
	int temp;
	temp = A[a];
	A[a] = A[b];
	A[b] = temp;
}
int partition(int A[], int p, int r, int pivot)
{
	// 배열 A[p..r]의 원소들을 pivot을 넣으면서
	// pivot을 기준으로 양쪽으로 재배치하고 
	// pivot이 자리한 위치를 return한다.

	// 코드 작성
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

	// 크기가 (n + 1)인 동적 배열 list 생성
	// 코드 작성
	list = (int*)malloc(sizeof(int) * (n + 1));

	for (i = 0; i < n; i++)
		scanf("%d", &list[i]);

	scanf("%d", &pivot);

	partition(list, 0, n - 1, pivot);
	printList(list, ++n);

	free(list);
}