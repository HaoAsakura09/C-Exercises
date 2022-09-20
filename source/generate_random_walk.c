#include <unistd.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROW 10
#define COL 10

void generate_random_walk(char walk[ROW][COL]);
void print_array(char walk[ROW][COL]);

int main(void)
{
	srand((unsigned)time(NULL));

	char walk[ROW][COL];
	generate_random_walk(walk);
	print_array(walk);
	return 0;
}

void generate_random_walk(char walk[ROW][COL])
{
	for (int row = 0; row < ROW; row++)
		for (int col = 0; col < COL; col++)
			walk[row][col] = '.';

	char ch = 'A';
	int move, x, y;
	x = y = 0;
	bool top, left, right, bottom;

	walk[x][y] = ch;
	for (;;)
	{
		top = left = right = bottom = false;
		move = rand() % 4;
		switch (move)
		{
		case 0:
			top = true;
			break;
		case 1:
			left = true;
			break;
		case 2:
			bottom = true;
			break;
		case 3:
			right = true;
			break;
		}

		if (top && x > 0 && (walk[x - 1][y] == '.'))
			walk[--x][y] = ++ch;
		else if (bottom && x >= 0 && x < ROW - 1 && (walk[x + 1][y] == '.'))
			walk[++x][y] = ++ch;
		else if (right && y >= 0 && y < COL - 1 && (walk[x][y + 1] == '.'))
			walk[x][++y] = ++ch;
		else if (left && y > 0 && (walk[x][y - 1] == '.'))
			walk[x][--y] = ++ch;
		// Sometimes infinite loop occurs
		// So I enable these lines to check.
		//	fflush(stdout);
		//	sleep(1);
		//printf("x = %d, y = %d move %d\n", x, y, move);
		if (walk[x - 1][y] != '.' && walk[x + 1][y] != '.' && walk[x][y + 1] != '.' && walk[x][y - 1] != '.')
			break;
		else if (ch == 'Z')
			break;
	}
}

void print_array(char walk[ROW][COL])
{
	for (int row = 0; row < ROW; row++)
	{
		for (int col = 0; col < COL; col++)
			printf(" %c", walk[row][col]);
		printf("\n");
	}
}
