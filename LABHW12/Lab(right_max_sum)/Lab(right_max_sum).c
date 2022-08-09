//20190941 ±è°æ¹Î
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int right_max_sum(int A[], int left, int right)
{
	int max = A[left];
	int num = A[left];
	int i;
	for (i = left + 1; i <= right; i++) {
		num += A[i];
		if (max <= num) max = num;
	}
	return max;
}
int main()
{
	int A[] = { -2, 1, -3, 4, -1, 2, 1, -5, 4 };

	int max = right_max_sum(A, 3, 5); // 5
	printf("%d\n", max);
	max = right_max_sum(A, 3, 4); // 4
	printf("%d\n", max);
	max = right_max_sum(A, 5, 7); //3
	printf("%d\n", max);
}