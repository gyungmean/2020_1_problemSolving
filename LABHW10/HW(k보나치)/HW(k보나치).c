//20190941 ����
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
int kbonacci(int n, int k)
{
	int rslt = 0, i;
	if (n <= k)
		return 1;
	else {
		for (i = n - 1; i >= n - k; i--) {
			rslt += kbonacci(i, k);
		}
		return  rslt;
	}

}
int main(void)
{
	int n, k, i;

	printf("k����? ");
	scanf("%d", &k);

	printf("���° �ױ���? ");
	scanf("%d", &n);

	for (i = 1; i <= n; i++)
		printf("%d ", kbonacci(i, k));
	printf("\n");
}