#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
void echo(int arr[], int arrSize)
{
	int i;
	for (i = 0; i < arrSize; i++) {
		printf("숫자 입력: ");
		scanf("%d", &arr[i]);
	}
}
void reverse(int arr[], int arrSize)
{
	int i;
	for (i = arrSize - 1; i >= 0; i--)
		printf("%d ", arr[i]);
	printf("\n");
}
void printArray(int arr[], int arrSize)
{
	int i;
	for (i = 0; i < arrSize; i++)
		printf("%d ", arr[i]);
	printf("\n");
}
int main()
{
	int arr[5];
	echo(arr, 5);
	printArray(arr, 5);
	reverse(arr, 5);
}