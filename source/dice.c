#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int roll_dice(void);
bool play_game(void);

int main(void)
{
	srand((unsigned)time(NULL));
	
	char play = 'Y';
	int win_count = 0, lose_count = 0;;
	
	while(toupper(play) != 'N')
	{
		if(play_game())
		{
			printf("You win!\n");
			win_count++;
		}
		else
		{
			printf("You lose!\n");
			lose_count++;
		}
			
		printf("\nPlay again? ");
		scanf(" %c", &play);
		printf("\n");
	}
	
	printf("\nWins: %d\tLosses: %d\n", win_count, lose_count);
	return 0;
}

int roll_dice(void)
{
	return rand() % 6 + 1;
}

bool play_game(void)
{
	int roll1, roll2, point;
	bool first_roll = false;
	
	for(;;)
	{
		roll1 = roll_dice();
		roll2 = roll_dice();
	
	   point = roll1 + roll2;
		printf("You rolled: %d\n", point);
		if(first_roll == false)
		{
			if(point == 7 || point == 11)
				return true;
			printf("Your point is %d\n", point);
			first_roll = true;
		}
		
		if(point == 2 || point == 3 || point == 12)
			return false;
		else if(point == 7 || point == 11)
			return true;		
	}
}
