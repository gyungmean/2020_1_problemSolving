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

	printf("***로또 번호 생성기***\n");
	do {
		makeNum(num);
		printf("\n생성 번호: ");
		for (i = 0; i < 6; i++)
			printf("%d ", num[i]);
		printf("\n다시 생성하시겠습니까? (y/n)");
		scanf("%c", &proceed);
	} while (proceed != 'n');
}