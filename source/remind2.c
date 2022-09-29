/* Prints a one-month reminder list (dynamic string version) */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_REMIND 50 // Maximum reminders
#define MSG_LEN 60			// Maximum length of message

int read_line(char str[], int n);

int main(void)
{
	char *reminder[MAX_REMIND];
	char day_str[3], msg[MSG_LEN + 1];
	int day, i, j, num_remind = 0;
	
	for(;;)
	{
		if(num_remind == MAX_REMIND)
		{
			printf("-- No space left --");
			break;
		}
		
			printf("Enter day and reminder: ");
			scanf("%2d", &day);
			
			if(day == 0)
				break;
			
			sprintf(day_str, "%2d", day);
			read_line(msg, MSG_LEN);
			
			for(i = 0; i < num_remind; i++)
				if(strcmp(day_str, reminder[i]) < 0)
					break;
			
			for(j = num_remind; j > i; j--)
				reminder[j] = reminder[j - 1];
				
			reminder[i] = malloc(2 + strlen(msg) + 1);
			if(reminder[i] == NULL)
			{
				printf("-- No spaces left --\n");
				break;
			}
			strcpy(reminder[i], day_str);
			strcat(reminder[i], msg);
	}
	return 0;
}

int read_line(char str[], int n)
{
	int ch, i = 0;
	
	while((ch = getchar()) != '\n')
		if(i < n)
			str[i++] = ch;
	str[i] = '\0';
	return i;
}
