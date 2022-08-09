﻿//20190941 김경민
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#define X_VALUE 5 //2차원 배열의 행의 수
#define Y_VALUE 5 //2차원 배열의 열의 수
void readBombInfo(char grid[][Y_VALUE + 1])
{
	int i;
	// grid 및 지뢰 정보 입력
	printf("Input Grid\n");
	for (i = 0; i < X_VALUE; i++)
		scanf("%s", grid[i]);
}
void countBomb(char grid[][Y_VALUE + 1], int numOfBombs[][Y_VALUE])
{
	int i, j;
	for (i = 0; i < X_VALUE; i++)
		for (j = 0; j < Y_VALUE; j++)
			if (grid[i][j] == '*') {
				// 여기에 지뢰의 개수를 세어 numOfBombs에 넣는 코드 작성
				if (i - 1 >= 0) {
					if (j - 1 >= 0)
						numOfBombs[i - 1][j - 1]++; // 위 왼쪽 대각선
					if (j + 1 < Y_VALUE)
						numOfBombs[i - 1][j + 1]++; // 위 오른쪽 대각선
					numOfBombs[i - 1][j]++; // 위
				}

				if (i + 1 <= Y_VALUE) {
					if (j - 1 >= 0)
						numOfBombs[i + 1][j - 1]++; // 아래 왼쪽 대각선
					if (j + 1 < Y_VALUE)
						numOfBombs[i + 1][j + 1]++; // 아래 오른쪽 대각선
					numOfBombs[i + 1][j]++; // 아래
				}

				if (j - 1 >= 0)
					numOfBombs[i][j - 1]++; // 왼쪽
				if (j + 1 < Y_VALUE)
					numOfBombs[i][j + 1]++; // 오른쪽
			}
}
void display_numOfBombs(char grid[][Y_VALUE + 1], int numOfBombs[][Y_VALUE])
{
	int i, j;
	for (i = 0; i < X_VALUE; i++) {
		for (j = 0; j < Y_VALUE; j++)
			if (grid[i][j] == '*')
				printf("*");
			else
				printf("%d", numOfBombs[i][j]);
		printf("\n");
	}
}
int main(void)
{
	char grid[X_VALUE][Y_VALUE + 1]; //문자열의 경우 마지막에 NULL이 들어가야 하므로
   // 5X5 배열이 아닌 5X6 배열이 되어야 한다.
	int numOfBombs[X_VALUE][Y_VALUE] = { 0 }; //지뢰의 개수를 넣는 정수형 5X5 배열
	readBombInfo(grid);
	countBomb(grid, numOfBombs);
	display_numOfBombs(grid, numOfBombs);
}