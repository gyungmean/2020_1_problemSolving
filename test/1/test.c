//20190941 ±è°æ¹Î
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void printArray(int* a, int size)
{
	int i;
	for (i = 0; i < size; i++)
		printf("%d ", a[i]);
	printf("\n");
}
void selection_Sort(int* a, int size)
{
	int i, j, maxIdx, temp;
	for (i = 0; i < size - 1; i++) {
		maxIdx = i;
		for (j = i; j <= size - 1; j++) {
			if (a[maxIdx] <= a[j]) {
				maxIdx = j;
			}
		}
		temp = a[i];
		a[i] = a[maxIdx];
		a[maxIdx] = temp;
	}
}
int main()
{
	int array[] = {1,3,4,2,6 };
	printArray(array, 5);
	selection_Sort(array, 5);
	printArray(array, 5);
}