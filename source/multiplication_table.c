#include <stdio.h>

#define ROW 11
#define COL 11

void table(int ch[][COL], int row, int col);
void print_table(int ch[][COL], int row, int col);

int main(void)
{
	int m[ROW][COL];
	table(m, ROW, COL);
	
	printf("------------Multiplication Table-------------\n");
	print_table(m, ROW, COL);
	return 0;
}

void table(int ch[][COL], int row, int col)
{
	for(int r = 1; r < row; r++)
		for(int c = 1; c < col; c++)
			ch[r][c] = r * c;			
}

void print_table(int ch[][COL], int row, int col)
{
	printf("     ");
	for(int i = 1; i < COL; i++)
		printf("%3d|", i);
	printf("\n");
	printf("---------------------------------------------\n");
	for(int r = 1; r < row; r++)
	{
		printf("|%3d|", r);
		for(int c = 1; c < col; c++)
			printf("%3d|", ch[r][c]);
		printf("\n---------------------------------------------");
		printf("\n");
	}
}

