//20190941 김경민
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
void bubble_sort(int* a, int n)//sorted 플래그 변수 사용해서 jfor문 안에서 플래그 사용
{
	int i, j, temp, sortCheck;

	for (i = 0; i < n - 1; i++) {
		sortCheck = 0;
		for (j = 0; j < n - 1 - i; j++) {
			if (a[j] > a[j + 1]) {
				temp = a[j + 1];
				a[j + 1] = a[j];
				a[j] = temp;
			}
			else {
				sortCheck++;
			}
		}
		printf("i = %d : ", i);
		printArray(a, n);
		if (sortCheck == n - i - 2)
			break;
	}
}
int main()
{
	int n = 5, i;
	int arr[5] = { 8, 4, 6, 2, 7 };
	//srand(time(NULL));

	printf("Enter a number: ");
	scanf("%d", &n);
	//arr = (int*)malloc(sizeof(int) * n);

	//if (!arr) { return 0; }

	//initArray(arr, n);
	printf("초기 : ");
	printArray(arr, n);

	bubble_sort(arr, n);
	printf("정렬 후 :");
	printArray(arr, n);

	//free(arr);
}