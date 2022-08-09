//20190941 김경민
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#define BOARD_SIZE 5
void resetBoard(char b[][3])
{
	int i, j;
	for (i = 0; i < BOARD_SIZE; i++)
		for (j = 0; j < BOARD_SIZE; j++)
			b[i][j] = ' ';
}
void display(char b[][3])
{
	int i, j;
	printf("     ");
	for (i = 0; i < BOARD_SIZE; i++)
		printf("%2d", i);
	printf("\n -------------\n");
	for (i = 0; i < BOARD_SIZE; i++) {
		printf("%3d |", i);
		for (j = 0; j < BOARD_SIZE; j++)
			printf(" %c", b[i][j]);
		printf("\n");
	}
}
int winCheck(char b[][3], int r, int c)
{
	int i, j = 0, count = 0;
	char turn = b[r][c];

	//세로체크
	for (i = 0; i < BOARD_SIZE; i++)
		if (b[i][c] == turn)
			count++;
	if (count == 5)
		return 1;
	
	count = 0;
	//가로체크
	for (i = 0; i < BOARD_SIZE; i++)
		if (b[r][i] == turn)
			count++;
	if (count == 5)
		return 1;

	count = 0;
	//대각선체크
	for (i = 0; i < BOARD_SIZE; i++) {
		if (b[i][j] == turn)
			count++;
		j++;
	}
	if (count == 5)
		return 1;

	count = 0;
	j--;
	//역대각선체크
	for (i = 0; i < BOARD_SIZE; i++) {
		if (b[i][j] == turn)
			count++;
		j--;
	}
	if (count == 5)
		return 1;

	return 0;
}
void Play(char b[][3])
{
	int r, c, count = 0;
	char turn = 'X';

	while (1) {
		printf("Player %c(행 열):", turn);
		scanf("%d %d", &r, &c);

		if (b[r][c] != ' ')
			continue;

		b[r][c] = turn;
		count++;

		display(b);

		if (winCheck(b, r, c)) {
			printf("Player %c wins!\n", turn);
			break;
		}
		
		else if (count == BOARD_SIZE * BOARD_SIZE) {
			printf("Nobody wins!\n");
			break;
		}
		
		turn = (turn == 'X' ? 'O' : 'X');
	}
}
int main(void)
{
	char board[BOARD_SIZE][BOARD_SIZE];

	resetBoard(board);

	display(board);

	Play(board);
}