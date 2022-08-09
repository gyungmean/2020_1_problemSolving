//20190941 김경민
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
int matrixPath_memo(int** m, int r, int c, int i, int j, int** M, int** M2)
{
	if (i == 0 && j == 0)
		return m[0][0];
	else if (i == 0) {
		if (M2[0][j - 1] != 1) {
			M[0][j - 1] = matrixPath_memo(m, r, c, 0, j - 1, M, M2);
			M2[i][j] = 1;
		}
		return M[0][j - 1] + m[i][j];
	}
	else if (j == 0) {
		if (M2[i - 1][0] != 1) {
			M[i - 1][0] = matrixPath_memo(m, r, c, i - 1, 0, M, M2);
			M2[i][j] = 1;
		}
		return M[i - 1][0] + m[i][j];
	}
	else {
		if (M2[i - 1][j] != 1) {
			M2[i - 1][j] = 1;
			M[i - 1][j] = matrixPath_memo(m, r, c, i - 1, j, M, M2);
		}
		if (M2[i][j - 1] != 1) {
			M2[i][j - 1] = 1;
			M[i][j - 1] = matrixPath_memo(m, r, c, i, j - 1, M, M2);
		}
		return (M[i - 1][j] < M[i][j - 1] ? M[i - 1][j] : M[i][j - 1]) + m[i][j];
	}
}
int main(void)
{
	int** m, ** M; // M은 메모
	int** M2;//BP는 back pointer
	int i, j, r, c;
	r = c = 4; // 4x4 matrix
	m = (int**)malloc(sizeof(int*) * r);
	M = (int**)malloc(sizeof(int*) * r);
	M2 = (int**)malloc(sizeof(int*) * r);
	for (i = 0; i < r; i++) {
		m[i] = (int*)malloc(sizeof(int) * c);
		M[i] = (int*)malloc(sizeof(int) * c);
		M2[i] = (int*)malloc(sizeof(int) * c);
	}
	for (i = 0; i < r; i++)
		for (j = 0; j < c; j++) {
			scanf("%d", &m[i][j]);
			M[i][j] = 0; //메모 초기화
			M2[i][j] = 0;
		}
	printf("%d\n", matrixPath_memo(m, r, c, 3, 3, M, M2));

	for (i = 0; i < r; i++) {
		for (j = 0; j < c; j++) {
			printf("%3d ", M[i][j]);
		}
		printf("\n");
	}
	printf("\n");
	for (i = 0; i < r; i++) {
		for (j = 0; j < c; j++) {
			printf("%3d ", M2[i][j]);
		}
		printf("\n");
	}

	for (i = 0; i < r; i++) {
		free(m[i]);
		free(M[i]);
		free(M2[i]);
	}
	free(m);
	free(M);
	free(M2);

}