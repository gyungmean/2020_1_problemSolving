//20190941 ±è°æ¹Î
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
void makeCode(char* alphabet, char* code, int distance)
{
	int i;
	for (i = 0; i < 26; i++)
		if(alphabet[i] + distance <= 'Z')
			code[i] = alphabet[i] + distance;
		else
			code[i] = alphabet[i] + distance - 26;
}
void encode(char* sentence, char* encoded, int distance) 
{
	int i;
	for (i = 0; sentence[i] != '\0'; i++) {
		if ('A' <= sentence[i] && sentence[i] <= 'Z') {
			if (sentence[i] + distance <= 'Z')
				encoded[i] = sentence[i] + distance;
			else
				encoded[i] = sentence[i] + distance - 26;
		}
		else
			encoded[i] = sentence[i];
	}
	encoded[i] = '\0';
}
int main()
{
	int distance;
	int i;
	char alphabet[26], code[26];
	char element = 'A';
	char sentence[80], encoded[80];

	for (i = 0; i < 26; i++)//alphabet Ã¤¿ì±â
		alphabet[i] = element++;

	printf("Enter a distance for encoding: ");
	scanf("%d", &distance);

	makeCode(alphabet, code, distance);

	printf("------------------------------------\n");
	printf("alphabet :\t");
	for (i = 0; i < 26; i++)
		printf("%c", alphabet[i]);
	printf("\nencoded :\t");
	for (i = 0; i < 26; i++)
		printf("%c", code[i]);
	printf("\n------------------------------------\n");

	while (getchar() != '\n');
	printf("\nEnter a sentence to encode: ");
	fgets(sentence, sizeof(sentence), stdin);

	encode(sentence, encoded, distance);

	printf("original sentence :\t");
	printf("%s\n", sentence);
	printf("encoded sentence:\t");
	printf("%s\n", encoded);
}