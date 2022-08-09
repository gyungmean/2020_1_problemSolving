//20190941 김경민
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
int H(int n, int *M)
{
	int i, rslt = 0;
	if (n == 0 || n == 1) {
		M[n] = 1;
		return M[n];
	}
	else
		for (i = 0; i <= n - 1; i++) {
			if (M[i] == 0)
				M[i] = H(i, M);
			if(M[n - (i + 1)] == 0)
				M[n - (i + 1)] = H(n - (i + 1), M);

			rslt += M[i] * M[n - (i + 1)];
		}

	return rslt;
}
int main(void)
{
	int n;
	int* M;
	int i;

	printf("0보다 큰 정수: ");
	scanf("%d", &n);

	M = (int*)malloc(sizeof(int) * n);
	for (i = 0; i < n; i++)
		M[i] = 0;

	printf("결과는 %d\n", H(n, M));
	
	free(M);
}