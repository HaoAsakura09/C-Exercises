#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
	srand((unsigned)time(NULL));
	
	bool card_exists[13][4] = { false };
	char *rank[] = {"Ace", "King", "Queen", "Jack",
									"Ten", "Nine", "Eight", "Seven",
									"Six", "Five", "Four", "Three",
									 "Two"};
  char *suit[] = {"clubs", "spades", "diamonds", "hearts"};
  
  
  int num_cards, card_rank, card_suit;
  
  printf("Enter number of cards in hands: ");
  scanf("%d", &num_cards);
  
  while(num_cards > 0)
  {
  	card_rank = rand() % 13;
  	card_suit = rand() % 4;
  	
  	if(card_exists[card_rank][card_suit] == true)
  		continue;
  	else
  	{
  		card_exists[card_rank][card_suit] = true;
  		printf("%s of %s\n", rank[card_rank], suit[card_suit]);
  		num_cards--;
  	}
  }
  
  return 0;
}
