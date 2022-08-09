//20190941 ±è°æ¹Î
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
int digits(int n)
{
	int d = 0;
	while (n > 0) {
		n /= 10;
		d++;
	}
	return d;
}
void divideNum(int n, int* newN, int size)
{
	int i;
	for (i = 0; i < size; i++) {
		if (n == 0) newN[i] = 0;
		newN[i] = n % 10;
		n /= 10;
	}
}
int calcCarry(int* n1, int* n2, int s)
{
	int i, carry = 0;

	for (i = 0; i < s; i++) {
		if (n1[i] + n2[i] >= 10) {
			carry++;
			n1[i + 1] += 1;
		}
	}

	return carry;
}
int main()
{
	int n1, n2;
	int carry;
	int size1, size2, size;
	int* newN1;
	int* newN2;

	scanf("%d %d", &n1, &n2);
	if(n1 >= n2) size = digits(n1);
	else size = digits(n2);

	newN1 = (int*)malloc(sizeof(int) * size);
	newN2 = (int*)malloc(sizeof(int) * size);

	divideNum(n1, newN1, size);
	divideNum(n2, newN2, size);
	
	carry = calcCarry(newN1, newN2, size);
	printf("%d\n", carry);
	
}