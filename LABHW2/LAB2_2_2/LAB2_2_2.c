//20190941 ±è°æ¹Î
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int get_cycle_number(int n)
{
	printf("%d ", n);
	if (n == 1)
		return 0;
	if (n % 2 == 0) {
		n /= 2;
	}
	else
		n = n * 3 + 1;

	return get_cycle_number(n) + 1;
}
int main()
{
	int test = 0;
	while (1) {
		scanf("%d", &test);
		if (test == -1)
			break;
		printf("±æÀÌ´Â %d\n", get_cycle_number(test));
	}
}