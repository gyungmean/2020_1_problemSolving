#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int finfKey(int a[], int key);
int main()
{
	int a[5], key, rslt;

	printf("Enter 5���� ����: ");
	scanf("%d %d %d %d %d", &a[0], &a[1], &a[2], &a[3], &a[4]);
	printf("Enter a key: ");
	scanf("%d", &key);
	rslt = findKey(a, key);
	if (rslt == -1)
		printf("����\n");
	else
		printf("%d��°�� �ִ�.\n", rslt + 1);
}
int findKey(int a[], int key)
{
	int i;
	for (i = 0; i < 5; i++)
		if (key == a[i])
			return i;
	return -1;
}