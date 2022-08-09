//20190941 ±è°æ¹Î
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int check(int n)
{
	int count = 0;
	while (n % 10 == 1 && n > 0) {
		count++;
		n /= 10;
	}
	if (n == 0) return count;
	return 0;
}
int main()
{
	int A, B, C;
	int rslt;
	scanf("%d", &A);
	B = 1;
	while (1) {
		C = A * B++;
		rslt = check(C);
		if (rslt != 0) break;
	}
	printf("%d\n", rslt);
}