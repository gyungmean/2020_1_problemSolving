//20190941 ??????
#include <stdio.h>
void pick(int n, int picked[], int m, int toPick)
{
	int smallest, lastIndex, i;
	if (toPick == 0) {
		for (i = 0; i < m; i++)
			printf("%d ", picked[i]);
		printf("\n");
		return;
	}

	lastIndex = m - toPick - 1;

	if (m == toPick)
		smallest = 0;
	else
		smallest = picked[lastIndex] + 1;

	for (i = smallest; i < n; i++) {
		picked[lastIndex + 1] = i;
		pick(7, picked, m, toPick - 1);
	}
}
int main()
{
	int picked[5];
	pick(7, picked, 5, 5);
}