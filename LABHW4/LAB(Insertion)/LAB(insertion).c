//20190941 ����
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void insertionSort(int* a, int n)
{
	int i, j, k, temp;
	for (i = 1; i < n; i++) {
		for (j = 0; j < i; j++) {
			if (a[j] > a[i]) break;
		}
		temp = a[i];
		for (k = i - 1; k >= j; k--)
			a[k + 1] = a[k];
		a[j] = temp;//���빮���� ���������� �������� �ű�°͵� �����ؾ���
	}
}
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
int main() {
	int n;
	int* arr;
	srand(time(NULL));

	printf("Enter a number: ");
	scanf("%d", &n);
	arr = (int*)malloc(sizeof(int) * n);

	initArray(arr, n);
	printArray(arr, n);

	insertionSort(arr, n);
	printf("\n���� ��\n");
	printArray(arr, n);

	free(arr);
}