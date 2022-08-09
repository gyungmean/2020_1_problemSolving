//20190941 ����
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
int fib(int n, int* F)
{
	if (n == 1 || n == 2) return 1;

	if (F[n - 1] == 1) // memo���� fn-1 Ȯ��
		F[n - 1] = fib(n - 1, F); //memo�� ������ ȣ��

	if (F[n - 2] == 1) // memo���� fn-2 Ȯ��
		F[n - 2] = fib(n - 2, F); //memo�� ������ ȣ��

	return F[n - 1] + F[n - 2];
}
int main(void)
{
	int n, i;
	int* F; //memo

	printf("�� ��°������ �Ǻ���ġ ����:");
	scanf("%d", &n); //fn

	//memo �ʱ�ȭ
	F = (int*)malloc(sizeof(int) * (n + 1));
	for (i = 1; i <= n; i++)
		F[i] = 1; // F[1]���� ���ǹ��� ���� ����

	F[n] = fib(n, F);

	for (i = 1; i <= n; i++)
		printf("%4d", F[i]);
	printf("\n");

	free(F);
}