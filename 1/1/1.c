#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

void printArray(int a[], int size) // 필요하면 쓴다
{
	int i;
	for (i = 0; i < size; i++)
		printf("%d ", a[i]);
	printf("\n");
}
void solution(int a[], int n)
{
	int i, j, temp;

	for (i = 0; i < n - 1; i++) {
		for (j = 0; j < n - 1 - i; j++) {
			if (a[j] < a[j + 1]) {
				temp = a[j + 1];
				a[j + 1] = a[j];
				a[j] = temp;
			}
		}
	}
}
int main(void)
{
	int student, test;
	int i, j, input;
	int* stSub;

	scanf("%d", &test);
	scanf("%d", &student);

	stSub = (int*)malloc(sizeof(int) * student);

	for (i = 0; i < student; i++) {
		stSub[i] = 0;
	}

	for (i = 0; i < test; i++)
		for (j = 0; j < student; j++) {
			scanf("%d", &input);
			stSub[j] += input; //총점계산
		}
	/*
	printf("총점 : ");
	printArray(stSub, student);
	*/

	solution(stSub, student);
	printArray(stSub, student);
}