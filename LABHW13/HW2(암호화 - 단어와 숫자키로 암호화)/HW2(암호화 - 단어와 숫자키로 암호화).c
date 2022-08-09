//20190941 김경민
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int check(char* word, int size, char ch)
{
	int i;
	for (i = 0; i < size; i++)
		if (word[i] == ch) return 1;
	return 0;
}
void remove_duplicated_char(char word[])
{
	int i, j = 0;
	char temp[80];
	for (i = 0; word[i] != '\0'; i++)
		if (check(temp, j, word[i]) == 0)
			temp[j++] = word[i];
	temp[j] = '\0';
	strcpy(word, temp);
}
void makeCode(char code[], int distance, char* key) 
{
	int i, j = 0;
	char ch = 'A';
	for (i = distance; key[j] != '\0'; i++) {
		code[i] = key[j++];
	}
	for (i = i; i < 26; i++) {
		while(check(key, strlen(key), ch))
			ch++;
		code[i] = ch++;
	}
	for (i = 0; i < distance; i++) {
		while (check(code, strlen(key), ch))
			ch++;
		code[i] = ch++;
	}
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
int main()
{
	char code[26];//code[0]부터 ‘A'의 암호화 문자 넣음
	int distance;
	char key[30];
	char sentence[80];
	char encodedSentence[80];
	char decodedSentence[80];

	printf("Enter a distance for encoding:");
	scanf("%d", &distance);
	printf("Enter a word to use for encoding:");
	scanf("%s", key);

	remove_duplicated_char(key);
	makeCode(code, distance, key);
	printCode(code);

	while (getchar() != '\n');
	printf("Enter a sentence to encode:");
	fgets(sentence, sizeof(sentence), stdin);

	encode(code, sentence, encodedSentence);
	printf("original sentence:\t");
	puts(sentence);

	printf("encoded sentence:\t");
	puts(encodedSentence);

	/*
	decode(code, encodedSentence, decodedSentence);
	printf("decoded sentence:\t");
	puts(decodedSentence);*/
}