//20190941 ±è°æ¹Î
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int calculateReverse(int n)
{
	int r = 0;
	while (n > 0) {
		r *= 10;
		r += n % 10;
		n /= 10;
	}

	return r;
}
int findPalindrome(int n, int r)
{
	if (n == r) return 1;
	return 0;
}
int main()
{
	int n, re;
	int count = 0;

	scanf("%d", &n);

	while (1) {
		re = calculateReverse(n);
		if (findPalindrome(n, re)) {
			printf("%d %d\n", count, n);
			break;
		}
		count++;
		n += re;
		if (n < 0) {
			printf("Overflow\n");
			break;
		}
	}
}