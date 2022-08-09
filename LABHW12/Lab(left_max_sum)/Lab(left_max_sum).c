//20190941 ±è°æ¹Î
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int left_max_sum(int A[], int left, int right)
{
	int max = A[right];
	int num = A[right];
	int i;
	for (i = right - 1; i >= left; i--) {
		num += A[i];
		if (max <= num) max = num;
	}
	return max;
}
int main()
{
	int A[] = { -2, 1, -3, 4, -1, 2, 1, -5, 4 };

	int max = left_max_sum(A, 4, 6); // 3
	printf("%d\n", max);
	max = left_max_sum(A, 0, 4); // 3
	printf("%d\n", max);
	max = left_max_sum(A, 4, 7); //-2
	printf("%d\n", max);
}