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
		a = 2001;  // 엘리스에서는 INT_MAX가 안되므로 충분히 큰 값을 사용

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

	// a, b, c중 작은 값을 선택하며 연산의 횟수를 구하기 위한 것이니 1을 더해 반환한다.
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