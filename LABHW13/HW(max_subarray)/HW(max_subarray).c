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
int max_subarray(int A[], int left, int right)//Àç±Í
{
	int mid = (left + right) / 2;
	int v1, v2, v3;
	int max;

	if (left == right) return A[left];

	v1 = max_subarray(A, left, mid);
	v2 = max_subarray(A, mid + 1, right);
	v3 = left_max_sum(A, left, mid) + right_max_sum(A, mid + 1, right);

	max = v1;
	if (v2 >= max) {
		max = v2;
	}
	if (v3 >= max) {
		max = v3;
	}

	return max;
}
int main()
{
	int A[] = { -2, 1, -3, 4, -1, 2, 1, -5, 4 }; // tc #1: max´Â 6
	//int A[] = {2, -1, 5, -2, 2, -3, 1}; // tc #2: max´Â 6
	//int A[] = {3, -1, 1, 2, 3, 1, -1, 5}; // tc #3: max´Â 13
	///int A[] = {1, 2, 3}; // tc #4: max´Â 6
	//int A[] = {-1, -2, -3, -4}; //tc #5: max´Â -1
	//int A[] = {5}; // tc #6: max´Â 5

	int lastIndex = sizeof(A) / sizeof(int) - 1;
	int max = max_subarray(A, 0, lastIndex);
	printf("max value = %d\n", max);
}