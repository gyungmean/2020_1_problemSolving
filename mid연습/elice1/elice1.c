#include <stdio.h>

int main(void)
{
	int score, total = 0;

	scanf("%d", &score);
	while (score != -1) {
		total += score;
		scanf("%d", &score);
	}
	printf("%d", total);
}