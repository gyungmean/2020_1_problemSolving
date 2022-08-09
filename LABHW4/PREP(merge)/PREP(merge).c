//20190941 ±è°æ¹Î
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
void merge(int a[], int p, int q, int r)
{
	int temp[100];
	int i = p, j = q + 1;
	int t = 0;

	while (i <= q && j <= r)
		if (a[i] <= a[j])
			temp[t++] = a[i++];
		else
			temp[t++] = a[j++];
	
	while (i <= q)
		temp[t++] = a[i++];

	while (j <= r)
		temp[t++] = a[j++];
	i = p;
	t = 0;
	while (i <= r)
		a[i++] = temp[t++];
}
void printList(int a[], int s, int e)
{
	int i;
	for (i = s; i <= e; i++)
		printf("%d ", a[i]);
	printf("\n");
}
int main(void)
{
	int list1[] = {
		10, 20, 30, 70, 80,
		11, 33, 44, 55, 66
	};
	int list2[] = {
		10, 20, 30, 70, 80,
		11, 33, 44, 55, 66
	};

	printList(list1, 0, 9);
	merge(list1, 0, 4, 9);
	printList(list1, 0, 9);

	printList(list2, 2, 7);
	merge(list2, 2, 4, 7);
	printList(list2, 2, 7);
}