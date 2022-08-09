//20190941 김경민
#define _CRT_SECURE_NO_WARNINGS
#define WIDTH 10
#define HEIGHT 10
#include <stdio.h>
int screen[WIDTH][HEIGHT] = {
-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,
-1,-1, 0, 0,-1,-1,-1, 0,-1,-1,
-1,-1,-1, 0, 0, 0, 0, 0,-1,-1,
-1,-1,-1, 0,-1,-1,-1,-1,-1,-1,
-1,-1,-1, 0, 0, 0, 0, 0,-1,-1,
-1,-1,-1, 0,-1, 0,-1,-1,-1,-1,
-1,-1,-1, 0,-1, 0,-1,-1,-1,-1,
-1,-1,-1, 0,-1, 0, 0, 0,-1,-1,
-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,
-1,-1,-1,-1,-1,-1,-1,-1,-1,-1
};
void flood_fill(int x, int y)
{
	static int num = 1;
	if (screen[x][y] == 0)
	{
		screen[x][y] = num++;
		flood_fill(x, y + 1); // 순환 호출
		flood_fill(x + 1, y); // 순환 호출
		flood_fill(x, y - 1); // 순환 호출
		flood_fill(x - 1, y); // 순환 호출
	}
}
int main()
{
	int i, j;
	flood_fill(4, 3);
	for (i = 0; i < WIDTH; i++) {
		for (j = 0; j < HEIGHT; j++)
			printf("\t%d", screen[i][j]);
		printf("\n");
	}
}