#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int minOp(int x, int bp[], int c[])
{
	int a, b, c;
	int ax, bx, cx;

	if (x == 1) 
		return 0;

	if (x % 3 == 0) {
		if (bp[x / 3] != -1)
			a = bp[x / 3];
		else {
			a = minOp(x / 3, bp, c);
			bp[x / 3] = a;
		}
	}
	else
		a = 2001;  // ������������ INT_MAX�� �ȵǹǷ� ����� ū ���� ���

	if (x % 2 == 0) {
		if (bp[x / 2] != -1) b = bp[x / 2];
		else {
			b = minOp(x / 2, bp, c);
			bp[x / 2] = b;
		}
	}
	else
		b = 2001;

	if (bp[x - 1] != -1)
		c = bp[x - 1];
	else {
		c = minOp(x - 1, bp, c);
		bp[x - 1] = c;
	}

	// a, b, c�� ���� ���� �����ϸ� ������ Ƚ���� ���ϱ� ���� ���̴� 1�� ���� ��ȯ�Ѵ�.
	if (a <= b)
		if (a <= c) {
			return a + 1;
		}
		else {
			return c + 1;
		}
	else
		if (b <= c) {
			return b + 1;
		}
		else {
			return c + 1;
		}
}

int main(void)
{
	int x;
	int* BP;
	int result;
	int i;
	int* clac;

	scanf("%d", &x);

	BP = (int*)malloc(sizeof(int) * (x + 1));
	clac = (int*)malloc(sizeof(int) * (x + 1));
	for (i = 0; i < x + 1; i++)
		BP[i] = -1;
	result = minOp(x, BP, clac);
	printf("%d\n", result);

	return 0;
}