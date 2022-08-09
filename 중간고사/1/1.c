#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
int main(void)
{
	int i;
	int sum = 0;
	char str[1051];

	scanf("%s", str);
	// 코드 작성
	for (i = 0; i < strlen(str); i++) {
		sum += str[i];
	}
	if (sum % 3 == 0)
		printf("yes");
	else
		printf("no");
}