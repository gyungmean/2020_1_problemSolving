//20190941 ����
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void initArray(int* a, int n)
{
	int i;
	for (i = 0; i < n; i++) {
		a[i] = rand() % 100;
	}
}
void printArray(int* a, int n)
{
	int i;
	for (i = 0; i < n; i++) {
		printf("%d\t", a[i]);
	}
	printf("\n");
}
int sortCheck(int* a, int n)
{
	int i;
	for (i = 0; i < n - 1; i++)
		if (a[i] > a[i + 1])
			return 1;
	return 0;
}
void bubble_sort(int* a, int n)//sorted �÷��� ���� ����ؼ� jfor�� �ȿ��� �÷��� ���
{
	int i, j, temp;

	for (i = 0; i < n - 1; i++) {
		for (j = 0; j < n - 1 - i; j++) {
			if (a[j] > a[j + 1]) {
				temp = a[j + 1];
				a[j + 1] = a[j];
				a[j] = temp;
				}
			}
		printf("i = %d : ", i);
		printArray(a, n);
		if (sortCheck(a, n) == 0)//���� for���� ���� Ȯ���� �ʿ�x
			break;
	}
}
int main()
{
	int n, i;
	int* arr;
	//srand(time(NULL));

	printf("Enter a number: ");
	scanf("%d", &n);
	arr = (int*)malloc(sizeof(int) * n);

	if (!arr) { return 0; }

	initArray(arr, n);
	printf("�ʱ� : ");
	printArray(arr, n);

	bubble_sort(arr, n);
	printf("���� �� :");
	printArray(arr, n);

	free(arr);
}