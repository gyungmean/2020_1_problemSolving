#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void makeNum(int n[])
{
	int i;
	for (i = 0; i < 6; i++)
		n[i] = rand() % 45 + 1;
}
int main()
{
	char proceed;
	int num[6];
	int i;
	srand(time(NULL));

	printf("***�ζ� ��ȣ ������***\n");
	do {
		makeNum(num);
		printf("\n���� ��ȣ: ");
		for (i = 0; i < 6; i++)
			printf("%d ", num[i]);
		printf("\n�ٽ� �����Ͻðڽ��ϱ�? (y/n)");
		scanf("%c", &proceed);
	} while (proceed != 'n');
}