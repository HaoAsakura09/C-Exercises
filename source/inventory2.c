/* Maintains a part database (linked list version) */
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

#define NAME_LEN 25

struct part
{
	int number;
	char name[NAME_LEN + 1];
	int on_hand;
	struct part *next;
};

struct part *inventory = NULL; // Point to first part 

struct part *find_part(int number);
void insert(void);
void search(void);
void update(void);
void print(void);

int read_line(char str[], int n);
int main(void)
{
	char code;
	
	for(;;)
	{
		printf("Enter operation code: ");
		scanf(" %c", &code);
		while(getchar() != '\n') // skips to end of line
			;
		switch(toupper(code))
		{
			case 'I': insert(); break;
			case 'S': search(); break;
			case 'U': update(); break;
			case 'P': print(); break;
			case 'Q': return 0;
			default: printf("Illegal code.\n"); break;
		}
		printf("\n");
	}
	return 0;
}

int read_line(char str[], int n)
{
	int ch, i = 0;
	while(isspace(ch = getchar()))
		;
	while(ch != '\n' && ch != EOF)
	{
		if(i < n)
			str[i++] = ch;
		ch = getchar();
	}
	str[i] = '\0';
	return i;
}

struct part *find_part(int number)
{
	struct part *p;
	
	for(p = inventory;
			p != NULL && number > p -> number;
			p = p -> next)
	;
	
	if(p != NULL && number  == p -> number)
		return p;
	return NULL;		
}

void insert(void)
{
	struct part *cur, *prev, *new_node;
	
	new_node = malloc(sizeof(struct part));
	if(new_node == NULL)
	{
		printf("Database is full; can't add more parts.\n");
		return;
	}
	printf("Enter part number: ");
	scanf("%d", &new_node -> number);
	
	for(cur = inventory, prev = NULL; 
		    cur != NULL && new_node -> number > cur -> number;
		    prev = cur, cur = cur -> next)
    ;
   
   if(cur != NULL && new_node -> number == cur -> number)
   {
   	printf("Already exists.\n");
   	free(new_node);
   	return;
   }
   
   printf("Enter part name: ");
   read_line(new_node -> name, NAME_LEN);
   printf("Enter qunatity on hand: ");
   scanf("%d", &new_node -> on_hand);
   
   new_node -> next = cur;
   if(prev == NULL)
   	inventory = new_node;
   else
   	prev -> next = new_node;
}

void search(void)
{
	int number;
	struct part *p;
	
	printf("Enter part number: ");
	scanf("%d", &number);
	p = find_part(number);
	if(p != NULL)
	{
		printf("Part name: %s\n", p -> name);
		printf("Quantity on hand: %d\n", p -> on_hand);
	}
	else
		printf("Part not found.\n");
}

void update(void)
{
	int number, change;
	struct part *p;
	
	printf("Enter part number: ");
	scanf("%d", &number);
	p = find_part(number);
	
	if(p != NULL)
	{
		printf("Change in quantity on hand: ");
		scanf("%d", &change);
		p -> on_hand += change;
	}
	else
		printf("Part not found.\n");
}

void print(void)
{
	struct part *p;
	
	printf("Part Number     Part Name     Quantity on hand\n");
	for(p = inventory; p != NULL; p = p -> next)
	{
		printf("%7d             %-24s%-10d\n", p -> number, p -> name, p -> on_hand);
	}
}
