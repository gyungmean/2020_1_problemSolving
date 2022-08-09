#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
void echo(int arr[], int arrSize)
{
	int i;
	printf("배열 입력: ");
	for (i = 0; i < arrSize; i++) {
		scanf("%d", &arr[i]);
	}
}
int compareArray(int arr1[], int arr1Size, int arr2[], int arr2Size)
{
	int i;
	if (arr1Size != arr2Size)
		return 0;
	else {
		for (i = 0; i < arr1Size; i++)
			if (arr1[i] != arr2[i])
				return 0;
		return 1;
	}
}
int main()
{
	int arr1[5], arr2[5];
	echo(arr1, 5);
	echo(arr2, 5);

	if (compareArray(arr1, 5, arr2, 5) == 1)
		printf("두 개의 배열은 같다\n");
	else
		printf("두 개의 배열은 다르다\n");

}