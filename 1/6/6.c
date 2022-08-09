
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <ctype.h>
#include <string.h>

int is_in(char w[], char ch) // 필요하면 사용한다
{
	int i;
	for (i = 0; w[i] != '\0'; i++)
		if (w[i] == ch)
			return 1;
	return 0;
}

void makeCode(char code[], char word[])
{
	int i, j = 0;
	char ch = 'A';
	for (i = 26 - strlen(word); i < 26; i++) {
		code[i] = word[j++];
	}
	for (i = 0; i < 26 - strlen(word); i++) {
		while (is_in(word, ch)) ch++;
		code[i] = ch++;
	}

}

void printCode(char code[])
{
	int i;
	for (i = 0; i < 26; i++) {
		printf("%c", code[i]);
	}
	printf("\n");
}

void remove_duplicated_char(char* str) {
	int i, j;
	int len;
	int tail = 1;

	if (str == NULL) return;

	len = strlen(str);
	for (i = 1; i < len; i++) {
		for (j = 0; j < tail; ++j) {
			if (str[i] == str[j]) break;
		}
		if (j == tail) { // 같은 것이 없으면
			str[tail] = str[i];
			tail++;
		}
	}
	str[tail] = '\0';
}
void encode(char s[], char c[], char es[])
{
	int i;
	for (i = 0; i < strlen(s); i++) {
		es[i] = c[s[i] - 65];
	}
	es[i] = '\0';
}
int main(void)
{
	char code[26] = { ' ' }; // code[0]부터 'A'의 암호화문자를 넣음
	char word[20];
	char sentence[80];
	char encodedSentence[80];

	scanf("%s", word);
	scanf("%s", sentence);

	remove_duplicated_char(word);
	makeCode(code, word);
	//printCode(code);
	encode(sentence, code, encodedSentence);
	printf("%s\n", encodedSentence);
}