#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int multiTwo(int n);
int main()
{
	int n;

	printf("Enter a number:");
	scanf_s("%d", &n);
	printf("%d\n", multiTwo(n));
}
int multiTwo(int n) 
{
	int i, rslt = 1;
	for (i = 0; i < n; i++)
		rslt *= 2;

	return rslt;
}