#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
void input(char* name)
{
	printf("Enter your name: ");
	scanf("%s", name);
}
void reverse(char* name)
{
	int nameSize, i;
	char temp;

	nameSize = strlen(name);

	for (i = 0; i < nameSize / 2; i++) {
		temp = name[i];
		name[i] = name[nameSize - 1 - i];
		name[nameSize - 1 -i] = temp;
	}

	printf("Reverse: %s\n", name);
}
int main()
{
	char name[20];
	input(name);
	reverse(name);
}