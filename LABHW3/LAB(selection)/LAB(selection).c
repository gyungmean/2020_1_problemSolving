//20190941 김경민
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void selection_sort(int *a, int n)
{
	int i, j, max, maxIdx, temp;

	for (i = 0; i < n - 1; i++) {
		max = a[0];
		maxIdx = 0;
		//max찾기
		for (j = 0; j <= n - i - 1; j++) {
			if (max <= a[j]) {
				max = a[j];
				maxIdx = j;
			}
		}
		temp = a[n - i - 1];
		a[n - i - 1] = max;
		a[maxIdx] = temp;
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

	if (!arr) { return 0; }

	for (i = 0; i < n; i++) {
		arr[i] = rand() % 1000;
	} //이부분 함수화하기

	for (i = 0; i < n; i++) {
		printf("%d\t", arr[i]);
	}
	printf("\n");
	selection_sort(arr, n);
	printf("정렬된 후:\n");
	for (i = 0; i < n; i++) {
		printf("%d\t", arr[i]);
	}//print도함수
	free(arr);


}