//20190941 김경민
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
int fib(int n, int* F)
{
	if (n == 1 || n == 2) return 1;

	if (F[n - 1] == 1) // memo에서 fn-1 확인
		F[n - 1] = fib(n - 1, F); //memo에 없으면 호출

	if (F[n - 2] == 1) // memo에서 fn-2 확인
		F[n - 2] = fib(n - 2, F); //memo에 없으면 호출

	return F[n - 1] + F[n - 2];
}
int main(void)
{
	int n, i;
	int* F; //memo

	printf("몇 번째까지의 피보나치 수열:");
	scanf("%d", &n); //fn

	//memo 초기화
	F = (int*)malloc(sizeof(int) * (n + 1));
	for (i = 1; i <= n; i++)
		F[i] = 1; // F[1]부터 유의미한 값을 넣음

	F[n] = fib(n, F);

	for (i = 1; i <= n; i++)
		printf("%4d", F[i]);
	printf("\n");

	free(F);
}