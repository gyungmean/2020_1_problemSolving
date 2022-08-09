//20190941 ±è°æ¹Î
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
int comb(int n, int r, int *M[])
{
	if (r == 0 || r == n) {
		return M[n][r];
	}
	if (M[n - 1][r - 1] == 1)
		M[n - 1][r - 1] = comb(n - 1, r - 1, M);
	if (M[n - 1][r] == 1)
		M[n - 1][r] = comb(n - 1, r, M);

	return M[n - 1][r - 1] + M[n - 1][r];
}
int main(void)
{
	int C;
	int n, r;
	int** M;
	int i, j;

	scanf("%d %d", &n, &r);
	M = (int**)malloc(sizeof(int*) * (n + 1));
	for (i = 0; i <= n; i++)
		M[i] = (int*)malloc(sizeof(int) * (r + 1));

	for (i = 0; i <= n; i++)
		for (j = 0; j <= r; j++)
			M[i][j] = 1;

	C = comb(n, r, M);
	printf("%d\n", C);

	for (i = 0; i <= n; i++)
		free(M[i]);
	free(M);
}