#include <conio.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ROW 10
#define MAX_COL 10

void clear(void);
void print_grid(char s[MAX_ROW][MAX_COL], int size);
void grid(char s[MAX_ROW][MAX_COL], int size);
// Direction to move
int generate_move(void);
void seed(void);

int main(void)
{
	seed();
	
	char grid_arr[MAX_ROW][MAX_COL];
	grid(grid_arr, MAX_ROW);
	
	char c = 'A';
	
	// Starting index
	int x, y;
	x = y = 0;
	
	int move_direction;
	
	bool up, down, right, left;
  
  grid_arr[x][y] = c;
	for(;;)
	{
		up = down = right = left = false;
		// gets direction to move
		move_direction = generate_move();
		
		printf("\n%d\n", move_direction);
		switch(move_direction)
		{
			case 0: up = true;			break;
			case 1: down = true;	break;
			case 2: right = true;	  break;
			case 3: left = true;		 break;
		}
		
		// Check if it's not out of bound
		// Then check if it doesn't contain letter
		if(up && x > 0 && x < MAX_ROW)
		{
			x--;
			if(grid_arr[x][y] == '.')
			{
				grid_arr[x][y] = ++c;
			}
			else
				x++;
		}
		else if(down && x >= 0 && x < (MAX_ROW - 1))
		{
			x++;
			if(grid_arr[x][y] == '.')
			{
				grid_arr[x][y] = ++c;
			}
			else
				x--;
		}
		else if(right &&  y >= 0 && y < (MAX_COL - 1))
		{
			y++;
			if(grid_arr[x][y] == '.')
			{
				grid_arr[x][y] = ++c;
			}
			else
				y--;
		}
		else if(left && y > 0 && y <= (MAX_COL - 1))
		{
			y--;
			if(grid_arr[x][y] == '.')
			{
				grid_arr[x][y] = ++c;
			}
			else
				y++;
		}
		
		printf("Current loc: x = %d: y = %d\n", x, y);
		clear();
		print_grid(grid_arr, MAX_ROW);
		
		//Check if all direction are blocked
		// then terminate the program
		if(x >= 0 &&  x < MAX_ROW && y >= 0 && y <MAX_ROW)		   {
			if((grid_arr[x - 1][y] != '.' ) && (grid_arr[x + 1][y] != '.') &&
				 (grid_arr[x][y - 1] != '.') && (grid_arr[x][y + 1]) != '.')
				break;
		}
		
		if(c == 'Z')
			break;
	}
	
	return 0;
}

void seed(void)
{
	srand((unsigned)time(NULL));
}

int generate_move(void)
{
	// Possible value 0, 1, 2 and 3
	return rand() % 4;
}

void grid(char s[MAX_ROW][MAX_COL], int size)
{
	for(int row = 0; row < MAX_ROW; row++)
		for(int col = 0; col < MAX_COL; col++)
			s[row][col] = '.';
}

void print_grid(char s[MAX_ROW][MAX_COL], int size)
{
	for(int row = 0; row < MAX_ROW; row++)
	{
		for(int col = 0; col < MAX_COL; col++)
			printf("%c ", s[row][col]);
		printf("\n");
	}
}
void clear(void)
{
	clrscr();
}
