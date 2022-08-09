#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
int findKey(char str[], char key)
{
	int rslt = 0, i;
	for (i = 0; i < strlen(str); i++)
		if (str[i] == key)
			rslt++;
	return rslt;
}
int main()
{
	char str[100];
	char key;
	int rslt;

	printf("Enter a String:");
	scanf("%s", str);
	getchar() != '\n';
	printf("Enter a character:");
	scanf("%c", &key);

	printf("'%c' is appeared %d times\n", key, findKey(str, key));
}