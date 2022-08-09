//20190941 김경민
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
void readMatrix(int** a, int r, int c)
{
	int i, j;
	for (i = 0; i < r; i++) {
		for (j = 0; j < c; j++) {
			scanf("%d", &a[i][j]);
		}
	}
}
void matrixMultiply(int** a, int** b, int** x, int xR, int aC, int xC)
{
	int i, j, k;
	int sum;

	for (i = 0; i < xR; i++) {
		for (j = 0; j < xC; j++) {
			sum = 0;
			for (k = 0; k < aC; k++) {
				sum += a[i][k] * b[k][j];
			}
			x[i][j] = sum;
		}
	}
}
void printMatrix(int** a, int r, int c)
{
	int i, j;
	for (i = 0; i < r; i++) {
		for (j = 0; j < c; j++)
			printf("%5d", a[i][j]);
		printf("\n");
	}
}
void matrixTranspose(int** a, int **t, int r, int c)
{
	int i, j;
	
	for (i = 0; i < r; i++) {
		for (j = 0; j < c; j++)
			t[i][j] = a[j][i];
	}
}
int main(void)
{
	int** A, ** C;
	int** X, ** T;
	int aRow, aCol,cRow, cCol;
	int i;

	printf("Enter 행렬 A의 행과 열의 개수: ");
	scanf("%d %d", &aRow, &aCol);
	A = (int**)malloc(sizeof(int*) * aRow);
	for (i = 0; i < aRow; i++)
		A[i] = (int*)malloc(sizeof(int) * aCol);

	printf("Enter 행렬 C의 행과 열의 개수:(C의 행은 %d이어야) ", aCol);
	scanf("%d %d", &cRow, &cCol);
	C = (int**)malloc(sizeof(int*) * cRow);
	for (i = 0; i < cRow; i++)
		C[i] = (int*)malloc(sizeof(int) * cCol);

	printf("<%d x %d> 행렬 A 입력: \n", aRow, aCol);
	readMatrix(A, aRow, aCol);
	printf("\n<%d x %d> 행렬 C 입력: \n", cRow, cCol);
	readMatrix(C, cRow, cCol);

	X = (int**)malloc(sizeof(int*) * aRow);
	for (i = 0; i < aRow; i++)
		X[i] = (int*)malloc(sizeof(int) * cCol);
	matrixMultiply(A, C, X, aRow, aCol, cCol);

	printf("\n행렬곱: \n");
	printMatrix(X, aRow, cCol);

	T = (int**)malloc(sizeof(int*) * aCol);
	for (i = 0; i < aCol; i++)
		T[i] = (int*)malloc(sizeof(int) * aRow);
	matrixTranspose(A, T, aCol, aRow);

	printf("\n전치행렬: \n");
	printMatrix(T, aCol, aRow);

	for (i = 0; i < aRow; i++)
		free(A[i]);
	for (i = 0; i < cRow; i++)
		free(C[i]);
	for (i = 0; i < aRow; i++)
		free(X[i]);
	for (i = 0; i < aCol; i++)
		free(T[i]);
	free(A);
	free(C);
	free(X);
	free(T);
}