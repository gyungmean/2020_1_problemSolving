//20190941 ±è°æ¹Î
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void printArray(int* a, int n)
{
	int i;
	for (i = 0; i < n; i++) {
		printf("%d\t", a[i]);
	}
}
void initArray(int* a, int n)
{
	int i;
	for (i = 0; i < n; i++) {
		a[i] = rand() % 1000;
	}
}
int main(void)
{
	int n, i;
	int* arr;
	srand(time(NULL));

	printf("Enter a number: ");
	scanf("%d", &n);
	arr = (int*)malloc(sizeof(int) * n);

	initArray(arr, n);
	printArray(arr, n);
	printf("\n");

	free(arr);


}