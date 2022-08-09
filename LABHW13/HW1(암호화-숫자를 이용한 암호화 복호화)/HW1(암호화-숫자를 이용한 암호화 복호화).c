//20190941 김경민
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
void makeCode(char code[], int dist)
{
	int i;
	for (i = 0; i < 26; i++)
		if('A' + dist <= 'Z')
			code[i] = 'A' + dist++;
		else
			code[i] = 'A' + dist++ - 26;
}
void printCode(char code[])
{
	int i;
	char alphabet = 'A';
	printf("------------------------------------\n");
	printf("alphabet :\t");
	for (i = 0; i < 26; i++)
		printf("%c", alphabet++);
	printf("\nencoded :\t");
	for (i = 0; i < 26; i++)
		printf("%c", code[i]);
	printf("\n------------------------------------\n");
}
void encode(char code[], char s[], char e[])
{
	int i;
	for (i = 0; s[i] != '\0'; i++) {
		if ('A' <= s[i] && s[i] <= 'Z')
				e[i] = code[s[i] - 65];
		else
			e[i] = s[i];
	}
	e[i] = '\0';
}
void decode(char code[], char e[], char d[])
{
	int i;
	int key = code[0] - 65;
	if(key > 0)
		for (i = 0; i < 26 ; i++) {
			if (code[i] - key >= 'A')
				code[i] -= key;
			else
				code[i] = code[i] - key + 26;
		}
	for (i = 0; e[i] != '\0'; i++) {
		if ('A' <= e[i] && e[i] <= 'Z')
			d[i] = code[e[i] - 65 - key];
		else
			d[i] = e[i];
	}
	d[i] = '\0';
}
int main(void)
{
	char code[26]; // code[0]부터 'A'의 암호화문자를 넣음
	int distance;
	char sentence[80];
	char encodedSentence[80];
	char decodedSentence[80];

	printf("Enter a distance for encoding:");
	scanf("%d", &distance);

	makeCode(code, distance);
	printCode(code);

	while (getchar() != '\n');
	printf("Enter a sentence to encode:");
	fgets(sentence, sizeof(sentence), stdin);

	encode(code, sentence, encodedSentence);
	printf("original sentence:\t");
	puts(sentence);

	printf("encoded sentence:\t");
	puts(encodedSentence);

	decode(code, encodedSentence, decodedSentence);
	printf("decoded sentence:\t");
	puts(decodedSentence);
}