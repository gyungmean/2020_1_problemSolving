#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
int check(char s[], char ch)
{
	int i;
	for (i = 0; i < strlen(s); i++)
		if (s[i] == ch) return 1;
	return 0;
}
int main(void)
{
	char s1[20], s2[20];
	char newS1[20];
	int i, j = 0;

	scanf("%s", s1);
	scanf("%s", s2);

	for (i = 0; s1[i] != '\0'; i++) {
		if (!check(s2, s1[i]))
			newS1[j++] = s1[i];
	}
	newS1[j] = '\0';

	for (i = 0; newS1[i] != '\0'; i++)
		s1[i] = newS1[i];
	s1[i] = '\0';
	printf("%s", s1);
}