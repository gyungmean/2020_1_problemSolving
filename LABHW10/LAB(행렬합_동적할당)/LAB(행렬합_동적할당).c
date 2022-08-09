//20190941 ����
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
void readMatrix(int **a, int r, int c)
{
	int i, j;
	for (i = 0; i < r; i++) {
		for (j = 0; j < c; j++) {
			scanf("%d", &a[i][j]);
		}
	}
}
void matrixAdd(int **a, int **b, int **x, int r, int c)
{
	int i, j;
	for (i = 0; i < r; i++)
		for (j = 0; j < c; j++)
			x[i][j] = a[i][j] + b[i][j];
}
void printMatrix(int **a, int r, int c)
{
	int i, j;
	for (i = 0; i < r; i++) {
		for (j = 0; j < c; j++)
			printf("%5d", a[i][j]);
		printf("\n");
	}
}
int main(void)
{
	int **A, **B;
	int **X;
	int aRow, aCol;
	int i;

	printf("Enter ��� A�� ��� ���� ����: ");
	scanf("%d %d", &aRow, &aCol);
	A = (int**)malloc(sizeof(int*) * aRow);
	for (i = 0; i < aRow; i++)
		A[i] = (int*)malloc(sizeof(int) * aCol);
	B = (int**)malloc(sizeof(int*) * aRow);
	for (i = 0; i < aRow; i++)
		B[i] = (int*)malloc(sizeof(int) * aCol);

	printf("<%d x %d> ��� A �Է�: \n", aRow, aCol);
	readMatrix(A, aRow, aCol);
	printf("<%d x %d> ��� B �Է�: \n", aRow, aCol);
	readMatrix(B, aRow, aCol);

	X = (int**)malloc(sizeof(int*) * aRow);
	for (i = 0; i < aRow; i++)
		X[i] = (int*)malloc(sizeof(int) * aCol);

	matrixAdd(A, B, X, aRow, aCol);
	printf("�����: \n");
	printMatrix(X, aRow, aCol);

	for (i = 0; i < aRow; i++) {
		free(A[i]);
		free(B[i]);
	}
	free(A);
	free(B);
}