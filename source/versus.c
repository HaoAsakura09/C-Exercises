#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
	srand((unsigned)time(NULL));
	int player1_point, player2_point;
	
	player1_point = player2_point = 0;
	
	for(;;)
	{
		player1_point += rand() % 4;
		player2_point += rand() % 4;
		
		if(player1_point > 100)
		{
			printf("Player 1 won!\n");
			break;
		}
		else if(player2_point > 100)
		{
			printf("Player 2 won!\n");
			break;
		}
	}
	printf("Player 1 got %d points.\n", player1_point);
	printf("Player 2 got %d points.\n", player2_point);
	return 0;
}
