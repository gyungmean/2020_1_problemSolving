//20190941 ±è°æ¹Î
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
int checkPalindrome(char* s, int size)
{
	int i;
	for (i = 0; i < size; i++) {
		if (s[i] != s[size - 1 - i]) return 0;
	}
	return 1;
}
int findPalindrome(char* s, int index)
{
	char temp[80];
	int i = 0, pIndex = index;
	while (index >= 0) {
		temp[i++] = s[index--];
		if (checkPalindrome(temp, i)) pIndex = index + 1;
	}

	return pIndex;
}
int main(void)
{
	char s[80];
	int size;
	int notPalin;

	scanf("%s", s);
	size = strlen(s);

	notPalin = findPalindrome(s, size - 1) - 1;
	while (notPalin >= 0) {
		s[size++] = s[notPalin--];
	}
	s[size] = '\0';

	printf("%s\n", s);
}