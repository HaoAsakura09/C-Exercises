#include <stdbool.h>	// for bool type. 
#include <conio.h>		// clrscr() and getch() 
#include <stdio.h>

// You can change the ROW and COL to get bigger tiles
// That would be boring lol
// because all you have to do is to eat these dots!
#define ROW 10  // Row for my multi array
#define COL 10	// Col for my multi array

void grid(char s[][COL], int size);					// My Map

void print_grid(char s[][COL], int size);		// Prints out multi array
void clear_screen(void);		// Clear console output

// Tracks how many dots left 
int count_dots(char s[][COL], int size);

int main(void)
{
	int x, y, dot_counter;
  // the @ character starts at row 0 and col 0
	 x = y = 0;
	char map[ROW][COL], c;
	bool top, right, left, down;
	
	grid(map, ROW);
	map[x][y] = '@';
	printf("\n===================================================\n");
		printf("Enter 'x' or eat the dots to terminate the program.\n");
		printf("===================================================\n");
	print_grid(map, ROW);
	dot_counter = count_dots(map, ROW);
	printf("Food Left: %d", dot_counter);
	while((c = getch()) != 'x')
	{
    // I assigned false to all directions
		top = right = left = down = false;
		
		// This tracks what character has user input
    // Only one character will be tested after the switch statement
		switch(c)
		{
			case 'w': top = true; break;
			case 'd': right = true; break;
			case 'a': left = true; break;
			case 's': down = true; break;
			default: 
			{
				printf("Invalid input!\n"); 
				continue;
			}
		}
		
    
    // x and y is the current position of @ character
    // I assigned ' ' first, then assigned @ character for new position
	   if(top && x > 0 && x <= (COL - 1))
	   {
	   	map[x--][y] = ' ';
	   	map[x][y] = '@';
	   	printf("You are at %d:%d\n", x, y);
	   }
	   else if(right && y >= 0 && y < (COL - 1))
	   {
	   	map[x][y++] = ' ';
	   	map[x][y] = '@';
	   	printf("You are at %d:%d\n", x, y);
	   }
	   else if(left && y > 0 && y <= (COL - 1))
	   {
	   	map[x][y--] = ' ';
	   	map[x][y] = '@';
	   	printf("You are at %d:%d\n", x, y);
	   }
	   else if(down && x >= 0 && x < (COL - 1))
	   {
	   	map[x++][y] = ' ';
	   	map[x][y] = '@';
	   	printf("You are at %d:%d\n", x, y);
	   }
     

     
	   clear_screen(); // It clears previous output
	   printf("The game started! Enjoy!\n");
	   print_grid(map, ROW);  
    // Counts how many dots left and will be saved to dot counter
	   dot_counter = count_dots(map, ROW);
	   
    // This will cause program termination when no dots are left
	   if(dot_counter == 0)
	   {
	   	printf("Congratulations! You have eaten these annoying dots!\n");
	   	printf("Well done :)\n");
	   	break;
	   }
	   printf("Food left: %d\n", dot_counter);
	}
	return 0;
}

void grid(char s[][COL], int size)
{
	for(int i = 0; i < ROW; i++)
		for(int j = 0; j < COL; j++)
			s[i][j] = '.';
}

void print_grid(char s[][COL], int size)
{
	for(int i = 0; i < ROW; i++)
	{
		for(int j = 0; j < COL; j++)
			printf("%c ", s[i][j]);
		printf("\n");
	}
}

int count_dots(char s[][COL], int size)
{
	int num_dots = 0;

	for(int i = 0; i < ROW; i++)
	{
		for(int j = 0; j < COL; j++)
			if(s[i][j] == '.')
				num_dots++;
	}
	
	return num_dots;
}
void clear_screen(void)
{
	clrscr();
}
