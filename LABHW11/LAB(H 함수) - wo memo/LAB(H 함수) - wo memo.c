//20190941 ����
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
int H(int n)
{
	int i, rslt = 0;
	if (n == 0 || n == 1)
		return 1;
	else
		for (i = 0; i <= n - 1; i++)
			rslt += H(i) * H(n - (i + 1));

	return rslt;
}
int main(void)
{
	int n;
	printf("0���� ū ����: ");
	scanf("%d", &n);
	printf("����� %d\n", H(n));
}