//20190941 ±è°æ¹Î
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void bubble_sort(int* a, int n)
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
	}
}
int main()
{
	int n, i;
	int* arr;
	srand(time(NULL));

	printf("Enter a number: ");
	scanf("%d", &n);
	arr = (int*)malloc(sizeof(int) * n);

	if (!arr) { return 0; }

	for (i = 0; i < n; i++) {
		arr[i] = rand() % 1000;
	}

	for (i = 0; i < n; i++) {
		printf("%d\t", arr[i]);
	}
	printf("\n");
	bubble_sort(arr, n);
	printf("Á¤·ÄµÈ ÈÄ:\n");
	for (i = 0; i < n; i++) {
		printf("%d\t", arr[i]);
	}
	free(arr);
}