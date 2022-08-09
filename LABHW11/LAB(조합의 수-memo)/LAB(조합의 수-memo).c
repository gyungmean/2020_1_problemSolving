//20190941 ±è°æ¹Î
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
int comb(int n, int r)
{
	if (r == 0 || r == n)
		return 1;
	return comb(n - 1, r - 1) + comb(n - 1, r);
}
int main(void)
{
	int C;
	int n, r;

	scanf("%d %d", &n, &r);
	C = comb(n, r);

	printf("%d\n", C);
}