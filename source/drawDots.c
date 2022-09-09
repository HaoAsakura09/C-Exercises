#include <stdbool.h>
#include <ctype.h>
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROW 20
#define COL 20

void clear_screen(void);
void tiles(char a[ROW][COL], int size);
void print_map(char a[ROW][COL], int size);

//  W A  S  D
char keys(void);

int main(void)
{
	bool top, right, left, bottom, hit = false;
	char map[ROW][COL], c, p = '@';
	tiles(map, ROW);
	int x, y;
	x = y = 1;
	
	map[x][y] = p;
	for(;;)
	{
		top = right = left = bottom = false;
		
  	print_map(map, ROW);
		c = keys();
		if(c == 'X') break;
		switch(c)
		{
			case 'W': top = true; break;
			case 'D': right = true; break;
			case 'A': left = true; break;
			case 'S': bottom = true; break;
		}
		
		if(top && x >=0 && x <= ROW - 1 && y > 0 && y <= ROW - 1)
		{
			map[x--][y] = '.';
			if(map[x][y] == '#') hit = true;
			map[x][y] = p;
		}
		else if(bottom && x >= 0 && x <= ROW - 1 && y >= 0 && y <= ROW - 1)
		{
			map[x++][y] = '.';
			if(map[x][y] == '#') hit = true;
			map[x][y] = p;
		}
		else if(right && y >= 0 && y <= COL - 1)
		{
			map[x][y++] = '.';
			if(map[x][y] == '#') hit = true;
			map[x][y] = p;
		}
		else if(left && y >= 0 && y <= COL - 1)
	   {
	   	map[x][y--] = '.';
	   	if(map[x][y] == '#')
	   	 	hit = true;
	   	map[x][y] = p;
	   }
	   
	
		clear_screen();
		if(hit)
		{
			printf("You hit the wall!\n");
			printf("Game Over.\n");
			printf("Do you want to play again? y/n: ");
			switch(toupper(getch()))
			{
				case 'Y':
								{
								// back the character to the original position
									map[x][y] = '#';
									x = y = 1;
									hit = false;
									printf("\n");
									// back to the original map
									tiles(map, ROW);
									// position of char
									map[x][y] = p;
								} break;
			    case 'N': return 0;
			}
			printf("\n");	
		}					
	}
	
	return 0;
}


char keys(void)
{
	switch(toupper(getch()))
	{
		case 'W': return 'W'; 
		case 'S': return 'S';
		case 'D': return 'D';
		case 'A': return 'A';
		case 'X': return 'X';
	}
}

void print_map(char a[ROW][COL], int size)
{
	for(int row = 0; row < ROW; row++)
	{
		for(int col = 0; col < COL; col++)
			printf("%c ", a[row][col]);
		printf("\n");
	}
}

void tiles(char a[ROW][COL], int size)
{
	for(int row = 0; row < ROW; row++)
	{
		for(int col = 0; col < COL; col++)
		{
			a[row][col] = ' ';
			
			// Left tiles
			if(row < ROW)
				a[row][0] = '#';
				
			// Top tiles
			 if(row == 0)
				a[row][col] = '#';
		   
		   // Bottom tiles		
			if(row == ROW - 1)
				a[row][col] = '#';
				
			// Right tiles
			if(col == COL - 1)
				a[row][col] = '#';
		}
	}
}

void clear_screen(void)
{
	clrscr();
}

