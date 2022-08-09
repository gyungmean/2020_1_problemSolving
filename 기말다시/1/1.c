#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

void printArray(int a[], int size) // �ʿ��ϸ� ����
{
	int i;
	for (i = 0; i < size; i++)
		printf("%d ", a[i]);
	printf("\n");
}
void solution(int a[], int n)
{
	int i, j, k, temp;
	for (i = 0; i < n; i++) {
		if (a[i] > a[i + 1]) {
			j = 0;
			while (a[j] < a[i + 1])
				j++;
			temp = a[i];
			for (k = i - 1; k >= j; k--)
				a[k + 1] = a[k];
			a[j] = temp;//���빮���� ���������� �������� �ű�°͵� �����ؾ���
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
			stSub[j] += input; //�������
		}
	/*
	printf("���� : ");
	printArray(stSub, student);
	*/

	solution(stSub, student);
	printArray(stSub, student);
}