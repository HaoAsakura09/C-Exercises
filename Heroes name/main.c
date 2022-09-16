#include "read_input.h"
#include "words.h"

#include <stdbool.h>
#include <conio.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

bool is_equal(const char *str1, char *str2);

int main(void)
{
	srand((unsigned)time(NULL));
	char ch[10], answer[20], op;
	int word_pos;
	
	printf("Mobile Legends Guessing game for addict.\n");
	for (;;)
	{
		// generate a word from its position
		printf("The new name has been chosen.\n");
		word_pos = rand() % 12;

		for (;;)
		{
			printf("Guess the hero whose name starts with letter %c: ", words[word_pos][0]);
			read_input(ch, 9);
			
			// I did this because pointer gives me headache xD
			strncpy(answer, words[word_pos], sizeof(answer) - 1);
			
			// I created a function named is_equal
			// converts ch and answer to lowercase before comparing
			if (is_equal(ch, answer))
			{
				printf("It's %s! and you are correct!\n", words[word_pos]);
				break;
			}
		}

		printf("Do you want to play again? (Y/N): ");
		scanf(" %c", &op);

		if (toupper(op) == 'N')
		{
			printf("Thank you for playing!\n");
			break;
		}
	}
	return 0;
}

bool is_equal(const char *str1, char *str2)
{
	while (*str1 != '\0')
	{
		if (tolower(*str1++) != tolower(*str2++))
			return false;
	}
	return true;
}
