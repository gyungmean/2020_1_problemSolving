#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int isPrime(int x);
int main()
{
	int i;
	for (i = 2; i <= 30; i++) {
		if (isPrime(i))
			printf("%d ", i);
	}
}
int isPrime(int x) {
	int i;

	for (i = 2; i < x; i++)
		if (x % i == 0)
			return 0;

	return 1;
}