#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int total(int n);
int main()
{
	int n;
	printf("input a number:");
	scanf("%d", &n);
	printf("1부터 %d까지의 합은 %d\n", n, total(n));
}
int total(int n)
{
	int i, total = 0;
	for (i = 1; i <= n; i++)
		total += i;
	return total;
}
