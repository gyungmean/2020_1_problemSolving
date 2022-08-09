//20190941 ±è°æ¹Î
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int H(int n)
{
	int i, result = 0;
	if (n == 0 || n == 1) return 1;
	else
		for (i = 0; i <= n - 1; i++)
			result += H(i) * H(n - (i + 1));
	
	return result;
}
int main() {
	int i;
	scanf("%d", &i);
	printf("%d", H(i));
}