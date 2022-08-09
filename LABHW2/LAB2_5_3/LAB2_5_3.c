//20190941 ����
#define _CRT_SECURE_NO_WARNINGS
#define WIDTH 10
#define HEIGHT 10
#include <stdio.h>
int screen[WIDTH][HEIGHT] = {
0, 0, 0,-1,-1,-1,-1,-1,-1,-1,
-1,-1, 0,-1,-1,-1,-1,-1,-1,-1,
-1, 0, 0, 0, 0, 0, 0,-1,-1,-1,
-1,-1,-1,-1, 0,-1, 0,-1,-1,-1,
-1,-1,-1,-1, 0,-1, 0,-1,-1,-1,
-1,-1, 0, 0, 0,-1, 0, 0, 0,-1,
-1,-1,-1,-1, 0,-1, 0,-1,-1,-1,
-1,-1,-1,-1, 0,-1, 0,-1, 0,-1,
-1,-1,-1,-1, 0,-1,-1,-1, 0,-1,
-1,-1,-1,-1, 0, 0, 0, 0, 0, 0
};
void flood_fill(int x, int y)
{
	static int num = 1;
	if (screen[x][y] == 0)
	{
		screen[x][y] = num++;
		if(y + 1 < WIDTH)
			flood_fill(x, y + 1); // ��ȯ ȣ��
		if(x + 1 < HEIGHT)
			flood_fill(x + 1, y); // ��ȯ ȣ��
		if (y - 1 >= 0)
			flood_fill(x, y - 1); // ��ȯ ȣ��
		if (x - 1 >= 0)
			flood_fill(x - 1, y); // ��ȯ ȣ��
	}
}
int main()
{
	int i, j;
	flood_fill(0, 0);
	for (i = 0; i < WIDTH; i++) {
		for (j = 0; j < HEIGHT; j++)
			printf("\t%d", screen[i][j]);
		printf("\n");
	}
}